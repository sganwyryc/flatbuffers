package main

import (
	example "MyGame/Example" // refers to generated code
	"bytes"
	"flag"
	"fmt"
	flatbuffers "github.com/google/flatbuffers/go"
	"io/ioutil"
	"os"
	"reflect"
	"sort"
	"testing"
)

var (
	cppData, javaData, outData string
	fuzz, superFuzz            bool
	fuzzFields, fuzzObjects    int
)

func init() {
	flag.StringVar(&cppData, "cpp_data", "",
		"location of monsterdata_test.bin")
	flag.StringVar(&javaData, "java_data", "",
		"location of monsterdata_java_wire.bin")
	flag.StringVar(&outData, "out_data", "",
		"location to write generated Go data")
	flag.BoolVar(&fuzz, "fuzz", false, "perform fuzzing")
	flag.BoolVar(&superFuzz, "super_fuzz", false,
		"perform fuzzing of 0..fuzz_fields fields")
	flag.IntVar(&fuzzFields, "fuzz_fields", 4, "fields per fuzzer object")
	flag.IntVar(&fuzzObjects, "fuzz_objects", 10000,
		"number of fuzzer objects (higher is slower and more thorough")
	flag.Parse()
	if cppData == "" {
		fmt.Fprintf(os.Stderr, "cpp_data argument is required\n")
		os.Exit(1)
	}
	if javaData == "" {
		fmt.Fprintf(os.Stderr, "java_data argument is required\n")
		os.Exit(1)
	}
}

// Store specific byte patterns in these variables for the fuzzer.
var (
	overflowingInt32Val = flatbuffers.GetInt32([]byte{0x83, 0x33, 0x33, 0x33})
	overflowingInt64Val = flatbuffers.GetInt64([]byte{0x84, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44})
)

// TestAll runs all checks, failing if any errors occur.
func TestAll(t *testing.T) {
	monsterDataCpp, err := ioutil.ReadFile(cppData)
	if err != nil {
		t.Fatal(err)
	}

	monsterDataJava, err := ioutil.ReadFile(javaData)
	if err != nil {
		t.Fatalf("run the java test once to generate javaData\n%s", err)
	}

    // FIXME: this test is brittle and not maintainable when the test schema changes
	CheckByteLayout(t.Fatalf)

	manual, off0 := CheckManualBuild(t.Fatalf)
	helped, off1 := CheckGeneratedBuild(t.Fatalf)

	CheckEquality(manual[off0:], monsterDataJava, "manually", t.Fatalf)
	CheckEquality(helped[off1:], monsterDataJava, "helper", t.Fatalf)
	CheckVtableDeduplication(t.Fatalf)

	CheckInterpretBuffer(monsterDataCpp, 0, t.Fatalf)
	CheckInterpretBuffer(monsterDataJava, 0, t.Fatalf)

	CheckDocExample(manual, off0, t.Fatalf)

	if superFuzz {
		for i := 0; i <= fuzzFields; i++ {
			checkFuzz(i, fuzzObjects, t.Fatalf)
		}
	} else if fuzz {
		checkFuzz(fuzzFields, fuzzObjects, t.Fatalf)
	}

	err = ioutil.WriteFile(outData, helped[off1:], os.FileMode(0644))
	if err != nil {
		t.Fatal(err)
	}
}

