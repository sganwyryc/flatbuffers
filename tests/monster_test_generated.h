// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_MONSTER_TEST_MYGAME_EXAMPLE_H_
#define FLATBUFFERS_GENERATED_MONSTER_TEST_MYGAME_EXAMPLE_H_

#include "flatbuffers/flatbuffers.h"

namespace MyGame {
namespace Example {

enum {
  Color_Red = 1,
  Color_Green = 2,
  Color_Blue = 8
};

inline const char **EnumNamesColor() {
  static const char *names[] = { "Red", "Green", "", "", "", "", "", "Blue", nullptr };
  return names;
}

inline const char *EnumNameColor(int e) { return EnumNamesColor()[e - Color_Red]; }

enum {
  Any_NONE = 0,
  Any_Monster = 1
};

inline const char **EnumNamesAny() {
  static const char *names[] = { "NONE", "Monster", nullptr };
  return names;
}

inline const char *EnumNameAny(int e) { return EnumNamesAny()[e]; }

bool VerifyAny(const flatbuffers::Verifier &verifier, const void *union_obj, uint8_t type);

struct Test;
struct Vec3;
struct Monster;

MANUALLY_ALIGNED_STRUCT(2) Test {
 private:
  int16_t a_;
  int8_t b_;
  int8_t __padding0;

 public:
  Test(int16_t a, int8_t b)
    : a_(flatbuffers::EndianScalar(a)), b_(flatbuffers::EndianScalar(b)), __padding0(0) {}

  int16_t a() const { return flatbuffers::EndianScalar(a_); }
  int8_t b() const { return flatbuffers::EndianScalar(b_); }
};
STRUCT_END(Test, 4);

MANUALLY_ALIGNED_STRUCT(16) Vec3 {
 private:
  float x_;
  float y_;
  float z_;
  int32_t __padding0;
  double test1_;
  int8_t test2_;
  int8_t __padding1;
  Test test3_;
  int16_t __padding2;

 public:
  Vec3(float x, float y, float z, double test1, int8_t test2, const Test &test3)
    : x_(flatbuffers::EndianScalar(x)), y_(flatbuffers::EndianScalar(y)), z_(flatbuffers::EndianScalar(z)), __padding0(0), test1_(flatbuffers::EndianScalar(test1)), test2_(flatbuffers::EndianScalar(test2)), __padding1(0), test3_(test3), __padding2(0) {}

  float x() const { return flatbuffers::EndianScalar(x_); }
  float y() const { return flatbuffers::EndianScalar(y_); }
  float z() const { return flatbuffers::EndianScalar(z_); }
  double test1() const { return flatbuffers::EndianScalar(test1_); }
  int8_t test2() const { return flatbuffers::EndianScalar(test2_); }
  const Test &test3() const { return test3_; }
};
STRUCT_END(Vec3, 32);

struct Monster : private flatbuffers::Table {
  const Vec3 *pos() const { return GetStruct<const Vec3 *>(4); }
  int16_t mana() const { return GetField<int16_t>(6, 150); }
  int16_t hp() const { return GetField<int16_t>(8, 100); }
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(10); }
  const flatbuffers::Vector<uint8_t> *inventory() const { return GetPointer<const flatbuffers::Vector<uint8_t> *>(14); }
  int8_t color() const { return GetField<int8_t>(16, 8); }
  uint8_t test_type() const { return GetField<uint8_t>(18, 0); }
  const void *test() const { return GetPointer<const void *>(20); }
  const flatbuffers::Vector<const Test *> *test4() const { return GetPointer<const flatbuffers::Vector<const Test *> *>(22); }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *testarrayofstring() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(24); }
  /// an example documentation comment: this will end up in the generated code multiline too
  const flatbuffers::Vector<flatbuffers::Offset<Monster>> *testarrayoftables() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Monster>> *>(26); }
  const Monster *enemy() const { return GetPointer<const Monster *>(28); }
  const flatbuffers::Vector<uint8_t> *testnestedflatbuffer() const { return GetPointer<const flatbuffers::Vector<uint8_t> *>(30); }
  const Monster *testnestedflatbuffer_nested_root() { return flatbuffers::GetRoot<Monster>(testnestedflatbuffer()->Data()); }
  bool Verify(const flatbuffers::Verifier &verifier) const {
    return VerifyTable(verifier) &&
           VerifyField<Vec3>(verifier, 4 /* pos */) &&
           VerifyField<int16_t>(verifier, 6 /* mana */) &&
           VerifyField<int16_t>(verifier, 8 /* hp */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 10 /* name */) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 14 /* inventory */) &&
           verifier.Verify(inventory()) &&
           VerifyField<int8_t>(verifier, 16 /* color */) &&
           VerifyField<uint8_t>(verifier, 18 /* test_type */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 20 /* test */) &&
           VerifyAny(verifier, test(), test_type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 22 /* test4 */) &&
           verifier.Verify(test4()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 24 /* testarrayofstring */) &&
           verifier.Verify(testarrayofstring()) &&
           verifier.VerifyVectorOfStrings(testarrayofstring()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 26 /* testarrayoftables */) &&
           verifier.Verify(testarrayoftables()) &&
           verifier.VerifyVectorOfTables(testarrayoftables()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 28 /* enemy */) &&
           verifier.VerifyTable(enemy()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 30 /* testnestedflatbuffer */) &&
           verifier.Verify(testnestedflatbuffer());
  }
};

