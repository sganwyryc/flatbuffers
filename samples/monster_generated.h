// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_
#define FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_

#include "flatbuffers/flatbuffers.h"

namespace MyGame {
namespace Sample {

struct Vec3;

struct Monster;
struct MonsterT;

struct Weapon;
struct WeaponT;

enum Color {
  Color_Red = 0,
  Color_Green = 1,
  Color_Blue = 2,
  Color_MIN = Color_Red,
  Color_MAX = Color_Blue
};

inline const char **EnumNamesColor() {
  static const char *names[] = { "Red", "Green", "Blue", nullptr };
  return names;
}

inline const char *EnumNameColor(Color e) { return EnumNamesColor()[static_cast<int>(e)]; }

enum Equipment {
  Equipment_NONE = 0,
  Equipment_Weapon = 1,
  Equipment_MIN = Equipment_NONE,
  Equipment_MAX = Equipment_Weapon
};

struct EquipmentUnion {
  Equipment type;

  flatbuffers::NativeTable *table;
  EquipmentUnion() : type(Equipment_NONE), table(nullptr) {}
  EquipmentUnion(const EquipmentUnion &);
  EquipmentUnion &operator=(const EquipmentUnion &);
  ~EquipmentUnion();

  static flatbuffers::NativeTable *UnPack(const void *union_obj, Equipment type);
  flatbuffers::Offset<void> Pack(flatbuffers::FlatBufferBuilder &_fbb) const;

  WeaponT *AsWeapon() { return type == Equipment_Weapon ? reinterpret_cast<WeaponT *>(table) : nullptr; }
};

inline const char **EnumNamesEquipment() {
  static const char *names[] = { "NONE", "Weapon", nullptr };
  return names;
}

inline const char *EnumNameEquipment(Equipment e) { return EnumNamesEquipment()[static_cast<int>(e)]; }

inline bool VerifyEquipment(flatbuffers::Verifier &verifier, const void *union_obj, Equipment type);

MANUALLY_ALIGNED_STRUCT(4) Vec3 FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;
  float z_;

