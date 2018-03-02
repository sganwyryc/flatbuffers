// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace MyGame.Example
{

using global::System;
using global::FlatBuffers;

/// an example documentation comment: monster object
public struct Monster : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static Monster GetRootAsMonster(ByteBuffer _bb) { return GetRootAsMonster(_bb, new Monster()); }
  public static Monster GetRootAsMonster(ByteBuffer _bb, Monster obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public static bool MonsterBufferHasIdentifier(ByteBuffer _bb) { return Table.__has_identifier(_bb, "MONS"); }
  public void __init(int _i, ByteBuffer _bb) { __p.bb_pos = _i; __p.bb = _bb; }
  public Monster __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public Vec3? Pos { get { int o = __p.__offset(4); return o != 0 ? (Vec3?)(new Vec3()).__assign(o + __p.bb_pos, __p.bb) : null; } }
  public short Mana { get { int o = __p.__offset(6); return o != 0 ? __p.bb.GetShort(o + __p.bb_pos) : (short)150; } }
  public bool MutateMana(short mana) { int o = __p.__offset(6); if (o != 0) { __p.bb.PutShort(o + __p.bb_pos, mana); return true; } else { return false; } }
  public short Hp { get { int o = __p.__offset(8); return o != 0 ? __p.bb.GetShort(o + __p.bb_pos) : (short)100; } }
  public bool MutateHp(short hp) { int o = __p.__offset(8); if (o != 0) { __p.bb.PutShort(o + __p.bb_pos, hp); return true; } else { return false; } }
  public string Name { get { int o = __p.__offset(10); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
  public ArraySegment<byte>? GetNameBytes() { return __p.__vector_as_arraysegment(10); }
  public byte Inventory(int j) { int o = __p.__offset(14); return o != 0 ? __p.bb.Get(__p.__vector(o) + j * 1) : (byte)0; }
  public int InventoryLength { get { int o = __p.__offset(14); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetInventoryBytes() { return __p.__vector_as_arraysegment(14); }
  public bool MutateInventory(int j, byte inventory) { int o = __p.__offset(14); if (o != 0) { __p.bb.Put(__p.__vector(o) + j * 1, inventory); return true; } else { return false; } }
  public Color Color { get { int o = __p.__offset(16); return o != 0 ? (Color)__p.bb.GetSbyte(o + __p.bb_pos) : Color.Blue; } }
  public bool MutateColor(Color color) { int o = __p.__offset(16); if (o != 0) { __p.bb.PutSbyte(o + __p.bb_pos, (sbyte)color); return true; } else { return false; } }
  public Any TestType { get { int o = __p.__offset(18); return o != 0 ? (Any)__p.bb.Get(o + __p.bb_pos) : Any.NONE; } }
  public bool MutateTestType(Any test_type) { int o = __p.__offset(18); if (o != 0) { __p.bb.Put(o + __p.bb_pos, (byte)test_type); return true; } else { return false; } }
  public TTable? Test<TTable>() where TTable : struct, IFlatbufferObject { int o = __p.__offset(20); return o != 0 ? (TTable?)__p.__union<TTable>(o) : null; }
  public Test? Test4(int j) { int o = __p.__offset(22); return o != 0 ? (Test?)(new Test()).__assign(__p.__vector(o) + j * 4, __p.bb) : null; }
  public int Test4Length { get { int o = __p.__offset(22); return o != 0 ? __p.__vector_len(o) : 0; } }
  public string Testarrayofstring(int j) { int o = __p.__offset(24); return o != 0 ? __p.__string(__p.__vector(o) + j * 4) : null; }
  public int TestarrayofstringLength { get { int o = __p.__offset(24); return o != 0 ? __p.__vector_len(o) : 0; } }
  /// an example documentation comment: this will end up in the generated code
  /// multiline too
  public Monster? Testarrayoftables(int j) { int o = __p.__offset(26); return o != 0 ? (Monster?)(new Monster()).__assign(__p.__indirect(__p.__vector(o) + j * 4), __p.bb) : null; }
  public int TestarrayoftablesLength { get { int o = __p.__offset(26); return o != 0 ? __p.__vector_len(o) : 0; } }
  public Monster? TestarrayoftablesByKey(string key) { int o = __p.__offset(26); return o != 0 ? Monster.__lookup_by_key(null, __p.__vector(o), key, __p.bb) : null; }
  public Monster? TestarrayoftablesByKey(Monster? obj, string key) { int o = __p.__offset(26); return o != 0 ? Monster.__lookup_by_key(obj, __p.__vector(o), key, __p.bb) : null; }
  public Monster? Enemy { get { int o = __p.__offset(28); return o != 0 ? (Monster?)(new Monster()).__assign(__p.__indirect(o + __p.bb_pos), __p.bb) : null; } }
  public byte Testnestedflatbuffer(int j) { int o = __p.__offset(30); return o != 0 ? __p.bb.Get(__p.__vector(o) + j * 1) : (byte)0; }
  public int TestnestedflatbufferLength { get { int o = __p.__offset(30); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetTestnestedflatbufferBytes() { return __p.__vector_as_arraysegment(30); }
  public Monster? GetTestnestedflatbufferAsMonster() { int o = __p.__offset(30); return o != 0 ? (Monster?)(new Monster()).__assign(__p.__indirect(__p.__vector(o)), __p.bb) : null; }
  public bool MutateTestnestedflatbuffer(int j, byte testnestedflatbuffer) { int o = __p.__offset(30); if (o != 0) { __p.bb.Put(__p.__vector(o) + j * 1, testnestedflatbuffer); return true; } else { return false; } }
  public Stat? Testempty { get { int o = __p.__offset(32); return o != 0 ? (Stat?)(new Stat()).__assign(__p.__indirect(o + __p.bb_pos), __p.bb) : null; } }
  public bool Testbool { get { int o = __p.__offset(34); return o != 0 ? 0!=__p.bb.Get(o + __p.bb_pos) : (bool)false; } }
  public bool MutateTestbool(bool testbool) { int o = __p.__offset(34); if (o != 0) { __p.bb.Put(o + __p.bb_pos, (byte)(testbool ? 1 : 0)); return true; } else { return false; } }
  public int Testhashs32Fnv1 { get { int o = __p.__offset(36); return o != 0 ? __p.bb.GetInt(o + __p.bb_pos) : (int)0; } }
  public bool MutateTesthashs32Fnv1(int testhashs32_fnv1) { int o = __p.__offset(36); if (o != 0) { __p.bb.PutInt(o + __p.bb_pos, testhashs32_fnv1); return true; } else { return false; } }
  public uint Testhashu32Fnv1 { get { int o = __p.__offset(38); return o != 0 ? __p.bb.GetUint(o + __p.bb_pos) : (uint)0; } }
  public bool MutateTesthashu32Fnv1(uint testhashu32_fnv1) { int o = __p.__offset(38); if (o != 0) { __p.bb.PutUint(o + __p.bb_pos, testhashu32_fnv1); return true; } else { return false; } }
  public long Testhashs64Fnv1 { get { int o = __p.__offset(40); return o != 0 ? __p.bb.GetLong(o + __p.bb_pos) : (long)0; } }
  public bool MutateTesthashs64Fnv1(long testhashs64_fnv1) { int o = __p.__offset(40); if (o != 0) { __p.bb.PutLong(o + __p.bb_pos, testhashs64_fnv1); return true; } else { return false; } }
  public ulong Testhashu64Fnv1 { get { int o = __p.__offset(42); return o != 0 ? __p.bb.GetUlong(o + __p.bb_pos) : (ulong)0; } }
  public bool MutateTesthashu64Fnv1(ulong testhashu64_fnv1) { int o = __p.__offset(42); if (o != 0) { __p.bb.PutUlong(o + __p.bb_pos, testhashu64_fnv1); return true; } else { return false; } }
  public int Testhashs32Fnv1a { get { int o = __p.__offset(44); return o != 0 ? __p.bb.GetInt(o + __p.bb_pos) : (int)0; } }
  public bool MutateTesthashs32Fnv1a(int testhashs32_fnv1a) { int o = __p.__offset(44); if (o != 0) { __p.bb.PutInt(o + __p.bb_pos, testhashs32_fnv1a); return true; } else { return false; } }
  public uint Testhashu32Fnv1a { get { int o = __p.__offset(46); return o != 0 ? __p.bb.GetUint(o + __p.bb_pos) : (uint)0; } }
  public bool MutateTesthashu32Fnv1a(uint testhashu32_fnv1a) { int o = __p.__offset(46); if (o != 0) { __p.bb.PutUint(o + __p.bb_pos, testhashu32_fnv1a); return true; } else { return false; } }
  public long Testhashs64Fnv1a { get { int o = __p.__offset(48); return o != 0 ? __p.bb.GetLong(o + __p.bb_pos) : (long)0; } }
  public bool MutateTesthashs64Fnv1a(long testhashs64_fnv1a) { int o = __p.__offset(48); if (o != 0) { __p.bb.PutLong(o + __p.bb_pos, testhashs64_fnv1a); return true; } else { return false; } }
  public ulong Testhashu64Fnv1a { get { int o = __p.__offset(50); return o != 0 ? __p.bb.GetUlong(o + __p.bb_pos) : (ulong)0; } }
  public bool MutateTesthashu64Fnv1a(ulong testhashu64_fnv1a) { int o = __p.__offset(50); if (o != 0) { __p.bb.PutUlong(o + __p.bb_pos, testhashu64_fnv1a); return true; } else { return false; } }
  public bool Testarrayofbools(int j) { int o = __p.__offset(52); return o != 0 ? 0!=__p.bb.Get(__p.__vector(o) + j * 1) : false; }
  public int TestarrayofboolsLength { get { int o = __p.__offset(52); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetTestarrayofboolsBytes() { return __p.__vector_as_arraysegment(52); }
  public bool MutateTestarrayofbools(int j, bool testarrayofbools) { int o = __p.__offset(52); if (o != 0) { __p.bb.Put(__p.__vector(o) + j * 1, (byte)(testarrayofbools ? 1 : 0)); return true; } else { return false; } }
  public float Testf { get { int o = __p.__offset(54); return o != 0 ? __p.bb.GetFloat(o + __p.bb_pos) : (float)3.14159f; } }
  public bool MutateTestf(float testf) { int o = __p.__offset(54); if (o != 0) { __p.bb.PutFloat(o + __p.bb_pos, testf); return true; } else { return false; } }
  public float Testf2 { get { int o = __p.__offset(56); return o != 0 ? __p.bb.GetFloat(o + __p.bb_pos) : (float)3.0f; } }
  public bool MutateTestf2(float testf2) { int o = __p.__offset(56); if (o != 0) { __p.bb.PutFloat(o + __p.bb_pos, testf2); return true; } else { return false; } }
  public float Testf3 { get { int o = __p.__offset(58); return o != 0 ? __p.bb.GetFloat(o + __p.bb_pos) : (float)0.0f; } }
  public bool MutateTestf3(float testf3) { int o = __p.__offset(58); if (o != 0) { __p.bb.PutFloat(o + __p.bb_pos, testf3); return true; } else { return false; } }
  public string Testarrayofstring2(int j) { int o = __p.__offset(60); return o != 0 ? __p.__string(__p.__vector(o) + j * 4) : null; }
  public int Testarrayofstring2Length { get { int o = __p.__offset(60); return o != 0 ? __p.__vector_len(o) : 0; } }
  public Ability? Testarrayofsortedstruct(int j) { int o = __p.__offset(62); return o != 0 ? (Ability?)(new Ability()).__assign(__p.__vector(o) + j * 8, __p.bb) : null; }
  public int TestarrayofsortedstructLength { get { int o = __p.__offset(62); return o != 0 ? __p.__vector_len(o) : 0; } }
  public byte Flex(int j) { int o = __p.__offset(64); return o != 0 ? __p.bb.Get(__p.__vector(o) + j * 1) : (byte)0; }
  public int FlexLength { get { int o = __p.__offset(64); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetFlexBytes() { return __p.__vector_as_arraysegment(64); }
  public bool MutateFlex(int j, byte flex) { int o = __p.__offset(64); if (o != 0) { __p.bb.Put(__p.__vector(o) + j * 1, flex); return true; } else { return false; } }
  public Test? Test5(int j) { int o = __p.__offset(66); return o != 0 ? (Test?)(new Test()).__assign(__p.__vector(o) + j * 4, __p.bb) : null; }
  public int Test5Length { get { int o = __p.__offset(66); return o != 0 ? __p.__vector_len(o) : 0; } }
  public long VectorOfLongs(int j) { int o = __p.__offset(68); return o != 0 ? __p.bb.GetLong(__p.__vector(o) + j * 8) : (long)0; }
  public int VectorOfLongsLength { get { int o = __p.__offset(68); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetVectorOfLongsBytes() { return __p.__vector_as_arraysegment(68); }
  public bool MutateVectorOfLongs(int j, long vector_of_longs) { int o = __p.__offset(68); if (o != 0) { __p.bb.PutLong(__p.__vector(o) + j * 8, vector_of_longs); return true; } else { return false; } }
  public double VectorOfDoubles(int j) { int o = __p.__offset(70); return o != 0 ? __p.bb.GetDouble(__p.__vector(o) + j * 8) : (double)0; }
  public int VectorOfDoublesLength { get { int o = __p.__offset(70); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetVectorOfDoublesBytes() { return __p.__vector_as_arraysegment(70); }
  public bool MutateVectorOfDoubles(int j, double vector_of_doubles) { int o = __p.__offset(70); if (o != 0) { __p.bb.PutDouble(__p.__vector(o) + j * 8, vector_of_doubles); return true; } else { return false; } }
  public MyGame.InParentNamespace? ParentNamespaceTest { get { int o = __p.__offset(72); return o != 0 ? (MyGame.InParentNamespace?)(new MyGame.InParentNamespace()).__assign(__p.__indirect(o + __p.bb_pos), __p.bb) : null; } }
  public Referrable? VectorOfReferrables(int j) { int o = __p.__offset(74); return o != 0 ? (Referrable?)(new Referrable()).__assign(__p.__indirect(__p.__vector(o) + j * 4), __p.bb) : null; }
  public int VectorOfReferrablesLength { get { int o = __p.__offset(74); return o != 0 ? __p.__vector_len(o) : 0; } }
  public Referrable? VectorOfReferrablesByKey(ulong key) { int o = __p.__offset(74); return o != 0 ? Referrable.__lookup_by_key(null, __p.__vector(o), key, __p.bb) : null; }
  public Referrable? VectorOfReferrablesByKey(Referrable? obj, ulong key) { int o = __p.__offset(74); return o != 0 ? Referrable.__lookup_by_key(obj, __p.__vector(o), key, __p.bb) : null; }
  public ulong SingleWeakReference { get { int o = __p.__offset(76); return o != 0 ? __p.bb.GetUlong(o + __p.bb_pos) : (ulong)0; } }
  public bool MutateSingleWeakReference(ulong single_weak_reference) { int o = __p.__offset(76); if (o != 0) { __p.bb.PutUlong(o + __p.bb_pos, single_weak_reference); return true; } else { return false; } }
  public ulong VectorOfWeakReferences(int j) { int o = __p.__offset(78); return o != 0 ? __p.bb.GetUlong(__p.__vector(o) + j * 8) : (ulong)0; }
  public int VectorOfWeakReferencesLength { get { int o = __p.__offset(78); return o != 0 ? __p.__vector_len(o) : 0; } }
  public ArraySegment<byte>? GetVectorOfWeakReferencesBytes() { return __p.__vector_as_arraysegment(78); }
  public bool MutateVectorOfWeakReferences(int j, ulong vector_of_weak_references) { int o = __p.__offset(78); if (o != 0) { __p.bb.PutUlong(__p.__vector(o) + j * 8, vector_of_weak_references); return true; } else { return false; } }

  public static void StartMonster(FlatBufferBuilder builder) { builder.StartObject(38); }
  public static void AddPos(FlatBufferBuilder builder, Offset<Vec3> posOffset) { builder.AddStruct(0, posOffset.Value, 0); }
  public static void AddMana(FlatBufferBuilder builder, short mana) { builder.AddShort(1, mana, 150); }
  public static void AddHp(FlatBufferBuilder builder, short hp) { builder.AddShort(2, hp, 100); }
  public static void AddName(FlatBufferBuilder builder, StringOffset nameOffset) { builder.AddOffset(3, nameOffset.Value, 0); }
  public static void AddInventory(FlatBufferBuilder builder, VectorOffset inventoryOffset) { builder.AddOffset(5, inventoryOffset.Value, 0); }
  public static VectorOffset CreateInventoryVector(FlatBufferBuilder builder, byte[] data) { builder.StartVector(1, data.Length, 1); for (int i = data.Length - 1; i >= 0; i--) builder.AddByte(data[i]); return builder.EndVector(); }
  public static void StartInventoryVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(1, numElems, 1); }
  public static void AddColor(FlatBufferBuilder builder, Color color) { builder.AddSbyte(6, (sbyte)color, 8); }
  public static void AddTestType(FlatBufferBuilder builder, Any testType) { builder.AddByte(7, (byte)testType, 0); }
  public static void AddTest(FlatBufferBuilder builder, int testOffset) { builder.AddOffset(8, testOffset, 0); }
  public static void AddTest4(FlatBufferBuilder builder, VectorOffset test4Offset) { builder.AddOffset(9, test4Offset.Value, 0); }
  public static void StartTest4Vector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 2); }
  public static void AddTestarrayofstring(FlatBufferBuilder builder, VectorOffset testarrayofstringOffset) { builder.AddOffset(10, testarrayofstringOffset.Value, 0); }
  public static VectorOffset CreateTestarrayofstringVector(FlatBufferBuilder builder, StringOffset[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static void StartTestarrayofstringVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static void AddTestarrayoftables(FlatBufferBuilder builder, VectorOffset testarrayoftablesOffset) { builder.AddOffset(11, testarrayoftablesOffset.Value, 0); }
  public static VectorOffset CreateTestarrayoftablesVector(FlatBufferBuilder builder, Offset<Monster>[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static void StartTestarrayoftablesVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static void AddEnemy(FlatBufferBuilder builder, Offset<Monster> enemyOffset) { builder.AddOffset(12, enemyOffset.Value, 0); }
  public static void AddTestnestedflatbuffer(FlatBufferBuilder builder, VectorOffset testnestedflatbufferOffset) { builder.AddOffset(13, testnestedflatbufferOffset.Value, 0); }
  public static VectorOffset CreateTestnestedflatbufferVector(FlatBufferBuilder builder, byte[] data) { builder.StartVector(1, data.Length, 1); for (int i = data.Length - 1; i >= 0; i--) builder.AddByte(data[i]); return builder.EndVector(); }
  public static void StartTestnestedflatbufferVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(1, numElems, 1); }
  public static void AddTestempty(FlatBufferBuilder builder, Offset<Stat> testemptyOffset) { builder.AddOffset(14, testemptyOffset.Value, 0); }
  public static void AddTestbool(FlatBufferBuilder builder, bool testbool) { builder.AddBool(15, testbool, false); }
  public static void AddTesthashs32Fnv1(FlatBufferBuilder builder, int testhashs32Fnv1) { builder.AddInt(16, testhashs32Fnv1, 0); }
  public static void AddTesthashu32Fnv1(FlatBufferBuilder builder, uint testhashu32Fnv1) { builder.AddUint(17, testhashu32Fnv1, 0); }
  public static void AddTesthashs64Fnv1(FlatBufferBuilder builder, long testhashs64Fnv1) { builder.AddLong(18, testhashs64Fnv1, 0); }
  public static void AddTesthashu64Fnv1(FlatBufferBuilder builder, ulong testhashu64Fnv1) { builder.AddUlong(19, testhashu64Fnv1, 0); }
  public static void AddTesthashs32Fnv1a(FlatBufferBuilder builder, int testhashs32Fnv1a) { builder.AddInt(20, testhashs32Fnv1a, 0); }
  public static void AddTesthashu32Fnv1a(FlatBufferBuilder builder, uint testhashu32Fnv1a) { builder.AddUint(21, testhashu32Fnv1a, 0); }
  public static void AddTesthashs64Fnv1a(FlatBufferBuilder builder, long testhashs64Fnv1a) { builder.AddLong(22, testhashs64Fnv1a, 0); }
  public static void AddTesthashu64Fnv1a(FlatBufferBuilder builder, ulong testhashu64Fnv1a) { builder.AddUlong(23, testhashu64Fnv1a, 0); }
  public static void AddTestarrayofbools(FlatBufferBuilder builder, VectorOffset testarrayofboolsOffset) { builder.AddOffset(24, testarrayofboolsOffset.Value, 0); }
  public static VectorOffset CreateTestarrayofboolsVector(FlatBufferBuilder builder, bool[] data) { builder.StartVector(1, data.Length, 1); for (int i = data.Length - 1; i >= 0; i--) builder.AddBool(data[i]); return builder.EndVector(); }
  public static void StartTestarrayofboolsVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(1, numElems, 1); }
  public static void AddTestf(FlatBufferBuilder builder, float testf) { builder.AddFloat(25, testf, 3.14159f); }
  public static void AddTestf2(FlatBufferBuilder builder, float testf2) { builder.AddFloat(26, testf2, 3.0f); }
  public static void AddTestf3(FlatBufferBuilder builder, float testf3) { builder.AddFloat(27, testf3, 0.0f); }
  public static void AddTestarrayofstring2(FlatBufferBuilder builder, VectorOffset testarrayofstring2Offset) { builder.AddOffset(28, testarrayofstring2Offset.Value, 0); }
  public static VectorOffset CreateTestarrayofstring2Vector(FlatBufferBuilder builder, StringOffset[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static void StartTestarrayofstring2Vector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static void AddTestarrayofsortedstruct(FlatBufferBuilder builder, VectorOffset testarrayofsortedstructOffset) { builder.AddOffset(29, testarrayofsortedstructOffset.Value, 0); }
  public static void StartTestarrayofsortedstructVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(8, numElems, 4); }
  public static void AddFlex(FlatBufferBuilder builder, VectorOffset flexOffset) { builder.AddOffset(30, flexOffset.Value, 0); }
  public static VectorOffset CreateFlexVector(FlatBufferBuilder builder, byte[] data) { builder.StartVector(1, data.Length, 1); for (int i = data.Length - 1; i >= 0; i--) builder.AddByte(data[i]); return builder.EndVector(); }
  public static void StartFlexVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(1, numElems, 1); }
  public static void AddTest5(FlatBufferBuilder builder, VectorOffset test5Offset) { builder.AddOffset(31, test5Offset.Value, 0); }
  public static void StartTest5Vector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 2); }
  public static void AddVectorOfLongs(FlatBufferBuilder builder, VectorOffset vectorOfLongsOffset) { builder.AddOffset(32, vectorOfLongsOffset.Value, 0); }
  public static VectorOffset CreateVectorOfLongsVector(FlatBufferBuilder builder, long[] data) { builder.StartVector(8, data.Length, 8); for (int i = data.Length - 1; i >= 0; i--) builder.AddLong(data[i]); return builder.EndVector(); }
  public static void StartVectorOfLongsVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(8, numElems, 8); }
  public static void AddVectorOfDoubles(FlatBufferBuilder builder, VectorOffset vectorOfDoublesOffset) { builder.AddOffset(33, vectorOfDoublesOffset.Value, 0); }
  public static VectorOffset CreateVectorOfDoublesVector(FlatBufferBuilder builder, double[] data) { builder.StartVector(8, data.Length, 8); for (int i = data.Length - 1; i >= 0; i--) builder.AddDouble(data[i]); return builder.EndVector(); }
  public static void StartVectorOfDoublesVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(8, numElems, 8); }
  public static void AddParentNamespaceTest(FlatBufferBuilder builder, Offset<MyGame.InParentNamespace> parentNamespaceTestOffset) { builder.AddOffset(34, parentNamespaceTestOffset.Value, 0); }
  public static void AddVectorOfReferrables(FlatBufferBuilder builder, VectorOffset vectorOfReferrablesOffset) { builder.AddOffset(35, vectorOfReferrablesOffset.Value, 0); }
  public static VectorOffset CreateVectorOfReferrablesVector(FlatBufferBuilder builder, Offset<Referrable>[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static void StartVectorOfReferrablesVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static void AddSingleWeakReference(FlatBufferBuilder builder, ulong singleWeakReference) { builder.AddUlong(36, singleWeakReference, 0); }
  public static void AddVectorOfWeakReferences(FlatBufferBuilder builder, VectorOffset vectorOfWeakReferencesOffset) { builder.AddOffset(37, vectorOfWeakReferencesOffset.Value, 0); }
  public static VectorOffset CreateVectorOfWeakReferencesVector(FlatBufferBuilder builder, ulong[] data) { builder.StartVector(8, data.Length, 8); for (int i = data.Length - 1; i >= 0; i--) builder.AddUlong(data[i]); return builder.EndVector(); }
  public static void StartVectorOfWeakReferencesVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(8, numElems, 8); }
  public static Offset<Monster> EndMonster(FlatBufferBuilder builder) {
    int o = builder.EndObject();
    builder.Required(o, 10);  // name
    return new Offset<Monster>(o);
  }
  public static void FinishMonsterBuffer(FlatBufferBuilder builder, Offset<Monster> offset) { builder.Finish(offset.Value, "MONS"); }

  public static VectorOffset CreateSortedVectorOfMonster(FlatBufferBuilder builder, Offset<Monster>[] offsets) {
    Array.Sort(offsets, (Offset<Monster> o1, Offset<Monster> o2) => Table.CompareStrings(Table.__offset(10, o1.Value, builder.DataBuffer), Table.__offset(10, o2.Value, builder.DataBuffer), builder.DataBuffer));
    return builder.CreateVectorOfTables(offsets);
  }

  public static Monster? __lookup_by_key(Monster obj, int vectorLocation, string key, ByteBuffer bb) {
    byte[] byteKey = System.Text.Encoding.UTF8.GetBytes(key);
    int span = bb.GetInt(vectorLocation - 4);
    int start = 0;
    while (span != 0) {
      int middle = span / 2;
      int tableOffset = Table.__indirect(vectorLocation + 4 * (start + middle), bb);
      int comp = Table.CompareStrings(Table.__offset(10, bb.Length - tableOffset, bb), byteKey, bb);
      if (comp > 0) {
        span = middle;
      } else if (comp < 0) {
        middle++;
        start += middle;
        span -= middle;
      } else {
        return (obj == null ? new Monster(), obj).__assign(tableOffset, bb);
      }
    }
    return null;
  }
};


}