// CheckInterpretBuffer checks that the given buffer is evaluated correctly
// as the example Monster.
func CheckInterpretBuffer(buf []byte, offset flatbuffers.UOffsetT, fail func(string, ...interface{})) {
	monster := example.GetRootAsMonster(buf, offset)

	if got := monster.Hp(); 80 != got {
		fail(FailString("hp", 80, got))
	}

	// default
	if got := monster.Mana(); 150 != got {
		fail(FailString("mana", 150, got))
	}

	if got := monster.Name(); "MyMonster" != got {
		fail(FailString("name", "MyMonster", got))
	}

	// initialize a Vec3 from Pos()
	vec := new(example.Vec3)
	vec = monster.Pos(vec)
	if vec == nil {
		fail("vec3 initialization failed")
	}

	// check that new allocs equal given ones:
	vec2 := monster.Pos(nil)
	if !reflect.DeepEqual(vec, vec2) {
		fail("fresh allocation failed")
	}

	// verify the properties of the Vec3
	if got := vec.X(); float32(1.0) != got {
		fail(FailString("Pos.X", float32(1.0), got))
	}

	if got := vec.Y(); float32(2.0) != got {
		fail(FailString("Pos.Y", float32(2.0), got))
	}

	if got := vec.Z(); float32(3.0) != got {
		fail(FailString("Pos.Z", float32(3.0), got))
	}

	if got := vec.Test1(); float64(3.0) != got {
		fail(FailString("Pos.Test1", float64(3.0), got))
	}

	if got := vec.Test2(); int8(4) != got {
		fail(FailString("Pos.Test2", int8(4), got))
	}

	// initialize a Test from Test3(...)
	t := new(example.Test)
	t = vec.Test3(t)
	if t == nil {
		fail("vec.Test3(&t) failed")
	}

	// check that new allocs equal given ones:
	t2 := vec.Test3(nil)
	if !reflect.DeepEqual(t, t2) {
		fail("fresh allocation failed")
	}

	// verify the properties of the Test
	if got := t.A(); int16(5) != got {
		fail(FailString("t.A()", int16(5), got))
	}

	if got := t.B(); int8(6) != got {
		fail(FailString("t.B()", int8(6), got))
	}

	if got := monster.TestType(); example.AnyMonster != got {
		fail(FailString("monster.TestType()", example.AnyMonster, got))
	}

	if unionType := monster.TestType(); unionType != example.AnyMonster {
		fail("monster.TestType()")
	}

	// initialize a Table from a union field Test(...)
	var table2 flatbuffers.Table
	if ok := monster.Test(&table2); !ok {
		fail("monster.Test(&monster2) failed")
	}

	// initialize a Monster from the Table from the union
	var monster2 example.Monster
	monster2.Init(table2.Bytes, table2.Pos)

	if got := monster2.Hp(); int16(20) != got {
		fail(FailString("monster2.Hp()", int16(20), got))
	}

	if got := monster.InventoryLength(); 5 != got {
		fail(FailString("monster.InventoryLength", 5, got))
	}

	invsum := 0
	l := monster.InventoryLength()
	for i := 0; i < l; i++ {
		v := monster.Inventory(i)
		invsum += int(v)
	}
	if invsum != 10 {
		fail(FailString("monster inventory sum", 10, invsum))
	}

	if got := monster.Test4Length(); 2 != got {
		fail(FailString("monster.Test4Length()", 2, got))
	}

	var test0 example.Test
	ok := monster.Test4(&test0, 0)
	if !ok {
		fail(FailString("monster.Test4(&test0, 0)", true, ok))
	}

	var test1 example.Test
	ok = monster.Test4(&test1, 1)
	if !ok {
		fail(FailString("monster.Test4(&test1, 1)", true, ok))
	}

	// the position of test0 and test1 are swapped in monsterdata_java_wire
	// and monsterdata_test_wire, so ignore ordering
	v0 := test0.A()
	v1 := test0.B()
	v2 := test1.A()
	v3 := test1.B()
	sum := int(v0) + int(v1) + int(v2) + int(v3)

	if 100 != sum {
		fail(FailString("test0 and test1 sum", 100, sum))
	}
}