 public:
  Vec3() { memset(this, 0, sizeof(Vec3)); }
  Vec3(const Vec3 &_o) { memcpy(this, &_o, sizeof(Vec3)); }
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

struct MonsterT : public flatbuffers::NativeTable {
  std::unique_ptr<Vec3> pos;
  int16_t mana;
  int16_t hp;
  std::string name;
  std::vector<uint8_t> inventory;
  Color color;
  std::vector<std::unique_ptr<WeaponT>> weapons;
  EquipmentUnion equipped;
};

struct Monster FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_POS = 4,
    VT_MANA = 6,
    VT_HP = 8,
    VT_NAME = 10,
    VT_INVENTORY = 14,
    VT_COLOR = 16,
    VT_WEAPONS = 18,
    VT_EQUIPPED_TYPE = 20,
    VT_EQUIPPED = 22
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
  const flatbuffers::Vector<flatbuffers::Offset<Weapon>> *weapons() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Weapon>> *>(VT_WEAPONS); }
  flatbuffers::Vector<flatbuffers::Offset<Weapon>> *mutable_weapons() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<Weapon>> *>(VT_WEAPONS); }
  Equipment equipped_type() const { return static_cast<Equipment>(GetField<uint8_t>(VT_EQUIPPED_TYPE, 0)); }
  bool mutate_equipped_type(Equipment _equipped_type) { return SetField(VT_EQUIPPED_TYPE, static_cast<uint8_t>(_equipped_type)); }
  const void *equipped() const { return GetPointer<const void *>(VT_EQUIPPED); }
  void *mutable_equipped() { return GetPointer<void *>(VT_EQUIPPED); }
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
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_WEAPONS) &&
           verifier.Verify(weapons()) &&
           verifier.VerifyVectorOfTables(weapons()) &&
           VerifyField<uint8_t>(verifier, VT_EQUIPPED_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_EQUIPPED) &&
           VerifyEquipment(verifier, equipped(), equipped_type()) &&
           verifier.EndTable();
  }
  std::unique_ptr<MonsterT> UnPack() const;
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
  void add_weapons(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Weapon>>> weapons) { fbb_.AddOffset(Monster::VT_WEAPONS, weapons); }
  void add_equipped_type(Equipment equipped_type) { fbb_.AddElement<uint8_t>(Monster::VT_EQUIPPED_TYPE, static_cast<uint8_t>(equipped_type), 0); }
  void add_equipped(flatbuffers::Offset<void> equipped) { fbb_.AddOffset(Monster::VT_EQUIPPED, equipped); }
  MonsterBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  MonsterBuilder &operator=(const MonsterBuilder &);
  flatbuffers::Offset<Monster> Finish() {
    auto o = flatbuffers::Offset<Monster>(fbb_.EndTable(start_, 10));
    return o;
  }
};

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb,
    const Vec3 *pos = 0,
    int16_t mana = 150,
    int16_t hp = 100,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory = 0,
    Color color = Color_Blue,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Weapon>>> weapons = 0,
    Equipment equipped_type = Equipment_NONE,
    flatbuffers::Offset<void> equipped = 0) {
  MonsterBuilder builder_(_fbb);
  builder_.add_equipped(equipped);
  builder_.add_weapons(weapons);
  builder_.add_inventory(inventory);
  builder_.add_name(name);
  builder_.add_pos(pos);
  builder_.add_hp(hp);
  builder_.add_mana(mana);
  builder_.add_equipped_type(equipped_type);
  builder_.add_color(color);
  return builder_.Finish();
}

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb,
    const Vec3 *pos = 0,
    int16_t mana = 150,
    int16_t hp = 100,
    const char *name = nullptr,
    const std::vector<uint8_t> *inventory = nullptr,
    Color color = Color_Blue,
    const std::vector<flatbuffers::Offset<Weapon>> *weapons = nullptr,
    Equipment equipped_type = Equipment_NONE,
    flatbuffers::Offset<void> equipped = 0) {
  return CreateMonster(_fbb, pos, mana, hp, name ? 0 : _fbb.CreateString(name), inventory ? 0 : _fbb.CreateVector<uint8_t>(*inventory), color, weapons ? 0 : _fbb.CreateVector<flatbuffers::Offset<Weapon>>(*weapons), equipped_type, equipped);
}

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb, const MonsterT *_o);

struct WeaponT : public flatbuffers::NativeTable {
  std::string name;
  int16_t damage;
};

struct Weapon FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_DAMAGE = 6
  };
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }
  flatbuffers::String *mutable_name() { return GetPointer<flatbuffers::String *>(VT_NAME); }
  int16_t damage() const { return GetField<int16_t>(VT_DAMAGE, 0); }
  bool mutate_damage(int16_t _damage) { return SetField(VT_DAMAGE, _damage); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<int16_t>(verifier, VT_DAMAGE) &&
           verifier.EndTable();
  }
  std::unique_ptr<WeaponT> UnPack() const;
};

