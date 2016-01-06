// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_
#define FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_

#include "flatbuffers/flatbuffers.h"


namespace MyGame {
namespace Sample {

struct Vec3;
struct Monster;

enum Color {
  Color_Red = 0,
  Color_Green = 1,
  Color_Blue = 2
};

inline const char **EnumNamesColor() {
  static const char *names[] = { "Red", "Green", "Blue", nullptr };
  return names;
}

inline const char *EnumNameColor(Color e) { return EnumNamesColor()[static_cast<int>(e)]; }

enum Any {
  Any_NONE = 0,
  Any_Monster = 1
};

inline const char **EnumNamesAny() {
  static const char *names[] = { "NONE", "Monster", nullptr };
  return names;
}

inline const char *EnumNameAny(Any e) { return EnumNamesAny()[static_cast<int>(e)]; }

inline bool VerifyAny(flatbuffers::Verifier &verifier, const void *union_obj, Any type);

MANUALLY_ALIGNED_STRUCT(4) Vec3 FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;
  float z_;

 public:
  Vec3(float _x, float _y, float _z)
    : x_(flatbuffers::EndianScalar(_x)), y_(flatbuffers::EndianScalar(_y)), z_(flatbuffers::EndianScalar(_z)) { }

  float x() const { return flatbuffers::EndianScalar(x_); }
  void mutate_x(float _x) { flatbuffers::WriteScalar(&x_, _x); }
  float y() const { return flatbuffers::EndianScalar(y_); }
  void mutate_y(float _y) { flatbuffers::WriteScalar(&y_, _y); }
  float z() const { return flatbuffers::EndianScalar(z_); }
  void mutate_z(float _z) { flatbuffers::WriteScalar(&z_, _z); }
};
STRUCT_END(Vec3, 12);

struct Monster FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_POS = 4,
    VT_MANA = 6,
    VT_HP = 8,
    VT_NAME = 10,
    VT_INVENTORY = 14,
    VT_COLOR = 16
  };
  const Vec3 *pos() const { return GetStruct<const Vec3 *>(VT_POS); }
  Vec3 *mutable_pos() { return GetStruct<Vec3 *>(VT_POS); }
  int16_t mana() const { return GetField<int16_t>(VT_MANA, 150); }
  bool mutate_mana(int16_t _mana) { return SetField(VT_MANA, _mana); }
  int16_t hp() const { return GetField<int16_t>(VT_HP, 100); }
  bool mutate_hp(int16_t _hp) { return SetField(VT_HP, _hp); }
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }
  flatbuffers::String *mutable_name() { return GetPointer<flatbuffers::String *>(VT_NAME); }
  const flatbuffers::Vector<uint8_t> *inventory() const { return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_INVENTORY); }
  flatbuffers::Vector<uint8_t> *mutable_inventory() { return GetPointer<flatbuffers::Vector<uint8_t> *>(VT_INVENTORY); }
  Color color() const { return static_cast<Color>(GetField<int8_t>(VT_COLOR, 2)); }
  bool mutate_color(Color _color) { return SetField(VT_COLOR, static_cast<int8_t>(_color)); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<Vec3>(verifier, VT_POS) &&
           VerifyField<int16_t>(verifier, VT_MANA) &&
           VerifyField<int16_t>(verifier, VT_HP) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_INVENTORY) &&
           verifier.Verify(inventory()) &&
           VerifyField<int8_t>(verifier, VT_COLOR) &&
           verifier.EndTable();
  }
};

struct MonsterBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pos(const Vec3 *pos) { fbb_.AddStruct(Monster::VT_POS, pos); }
  void add_mana(int16_t mana) { fbb_.AddElement<int16_t>(Monster::VT_MANA, mana, 150); }
  void add_hp(int16_t hp) { fbb_.AddElement<int16_t>(Monster::VT_HP, hp, 100); }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Monster::VT_NAME, name); }
  void add_inventory(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory) { fbb_.AddOffset(Monster::VT_INVENTORY, inventory); }
  void add_color(Color color) { fbb_.AddElement<int8_t>(Monster::VT_COLOR, static_cast<int8_t>(color), 2); }
  MonsterBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  MonsterBuilder &operator=(const MonsterBuilder &);
  flatbuffers::Offset<Monster> Finish() {
    auto o = flatbuffers::Offset<Monster>(fbb_.EndTable(start_, 7));
    return o;
  }
};

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb,
   const Vec3 *pos = 0,
   int16_t mana = 150,
   int16_t hp = 100,
   flatbuffers::Offset<flatbuffers::String> name = 0,
   flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory = 0,
   Color color = Color_Blue) {
  MonsterBuilder builder_(_fbb);
  builder_.add_inventory(inventory);
  builder_.add_name(name);
  builder_.add_pos(pos);
  builder_.add_hp(hp);
  builder_.add_mana(mana);
  builder_.add_color(color);
  return builder_.Finish();
}

inline bool VerifyAny(flatbuffers::Verifier &verifier, const void *union_obj, Any type) {
  switch (type) {
    case Any_NONE: return true;
    case Any_Monster: return verifier.VerifyTable(reinterpret_cast<const Monster *>(union_obj));
    default: return false;
  }
}

inline const MyGame::Sample::Monster *GetMonster(const void *buf) { return flatbuffers::GetRoot<MyGame::Sample::Monster>(buf); }

inline Monster *GetMutableMonster(void *buf) { return flatbuffers::GetMutableRoot<Monster>(buf); }

inline bool VerifyMonsterBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<MyGame::Sample::Monster>(); }

inline void FinishMonsterBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<MyGame::Sample::Monster> root) { fbb.Finish(root); }

}  // namespace Sample
}  // namespace MyGame

#endif  // FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_