// Low level stress/fuzz test: serialize/deserialize a variety of
// different kinds of data in different combinations
func checkFuzz(fuzzFields, fuzzObjects int, fail func(string, ...interface{})) {

	// Values we're testing against: chosen to ensure no bits get chopped
	// off anywhere, and also be different from eachother.
	boolVal := true
	int8Val := int8(-127) // 0x81
	uint8Val := uint8(0xFF)
	int16Val := int16(-32222) // 0x8222
	uint16Val := uint16(0xFEEE)
	int32Val := int32(overflowingInt32Val)
	uint32Val := uint32(0xFDDDDDDD)
	int64Val := int64(overflowingInt64Val)
	uint64Val := uint64(0xFCCCCCCCCCCCCCCC)
	float32Val := float32(3.14159)
	float64Val := float64(3.14159265359)

	testValuesMax := 11 // hardcoded to the number of scalar types

	builder := flatbuffers.NewBuilder(0)
	l := NewLCG()

	objects := make([]flatbuffers.UOffsetT, fuzzObjects)

	// Generate fuzzObjects random objects each consisting of
	// fuzzFields fields, each of a random type.
	for i := 0; i < fuzzObjects; i++ {
		builder.StartObject(fuzzFields)

		for f := 0; f < fuzzFields; f++ {
			choice := l.Next() % uint32(testValuesMax)
			switch choice {
			case 0:
				builder.PrependBoolSlot(int(f), boolVal, false)
			case 1:
				builder.PrependInt8Slot(int(f), int8Val, 0)
			case 2:
				builder.PrependUint8Slot(int(f), uint8Val, 0)
			case 3:
				builder.PrependInt16Slot(int(f), int16Val, 0)
			case 4:
				builder.PrependUint16Slot(int(f), uint16Val, 0)
			case 5:
				builder.PrependInt32Slot(int(f), int32Val, 0)
			case 6:
				builder.PrependUint32Slot(int(f), uint32Val, 0)
			case 7:
				builder.PrependInt64Slot(int(f), int64Val, 0)
			case 8:
				builder.PrependUint64Slot(int(f), uint64Val, 0)
			case 9:
				builder.PrependFloat32Slot(int(f), float32Val, 0)
			case 10:
				builder.PrependFloat64Slot(int(f), float64Val, 0)
			}
		}

		off := builder.EndObject()

		// store the offset from the end of the builder buffer,
		// since it will keep growing:
		objects[i] = off
	}

	// Do some bookkeeping to generate stats on fuzzes:
	stats := map[string]int{}
	check := func(desc string, want, got interface{}) {
		stats[desc]++
		if want != got {
			fail("%s want %v got %v", desc, want, got)
		}
	}

	l = NewLCG() // Reset.

	// Test that all objects we generated are readable and return the
	// expected values. We generate random objects in the same order
	// so this is deterministic.
	for i := 0; i < fuzzObjects; i++ {

		table := &flatbuffers.Table{
			Bytes: builder.Bytes,
			Pos:   flatbuffers.UOffsetT(len(builder.Bytes)) - objects[i],
		}

		for j := 0; j < fuzzFields; j++ {
			f := flatbuffers.VOffsetT((flatbuffers.VtableMetadataFields + j) * flatbuffers.SizeVOffsetT)
			choice := int(l.Next()) % testValuesMax

			switch choice {
			case 0:
				check("bool", boolVal, table.GetBoolSlot(f, false))
			case 1:
				check("int8", int8Val, table.GetInt8Slot(f, 0))
			case 2:
				check("uint8", uint8Val, table.GetUint8Slot(f, 0))
			case 3:
				check("int16", int16Val, table.GetInt16Slot(f, 0))
			case 4:
				check("uint16", uint16Val, table.GetUint16Slot(f, 0))
			case 5:
				check("int32", int32Val, table.GetInt32Slot(f, 0))
			case 6:
				check("uint32", uint32Val, table.GetUint32Slot(f, 0))
			case 7:
				check("int64", int64Val, table.GetInt64Slot(f, 0))
			case 8:
				check("uint64", uint64Val, table.GetUint64Slot(f, 0))
			case 9:
				check("float32", float32Val, table.GetFloat32Slot(f, 0))
			case 10:
				check("float64", float64Val, table.GetFloat64Slot(f, 0))
			}
		}
	}

	// If enough checks were made, verify that all scalar types were used:
	if fuzzFields*fuzzObjects >= testValuesMax {
		if len(stats) != testValuesMax {
			fail("fuzzing failed to test all scalar types")
		}
	}

	// Print some counts, if needed:
	if testing.Verbose() {
		if fuzzFields == 0 || fuzzObjects == 0 {
			fmt.Printf("fuzz\tfields: %d\tobjects: %d\t[none]\t%d\n",
				fuzzFields, fuzzObjects, 0)
		} else {
			keys := make([]string, 0, len(stats))
			for k := range stats {
				keys = append(keys, k)
			}
			sort.Strings(keys)
			for _, k := range keys {
				fmt.Printf("fuzz\tfields: %d\tobjects: %d\t%s\t%d\n",
					fuzzFields, fuzzObjects, k, stats[k])
			}
		}
	}

	return
}

// FailString makes a message for when expectations differ from reality.
func FailString(name string, want, got interface{}) string {
	return fmt.Sprintf("bad %s: want %#v got %#v", name, want, got)
}