struct MonsterBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pos(const Vec3 *pos) { fbb_.AddStruct(4, pos); }
  void add_mana(int16_t mana) { fbb_.AddElement<int16_t>(6, mana, 150); }
  void add_hp(int16_t hp) { fbb_.AddElement<int16_t>(8, hp, 100); }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(10, name); }
  void add_inventory(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory) { fbb_.AddOffset(14, inventory); }
  void add_color(int8_t color) { fbb_.AddElement<int8_t>(16, color, 8); }
  void add_test_type(uint8_t test_type) { fbb_.AddElement<uint8_t>(18, test_type, 0); }
  void add_test(flatbuffers::Offset<void> test) { fbb_.AddOffset(20, test); }
  void add_test4(flatbuffers::Offset<flatbuffers::Vector<const Test *>> test4) { fbb_.AddOffset(22, test4); }
  void add_testarrayofstring(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> testarrayofstring) { fbb_.AddOffset(24, testarrayofstring); }
  void add_testarrayoftables(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Monster>>> testarrayoftables) { fbb_.AddOffset(26, testarrayoftables); }
  void add_enemy(flatbuffers::Offset<Monster> enemy) { fbb_.AddOffset(28, enemy); }
  void add_testnestedflatbuffer(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> testnestedflatbuffer) { fbb_.AddOffset(30, testnestedflatbuffer); }
  MonsterBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  MonsterBuilder &operator=(const MonsterBuilder &);
  flatbuffers::Offset<Monster> Finish() { return flatbuffers::Offset<Monster>(fbb_.EndTable(start_, 14)); }
};

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb,
   const Vec3 *pos = 0,
   int16_t mana = 150,
   int16_t hp = 100,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory = 0,
   int8_t color = 8,
   uint8_t test_type = 0,
   flatbuffers::Offset<void> test = 0,
   flatbuffers::Offset<flatbuffers::Vector<const Test *>> test4 = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> testarrayofstring = 0,
   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Monster>>> testarrayoftables = 0,
   flatbuffers::Offset<Monster> enemy = 0,
   flatbuffers::Offset<flatbuffers::Vector<uint8_t>> testnestedflatbuffer = 0) {
  MonsterBuilder builder_(_fbb);
  builder_.add_testnestedflatbuffer(testnestedflatbuffer);
  builder_.add_enemy(enemy);
  builder_.add_testarrayoftables(testarrayoftables);
  builder_.add_testarrayofstring(testarrayofstring);
  builder_.add_test4(test4);
  builder_.add_test(test);
  builder_.add_inventory(inventory);
  builder_.add_name(name);
  builder_.add_pos(pos);
  builder_.add_hp(hp);
  builder_.add_mana(mana);
  builder_.add_test_type(test_type);
  builder_.add_color(color);
  return builder_.Finish();
}

bool VerifyAny(const flatbuffers::Verifier &verifier, const void *union_obj, uint8_t type) {
  switch (type) {
    case Any_NONE: return true;
    case Any_Monster: return verifier.VerifyTable(reinterpret_cast<const Monster *>(union_obj));
    default: return false;
  }
}

inline const Monster *GetMonster(const void *buf) { return flatbuffers::GetRoot<Monster>(buf); }

inline bool VerifyMonsterBuffer(const flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<Monster>(); }

inline void FinishMonsterBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<Monster> root) { fbb.Finish(root, "MONS"); }

inline bool MonsterBufferHasIdentifier(const void *buf) { return flatbuffers::BufferHasIdentifier(buf, "MONS"); }

}  // namespace Example
}  // namespace MyGame

#endif  // FLATBUFFERS_GENERATED_MONSTER_TEST_MYGAME_EXAMPLE_H_