struct WeaponBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Weapon::VT_NAME, name); }
  void add_damage(int16_t damage) { fbb_.AddElement<int16_t>(Weapon::VT_DAMAGE, damage, 0); }
  WeaponBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  WeaponBuilder &operator=(const WeaponBuilder &);
  flatbuffers::Offset<Weapon> Finish() {
    auto o = flatbuffers::Offset<Weapon>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<Weapon> CreateWeapon(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int16_t damage = 0) {
  WeaponBuilder builder_(_fbb);
  builder_.add_name(name);
  builder_.add_damage(damage);
  return builder_.Finish();
}

inline flatbuffers::Offset<Weapon> CreateWeapon(flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int16_t damage = 0) {
  return CreateWeapon(_fbb, name ? 0 : _fbb.CreateString(name), damage);
}

inline flatbuffers::Offset<Weapon> CreateWeapon(flatbuffers::FlatBufferBuilder &_fbb, const WeaponT *_o);

inline std::unique_ptr<MonsterT> Monster::UnPack() const {
  auto _o = new MonsterT();
  { auto _e = pos(); if (_e) _o->pos = std::unique_ptr<Vec3>(new Vec3(*_e)); };
  { auto _e = mana(); _o->mana = _e; };
  { auto _e = hp(); _o->hp = _e; };
  { auto _e = name(); if (_e) _o->name = _e->str(); };
  { auto _e = inventory(); if (_e) { for (size_t _i = 0; _i < _e->size(); _i++) { _o->inventory.push_back(_e->Get(_i)); } } };
  { auto _e = color(); _o->color = _e; };
  { auto _e = weapons(); if (_e) { for (size_t _i = 0; _i < _e->size(); _i++) { _o->weapons.push_back(_e->Get(_i)->UnPack()); } } };
  { auto _e = equipped_type(); _o->equipped.type = _e; };
  { auto _e = equipped(); if (_e) _o->equipped.table = EquipmentUnion::UnPack(_e, equipped_type()); };
  return std::unique_ptr<MonsterT>(_o);
}

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb, const MonsterT *_o) {
  return CreateMonster(_fbb,
    _o->pos ? _o->pos.get() : 0,
    _o->mana,
    _o->hp,
    _o->name.size() ? _fbb.CreateString(_o->name) : 0,
    _o->inventory.size() ? _fbb.CreateVector(_o->inventory) : 0,
    _o->color,
    _o->weapons.size() ? _fbb.CreateVector<flatbuffers::Offset<Weapon>>(_o->weapons.size(), [&](size_t i) { return CreateWeapon(_fbb, _o->weapons[i].get()); }) : 0,
    _o->equipped.type,
    _o->equipped.Pack(_fbb));
}

inline std::unique_ptr<WeaponT> Weapon::UnPack() const {
  auto _o = new WeaponT();
  { auto _e = name(); if (_e) _o->name = _e->str(); };
  { auto _e = damage(); _o->damage = _e; };
  return std::unique_ptr<WeaponT>(_o);
}

inline flatbuffers::Offset<Weapon> CreateWeapon(flatbuffers::FlatBufferBuilder &_fbb, const WeaponT *_o) {
  return CreateWeapon(_fbb,
    _o->name.size() ? _fbb.CreateString(_o->name) : 0,
    _o->damage);
}

inline bool VerifyEquipment(flatbuffers::Verifier &verifier, const void *union_obj, Equipment type) {
  switch (type) {
    case Equipment_NONE: return true;
    case Equipment_Weapon: return verifier.VerifyTable(reinterpret_cast<const Weapon *>(union_obj));
    default: return false;
  }
}

inline flatbuffers::NativeTable *EquipmentUnion::UnPack(const void *union_obj, Equipment type) {
  switch (type) {
    case Equipment_NONE: return nullptr;
    case Equipment_Weapon: return reinterpret_cast<const Weapon *>(union_obj)->UnPack().release();
    default: return nullptr;
  }
}

inline flatbuffers::Offset<void> EquipmentUnion::Pack(flatbuffers::FlatBufferBuilder &_fbb) const {
  switch (type) {
    case Equipment_NONE: return 0;
    case Equipment_Weapon: return CreateWeapon(_fbb, reinterpret_cast<const WeaponT *>(table)).Union();
    default: return 0;
  }
}

inline EquipmentUnion::~EquipmentUnion() {
  switch (type) {
    case Equipment_Weapon: delete reinterpret_cast<WeaponT *>(table); break;
    default:;
  }
}

inline const MyGame::Sample::Monster *GetMonster(const void *buf) { return flatbuffers::GetRoot<MyGame::Sample::Monster>(buf); }

inline Monster *GetMutableMonster(void *buf) { return flatbuffers::GetMutableRoot<Monster>(buf); }

inline bool VerifyMonsterBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<MyGame::Sample::Monster>(nullptr); }

inline void FinishMonsterBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<MyGame::Sample::Monster> root) { fbb.Finish(root); }

}  // namespace Sample
}  // namespace MyGame

#endif  // FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_