// CheckByteLayout verifies the bytes of a Builder in various scenarios.
func CheckByteLayout(fail func(string, ...interface{})) {
	var b *flatbuffers.Builder

	var i int
	check := func(want []byte) {
		i++
		got := b.Bytes[b.Head():]
		if !bytes.Equal(want, got) {
			fail("case %d: want\n%v\nbut got\n%v\n", i, want, got)
		}
	}

	// test 1: numbers

	b = flatbuffers.NewBuilder(0)
	check([]byte{})
	b.PrependBool(true)
	check([]byte{1})
	b.PrependInt8(-127)
	check([]byte{129, 1})
	b.PrependUint8(255)
	check([]byte{255, 129, 1})
	b.PrependInt16(-32222)
	check([]byte{0x22, 0x82, 0, 255, 129, 1}) // first pad
	b.PrependUint16(0xFEEE)
	check([]byte{0xEE, 0xFE, 0x22, 0x82, 0, 255, 129, 1}) // no pad this time
	b.PrependInt32(-53687092)
	check([]byte{204, 204, 204, 252, 0xEE, 0xFE, 0x22, 0x82, 0, 255, 129, 1})
	b.PrependUint32(0x98765432)
	check([]byte{0x32, 0x54, 0x76, 0x98, 204, 204, 204, 252, 0xEE, 0xFE, 0x22, 0x82, 0, 255, 129, 1})

	// test 1b: numbers 2

	b = flatbuffers.NewBuilder(0)
	b.PrependUint64(0x1122334455667788)
	check([]byte{0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11})

	// test 2: 1xbyte vector

	b = flatbuffers.NewBuilder(0)
	check([]byte{})
	b.StartVector(flatbuffers.SizeByte, 1)
	check([]byte{0, 0, 0}) // align to 4bytes
	b.PrependByte(1)
	check([]byte{1, 0, 0, 0})
	b.EndVector(1)
	check([]byte{1, 0, 0, 0, 1, 0, 0, 0}) // padding

	// test 3: 2xbyte vector

	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeByte, 2)
	check([]byte{0, 0}) // align to 4bytes
	b.PrependByte(1)
	check([]byte{1, 0, 0})
	b.PrependByte(2)
	check([]byte{2, 1, 0, 0})
	b.EndVector(2)
	check([]byte{2, 0, 0, 0, 2, 1, 0, 0}) // padding

	// test 4: 1xuint16 vector

	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeUint16, 1)
	check([]byte{0, 0}) // align to 4bytes
	b.PrependUint16(1)
	check([]byte{1, 0, 0, 0})
	b.EndVector(1)
	check([]byte{1, 0, 0, 0, 1, 0, 0, 0}) // padding

	// test 5: 2xuint16 vector

	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeUint16, 2)
	check([]byte{}) // align to 4bytes
	b.PrependUint16(0xABCD)
	check([]byte{0xCD, 0xAB})
	b.PrependUint16(0xDCBA)
	check([]byte{0xBA, 0xDC, 0xCD, 0xAB})
	b.EndVector(2)
	check([]byte{2, 0, 0, 0, 0xBA, 0xDC, 0xCD, 0xAB})

	// test 6: CreateString

	b = flatbuffers.NewBuilder(0)
	b.CreateString("foo")
	check([]byte{3, 0, 0, 0, 'f', 'o', 'o', 0}) // 0-terminated, no pad
	b.CreateString("moop")
	check([]byte{4, 0, 0, 0, 'm', 'o', 'o', 'p', 0, 0, 0, 0, // 0-terminated, 3-byte pad
		3, 0, 0, 0, 'f', 'o', 'o', 0})

	// test 7: empty vtable
	b = flatbuffers.NewBuilder(0)
	b.StartObject(0)
	check([]byte{})
	b.EndObject()
	check([]byte{4, 0, 4, 0, 4, 0, 0, 0})

	// test 8: vtable with one true bool
	b = flatbuffers.NewBuilder(0)
	check([]byte{})
	b.StartObject(1)
	check([]byte{})
	b.PrependBoolSlot(0, true, false)
	b.EndObject()
	check([]byte{
		6, 0, // vtable bytes
		8, 0, // length of object including vtable offset
		7, 0, // start of bool value
		6, 0, 0, 0, // offset for start of vtable (int32)
		0, 0, 0, // padded to 4 bytes
		1, // bool value
	})

	// test 9: vtable with one default bool
	b = flatbuffers.NewBuilder(0)
	check([]byte{})
	b.StartObject(1)
	check([]byte{})
	b.PrependBoolSlot(0, false, false)
	b.EndObject()
	check([]byte{
		6, 0, // vtable bytes
		4, 0, // end of object from here
		0, 0, // entry 1 is zero
		6, 0, 0, 0, // offset for start of vtable (int32)
	})

	// test 10: vtable with one int16
	b = flatbuffers.NewBuilder(0)
	b.StartObject(1)
	b.PrependInt16Slot(0, 0x789A, 0)
	b.EndObject()
	check([]byte{
		6, 0, // vtable bytes
		8, 0, // end of object from here
		6, 0, // offset to value
		6, 0, 0, 0, // offset for start of vtable (int32)
		0, 0, // padding to 4 bytes
		0x9A, 0x78,
	})

	// test 11: vtable with two int16
	b = flatbuffers.NewBuilder(0)
	b.StartObject(2)
	b.PrependInt16Slot(0, 0x3456, 0)
	b.PrependInt16Slot(1, 0x789A, 0)
	b.EndObject()
	check([]byte{
		8, 0, // vtable bytes
		8, 0, // end of object from here
		6, 0, // offset to value 0
		4, 0, // offset to value 1
		8, 0, 0, 0, // offset for start of vtable (int32)
		0x9A, 0x78, // value 1
		0x56, 0x34, // value 0
	})

	// test 12: vtable with int16 and bool
	b = flatbuffers.NewBuilder(0)
	b.StartObject(2)
	b.PrependInt16Slot(0, 0x3456, 0)
	b.PrependBoolSlot(1, true, false)
	b.EndObject()
	check([]byte{
		8, 0, // vtable bytes
		8, 0, // end of object from here
		6, 0, // offset to value 0
		5, 0, // offset to value 1
		8, 0, 0, 0, // offset for start of vtable (int32)
		0,          // padding
		1,          // value 1
		0x56, 0x34, // value 0
	})

	// test 12: vtable with empty vector
	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeByte, 0)
	vecend := b.EndVector(0)
	b.StartObject(1)
	b.PrependUOffsetTSlot(0, vecend, 0)
	b.EndObject()
	check([]byte{
		6, 0, // vtable bytes
		8, 0,
		4, 0, // offset to vector offset
		6, 0, 0, 0, // offset for start of vtable (int32)
		4, 0, 0, 0,
		0, 0, 0, 0, // length of vector (not in struct)
	})

	// test 12b: vtable with empty vector of byte and some scalars
	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeByte, 0)
	vecend = b.EndVector(0)
	b.StartObject(2)
	b.PrependInt16Slot(0, 55, 0)
	b.PrependUOffsetTSlot(1, vecend, 0)
	b.EndObject()
	check([]byte{
		8, 0, // vtable bytes
		12, 0,
		10, 0, // offset to value 0
		4, 0, // offset to vector offset
		8, 0, 0, 0, // vtable loc
		8, 0, 0, 0, // value 1
		0, 0, 55, 0, // value 0

		0, 0, 0, 0, // length of vector (not in struct)
	})

	// test 13: vtable with 1 int16 and 2-vector of int16
	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeInt16, 2)
	b.PrependInt16(0x1234)
	b.PrependInt16(0x5678)
	vecend = b.EndVector(2)
	b.StartObject(2)
	b.PrependUOffsetTSlot(1, vecend, 0)
	b.PrependInt16Slot(0, 55, 0)
	b.EndObject()
	check([]byte{
		8, 0, // vtable bytes
		12, 0, // length of object
		6, 0, // start of value 0 from end of vtable
		8, 0, // start of value 1 from end of buffer
		8, 0, 0, 0, // offset for start of vtable (int32)
		0, 0, // padding
		55, 0, // value 0
		4, 0, 0, 0, // vector position from here
		2, 0, 0, 0, // length of vector (uint32)
		0x78, 0x56, // vector value 1
		0x34, 0x12, // vector value 0
	})

	// test 14: vtable with 1 struct of 1 int8, 1 int16, 1 int32
	b = flatbuffers.NewBuilder(0)
	b.StartObject(1)
	b.Prep(4+4+4, 0)
	b.PrependInt8(55)
	b.Pad(3)
	b.PrependInt16(0x1234)
	b.Pad(2)
	b.PrependInt32(0x12345678)
	structStart := b.Offset()
	b.PrependStructSlot(0, structStart, 0)
	b.EndObject()
	check([]byte{
		6, 0, // vtable bytes
		16, 0, // end of object from here
		4, 0, // start of struct from here
		6, 0, 0, 0, // offset for start of vtable (int32)
		0x78, 0x56, 0x34, 0x12, // value 2
		0, 0, // padding
		0x34, 0x12, // value 1
		0, 0, 0, // padding
		55, // value 0
	})

	// test 15: vtable with 1 vector of 2 struct of 2 int8
	b = flatbuffers.NewBuilder(0)
	b.StartVector(flatbuffers.SizeInt8*2, 2)
	b.PrependInt8(33)
	b.PrependInt8(44)
	b.PrependInt8(55)
	b.PrependInt8(66)
	vecend = b.EndVector(2)
	b.StartObject(1)
	b.PrependUOffsetTSlot(0, vecend, 0)
	b.EndObject()
	check([]byte{
		6, 0, // vtable bytes
		8, 0,
		4, 0, // offset of vector offset
		6, 0, 0, 0, // offset for start of vtable (int32)
		4, 0, 0, 0, // vector start offset

		2, 0, 0, 0, // vector length
		66, // vector value 1,1
		55, // vector value 1,0
		44, // vector value 0,1
		33, // vector value 0,0
	})

	// test 16: table with some elements
	b = flatbuffers.NewBuilder(0)
	b.StartObject(2)
	b.PrependInt8Slot(0, 33, 0)
	b.PrependInt16Slot(1, 66, 0)
	off := b.EndObject()
	b.Finish(off)

	check([]byte{
		12, 0, 0, 0, // root of table: points to vtable offset

		8, 0, // vtable bytes
		8, 0, // end of object from here
		7, 0, // start of value 0
		4, 0, // start of value 1

		8, 0, 0, 0, // offset for start of vtable (int32)

		66, 0, // value 1
		0,  // padding
		33, // value 0
	})

	// test 17: one unfinished table and one finished table
	b = flatbuffers.NewBuilder(0)
	b.StartObject(2)
	b.PrependInt8Slot(0, 33, 0)
	b.PrependInt8Slot(1, 44, 0)
	off = b.EndObject()
	b.Finish(off)

	b.StartObject(3)
	b.PrependInt8Slot(0, 55, 0)
	b.PrependInt8Slot(1, 66, 0)
	b.PrependInt8Slot(2, 77, 0)
	off = b.EndObject()
	b.Finish(off)

	check([]byte{
		16, 0, 0, 0, // root of table: points to object
		0, 0, // padding

		10, 0, // vtable bytes
		8, 0, // size of object
		7, 0, // start of value 0
		6, 0, // start of value 1
		5, 0, // start of value 2
		10, 0, 0, 0, // offset for start of vtable (int32)
		0,  // padding
		77, // value 2
		66, // value 1
		55, // value 0

		12, 0, 0, 0, // root of table: points to object

		8, 0, // vtable bytes
		8, 0, // size of object
		7, 0, // start of value 0
		6, 0, // start of value 1
		8, 0, 0, 0, // offset for start of vtable (int32)
		0, 0, // padding
		44, // value 1
		33, // value 0
	})

	// test 18: a bunch of bools
	b = flatbuffers.NewBuilder(0)
	b.StartObject(8)
	b.PrependBoolSlot(0, true, false)
	b.PrependBoolSlot(1, true, false)
	b.PrependBoolSlot(2, true, false)
	b.PrependBoolSlot(3, true, false)
	b.PrependBoolSlot(4, true, false)
	b.PrependBoolSlot(5, true, false)
	b.PrependBoolSlot(6, true, false)
	b.PrependBoolSlot(7, true, false)
	off = b.EndObject()
	b.Finish(off)

	check([]byte{
		24, 0, 0, 0, // root of table: points to vtable offset

		20, 0, // vtable bytes
		12, 0, // size of object
		11, 0, // start of value 0
		10, 0, // start of value 1
		9, 0, // start of value 2
		8, 0, // start of value 3
		7, 0, // start of value 4
		6, 0, // start of value 5
		5, 0, // start of value 6
		4, 0, // start of value 7
		20, 0, 0, 0, // vtable offset

		1, // value 7
		1, // value 6
		1, // value 5
		1, // value 4
		1, // value 3
		1, // value 2
		1, // value 1
		1, // value 0
	})

	// test 19: three bools
	b = flatbuffers.NewBuilder(0)
	b.StartObject(3)
	b.PrependBoolSlot(0, true, false)
	b.PrependBoolSlot(1, true, false)
	b.PrependBoolSlot(2, true, false)
	off = b.EndObject()
	b.Finish(off)

	check([]byte{
		16, 0, 0, 0, // root of table: points to vtable offset

		0, 0, // padding

		10, 0, // vtable bytes
		8, 0, // size of object
		7, 0, // start of value 0
		6, 0, // start of value 1
		5, 0, // start of value 2
		10, 0, 0, 0, // vtable offset from here

		0, // padding
		1, // value 2
		1, // value 1
		1, // value 0
	})

	// test 20: some floats
	b = flatbuffers.NewBuilder(0)
	b.StartObject(1)
	b.PrependFloat32Slot(0, 1.0, 0.0)
	off = b.EndObject()

	check([]byte{
		6, 0, // vtable bytes
		8, 0, // size of object
		4, 0, // start of value 0
		6, 0, 0, 0, // vtable offset

		0, 0, 128, 63, // value 0
	})
}

// CheckManualBuild builds a Monster manually.
func CheckManualBuild(fail func(string, ...interface{})) ([]byte, flatbuffers.UOffsetT) {
	b := flatbuffers.NewBuilder(0)
	str := b.CreateString("MyMonster")

	b.StartVector(1, 5)
	b.PrependByte(4)
	b.PrependByte(3)
	b.PrependByte(2)
	b.PrependByte(1)
	b.PrependByte(0)
	inv := b.EndVector(5)

	b.StartObject(13)
	b.PrependInt16Slot(2, 20, 100)
	mon2 := b.EndObject()

	// Test4Vector
	b.StartVector(4, 2)

	// Test 0
	b.Prep(2, 4)
	b.Pad(1)
	b.PlaceInt8(20)
	b.PlaceInt16(10)

	// Test 1
	b.Prep(2, 4)
	b.Pad(1)
	b.PlaceInt8(40)
	b.PlaceInt16(30)

	// end testvector
	test4 := b.EndVector(2)

	b.StartObject(13)

	// a vec3
	b.Prep(16, 32)
	b.Pad(2)
	b.Prep(2, 4)
	b.Pad(1)
	b.PlaceByte(6)
	b.PlaceInt16(5)
	b.Pad(1)
	b.PlaceByte(4)
	b.PlaceFloat64(3.0)
	b.Pad(4)
	b.PlaceFloat32(3.0)
	b.PlaceFloat32(2.0)
	b.PlaceFloat32(1.0)
	vec3Loc := b.Offset()
	// end vec3

	b.PrependStructSlot(0, vec3Loc, 0) // vec3. noop
	b.PrependInt16Slot(2, 80, 100)     // hp
	b.PrependUOffsetTSlot(3, str, 0)
	b.PrependUOffsetTSlot(5, inv, 0) // inventory
	b.PrependByteSlot(7, 1, 0)
	b.PrependUOffsetTSlot(8, mon2, 0)
	b.PrependUOffsetTSlot(9, test4, 0)
	mon := b.EndObject()

	b.Finish(mon)

	return b.Bytes, b.Head()
}

// CheckGeneratedBuild uses generated code to build the example Monster.
func CheckGeneratedBuild(fail func(string, ...interface{})) ([]byte, flatbuffers.UOffsetT) {
	b := flatbuffers.NewBuilder(0)
	str := b.CreateString("MyMonster")
	example.MonsterStartInventoryVector(b, 5)
	b.PrependByte(4)
	b.PrependByte(3)
	b.PrependByte(2)
	b.PrependByte(1)
	b.PrependByte(0)
	inv := b.EndVector(5)

	example.MonsterStart(b)
	example.MonsterAddHp(b, int16(20))
	mon2 := example.MonsterEnd(b)

	example.MonsterStartTest4Vector(b, 2)
	example.CreateTest(b, 10, 20)
	example.CreateTest(b, 30, 40)
	test4 := b.EndVector(2)

	example.MonsterStart(b)

	pos := example.CreateVec3(b, 1.0, 2.0, 3.0, 3.0, 4, 5, 6)
	example.MonsterAddPos(b, pos)

	example.MonsterAddHp(b, 80)
	example.MonsterAddName(b, str)
	example.MonsterAddInventory(b, inv)
	example.MonsterAddTestType(b, 1)
	example.MonsterAddTest(b, mon2)
	example.MonsterAddTest4(b, test4)
	mon := example.MonsterEnd(b)

	b.Finish(mon)

	return b.Bytes, b.Head()
}

// CheckVtableDeduplication verifies that vtables are deduplicated.
func CheckVtableDeduplication(fail func(string, ...interface{})) {
	b := flatbuffers.NewBuilder(0)

	b.StartObject(4)
	b.PrependByteSlot(0, 0, 0)
	b.PrependByteSlot(1, 11, 0)
	b.PrependByteSlot(2, 22, 0)
	b.PrependInt16Slot(3, 33, 0)
	obj0 := b.EndObject()

	b.StartObject(4)
	b.PrependByteSlot(0, 0, 0)
	b.PrependByteSlot(1, 44, 0)
	b.PrependByteSlot(2, 55, 0)
	b.PrependInt16Slot(3, 66, 0)
	obj1 := b.EndObject()

	b.StartObject(4)
	b.PrependByteSlot(0, 0, 0)
	b.PrependByteSlot(1, 77, 0)
	b.PrependByteSlot(2, 88, 0)
	b.PrependInt16Slot(3, 99, 0)
	obj2 := b.EndObject()

	got := b.Bytes[b.Head():]

	want := []byte{
		240, 255, 255, 255, // == -12. offset to dedupped vtable.
		99, 0,
		88,
		77,
		248, 255, 255, 255, // == -8. offset to dedupped vtable.
		66, 0,
		55,
		44,
		12, 0,
		8, 0,
		0, 0,
		7, 0,
		6, 0,
		4, 0,
		12, 0, 0, 0,
		33, 0,
		22,
		11,
	}

	if !bytes.Equal(want, got) {
		fail("testVtableDeduplication want:\n%d %v\nbut got:\n%d %v\n",
			len(want), want, len(got), got)
	}

	table0 := &flatbuffers.Table{b.Bytes, flatbuffers.UOffsetT(len(b.Bytes)) - obj0}
	table1 := &flatbuffers.Table{b.Bytes, flatbuffers.UOffsetT(len(b.Bytes)) - obj1}
	table2 := &flatbuffers.Table{b.Bytes, flatbuffers.UOffsetT(len(b.Bytes)) - obj2}

	testTable := func(tab *flatbuffers.Table, a flatbuffers.VOffsetT, b, c, d byte) {
		// vtable size
		if got := tab.GetVOffsetTSlot(0, 0); 12 != got {
			fail("failed 0, 0: %d", got)
		}
		// object size
		if got := tab.GetVOffsetTSlot(2, 0); 8 != got {
			fail("failed 2, 0: %d", got)
		}
		// default value
		if got := tab.GetVOffsetTSlot(4, 0); a != got {
			fail("failed 4, 0: %d", got)
		}
		if got := tab.GetByteSlot(6, 0); b != got {
			fail("failed 6, 0: %d", got)
		}
		if val := tab.GetByteSlot(8, 0); c != val {
			fail("failed 8, 0: %d", got)
		}
		if got := tab.GetByteSlot(10, 0); d != got {
			fail("failed 10, 0: %d", got)
		}
	}

	testTable(table0, 0, 11, 22, 33)
	testTable(table1, 0, 44, 55, 66)
	testTable(table2, 0, 77, 88, 99)
}

// CheckDocExample checks that the code given in FlatBuffers documentation
// is syntactically correct.
func CheckDocExample(buf []byte, off flatbuffers.UOffsetT, fail func(string, ...interface{})) {
	monster := example.GetRootAsMonster(buf, off)
	_ = monster.Hp()
	_ = monster.Pos(nil)
	for i := 0; i < monster.InventoryLength(); i++ {
		_ = monster.Inventory(i) // do something here
	}

	builder := flatbuffers.NewBuilder(0)

	example.MonsterStartInventoryVector(builder, 5)
	for i := 4; i >= 0; i-- {
		builder.PrependByte(byte(i))
	}
	inv := builder.EndVector(5)

	str := builder.CreateString("MyMonster")
	example.MonsterStart(builder)
	example.MonsterAddPos(builder, example.CreateVec3(builder, 1.0, 2.0, 3.0, 3.0, 4, 5, 6))
	example.MonsterAddHp(builder, 80)
	example.MonsterAddName(builder, str)
	example.MonsterAddInventory(builder, inv)
	example.MonsterAddTestType(builder, 1)
	// example.MonsterAddTest(builder, mon2)
	// example.MonsterAddTest4(builder, test4s)
	_ = example.MonsterEnd(builder)
}

// Include simple random number generator to ensure results will be the
// same cross platform.
// http://en.wikipedia.org/wiki/Park%E2%80%93Miller_random_number_generator
type LCG uint32

const InitialLCGSeed = 48271

func NewLCG() *LCG {
	n := uint32(InitialLCGSeed)
	l := LCG(n)
	return &l
}

func (lcg *LCG) Reset() {
	*lcg = InitialLCGSeed
}

func (lcg *LCG) Next() uint32 {
	n := uint32((uint64(*lcg) * uint64(279470273)) % uint64(4294967291))
	*lcg = LCG(n)
	return n
}

// CheckEquality verifies that two byte buffers are the same.
func CheckEquality(a, b []byte, msg string, fail func(string, ...interface{})) {
	if !bytes.Equal(a, b) {
		fail("%s constructed object does not pass byte equality", msg)
	}
}

// BenchmarkVtableDeduplication measures the speed of vtable deduplication
// by creating prePop vtables, then populating b.N objects with a
// different single vtable.
//
// When b.N is large (as in long benchmarks), memory usage may be high.
func BenchmarkVtableDeduplication(b *testing.B) {
	prePop := 10
	builder := flatbuffers.NewBuilder(0)

	// pre-populate some vtables:
	for i := 0; i < prePop; i++ {
		builder.StartObject(i)
		for j := 0; j < i; j++ {
			builder.PrependInt16Slot(j, int16(j), 0)
		}
		builder.EndObject()
	}

	// benchmark deduplication of a new vtable:
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		lim := prePop

		builder.StartObject(lim)
		for j := 0; j < lim; j++ {
			builder.PrependInt16Slot(j, int16(j), 0)
		}
		builder.EndObject()
	}
}
