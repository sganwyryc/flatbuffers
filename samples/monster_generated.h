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
  static const char *names[] = {
    "Red",
    "Green",
    "Blue",
    nullptr
  };
  return names;
}

inline const char *EnumNameColor(Color e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesColor()[index];
}

enum Equipment {
  Equipment_NONE = 0,
  Equipment_Weapon = 1,
  Equipment_MIN = Equipment_NONE,
  Equipment_MAX = Equipment_Weapon
};

inline const char **EnumNamesEquipment() {
  static const char *names[] = {
    "NONE",
    "Weapon",
    nullptr
  };
  return names;
}

inline const char *EnumNameEquipment(Equipment e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesEquipment()[index];
}

template<typename T> struct EquipmentTraits {
  static const Equipment enum_value = Equipment_NONE;
};

template<> struct EquipmentTraits<Weapon> {
  static const Equipment enum_value = Equipment_Weapon;
};

struct EquipmentUnion {
  Equipment type;
  flatbuffers::NativeTable *table;

  EquipmentUnion() : type(Equipment_NONE), table(nullptr) {}
  EquipmentUnion(const EquipmentUnion &);
  EquipmentUnion &operator=(const EquipmentUnion &);
  ~EquipmentUnion() { Reset(); }

  void Reset();

  template <typename T>
  void Set(T&& value) {
    Reset();
    type = EquipmentTraits<typename T::TableType>::enum_value;
    if (type != Equipment_NONE) {
      table = new T(std::forward<T>(value));
    }
  }

  static flatbuffers::NativeTable *UnPack(const void *obj, Equipment type, const flatbuffers::resolver_function_t *resolver);
  flatbuffers::Offset<void> Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *_rehasher = nullptr) const;

  WeaponT *AsWeapon() {
    return type == Equipment_Weapon ?
      reinterpret_cast<WeaponT *>(table) : nullptr;
  }
};

bool VerifyEquipment(flatbuffers::Verifier &verifier, const void *obj, Equipment type);

MANUALLY_ALIGNED_STRUCT(4) Vec3 FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;
  float z_;

 public:
  Vec3() {
    memset(this, 0, sizeof(Vec3));
  }
  Vec3(const Vec3 &_o) {
    memcpy(this, &_o, sizeof(Vec3));
  }
  Vec3(float _x, float _y, float _z)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)),
        z_(flatbuffers::EndianScalar(_z)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  void mutate_x(float _x) {
    flatbuffers::WriteScalar(&x_, _x);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
  void mutate_y(float _y) {
    flatbuffers::WriteScalar(&y_, _y);
  }
  float z() const {
    return flatbuffers::EndianScalar(z_);
  }
  void mutate_z(float _z) {
    flatbuffers::WriteScalar(&z_, _z);
  }
};
STRUCT_END(Vec3, 12);

struct MonsterT : public flatbuffers::NativeTable {
  typedef Monster TableType;
  std::unique_ptr<Vec3> pos;
  int16_t mana;
  int16_t hp;
  std::string name;
  std::vector<uint8_t> inventory;
  Color color;
  std::vector<std::unique_ptr<WeaponT>> weapons;
  EquipmentUnion equipped;
  MonsterT()
      : mana(150),
        hp(100),
        color(Color_Blue) {
  }
};

struct Monster FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MonsterT NativeTableType;
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
  const Vec3 *pos() const {
    return GetStruct<const Vec3 *>(VT_POS);
  }
  Vec3 *mutable_pos() {
    return GetStruct<Vec3 *>(VT_POS);
  }
  int16_t mana() const {
    return GetField<int16_t>(VT_MANA, 150);
  }
  bool mutate_mana(int16_t _mana) {
    return SetField(VT_MANA, _mana);
  }
  int16_t hp() const {
    return GetField<int16_t>(VT_HP, 100);
  }
  bool mutate_hp(int16_t _hp) {
    return SetField(VT_HP, _hp);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  flatbuffers::String *mutable_name() {
    return GetPointer<flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<uint8_t> *inventory() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_INVENTORY);
  }
  flatbuffers::Vector<uint8_t> *mutable_inventory() {
    return GetPointer<flatbuffers::Vector<uint8_t> *>(VT_INVENTORY);
  }
  Color color() const {
    return static_cast<Color>(GetField<int8_t>(VT_COLOR, 2));
  }
  bool mutate_color(Color _color) {
    return SetField(VT_COLOR, static_cast<int8_t>(_color));
  }
  const flatbuffers::Vector<flatbuffers::Offset<Weapon>> *weapons() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Weapon>> *>(VT_WEAPONS);
  }
  flatbuffers::Vector<flatbuffers::Offset<Weapon>> *mutable_weapons() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<Weapon>> *>(VT_WEAPONS);
  }
  Equipment equipped_type() const {
    return static_cast<Equipment>(GetField<uint8_t>(VT_EQUIPPED_TYPE, 0));
  }
  bool mutate_equipped_type(Equipment _equipped_type) {
    return SetField(VT_EQUIPPED_TYPE, static_cast<uint8_t>(_equipped_type));
  }
  const void *equipped() const {
    return GetPointer<const void *>(VT_EQUIPPED);
  }
  void *mutable_equipped() {
    return GetPointer<void *>(VT_EQUIPPED);
  }
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
  MonsterT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(MonsterT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Monster> Pack(flatbuffers::FlatBufferBuilder &_fbb, const MonsterT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct MonsterBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pos(const Vec3 *pos) {
    fbb_.AddStruct(Monster::VT_POS, pos);
  }
  void add_mana(int16_t mana) {
    fbb_.AddElement<int16_t>(Monster::VT_MANA, mana, 150);
  }
  void add_hp(int16_t hp) {
    fbb_.AddElement<int16_t>(Monster::VT_HP, hp, 100);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Monster::VT_NAME, name);
  }
  void add_inventory(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory) {
    fbb_.AddOffset(Monster::VT_INVENTORY, inventory);
  }
  void add_color(Color color) {
    fbb_.AddElement<int8_t>(Monster::VT_COLOR, static_cast<int8_t>(color), 2);
  }
  void add_weapons(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Weapon>>> weapons) {
    fbb_.AddOffset(Monster::VT_WEAPONS, weapons);
  }
  void add_equipped_type(Equipment equipped_type) {
    fbb_.AddElement<uint8_t>(Monster::VT_EQUIPPED_TYPE, static_cast<uint8_t>(equipped_type), 0);
  }
  void add_equipped(flatbuffers::Offset<void> equipped) {
    fbb_.AddOffset(Monster::VT_EQUIPPED, equipped);
  }
  MonsterBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MonsterBuilder &operator=(const MonsterBuilder &);
  flatbuffers::Offset<Monster> Finish() {
    const auto end = fbb_.EndTable(start_, 10);
    auto o = flatbuffers::Offset<Monster>(end);
    return o;
  }
};

inline flatbuffers::Offset<Monster> CreateMonster(
    flatbuffers::FlatBufferBuilder &_fbb,
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

inline flatbuffers::Offset<Monster> CreateMonsterDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Vec3 *pos = 0,
    int16_t mana = 150,
    int16_t hp = 100,
    const char *name = nullptr,
    const std::vector<uint8_t> *inventory = nullptr,
    Color color = Color_Blue,
    const std::vector<flatbuffers::Offset<Weapon>> *weapons = nullptr,
    Equipment equipped_type = Equipment_NONE,
    flatbuffers::Offset<void> equipped = 0) {
  return CreateMonster(
      _fbb,
      pos,
      mana,
      hp,
      name ? _fbb.CreateString(name) : 0,
      inventory ? _fbb.CreateVector<uint8_t>(*inventory) : 0,
      color,
      weapons ? _fbb.CreateVector<flatbuffers::Offset<Weapon>>(*weapons) : 0,
      equipped_type,
      equipped);
}

flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb, const MonsterT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct WeaponT : public flatbuffers::NativeTable {
  typedef Weapon TableType;
  std::string name;
  int16_t damage;
  WeaponT()
      : damage(0) {
  }
};

struct Weapon FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef WeaponT NativeTableType;
  enum {
    VT_NAME = 4,
    VT_DAMAGE = 6
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  flatbuffers::String *mutable_name() {
    return GetPointer<flatbuffers::String *>(VT_NAME);
  }
  int16_t damage() const {
    return GetField<int16_t>(VT_DAMAGE, 0);
  }
  bool mutate_damage(int16_t _damage) {
    return SetField(VT_DAMAGE, _damage);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<int16_t>(verifier, VT_DAMAGE) &&
           verifier.EndTable();
  }
  WeaponT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(WeaponT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Weapon> Pack(flatbuffers::FlatBufferBuilder &_fbb, const WeaponT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct WeaponBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Weapon::VT_NAME, name);
  }
  void add_damage(int16_t damage) {
    fbb_.AddElement<int16_t>(Weapon::VT_DAMAGE, damage, 0);
  }
  WeaponBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WeaponBuilder &operator=(const WeaponBuilder &);
  flatbuffers::Offset<Weapon> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Weapon>(end);
    return o;
  }
};

inline flatbuffers::Offset<Weapon> CreateWeapon(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int16_t damage = 0) {
  WeaponBuilder builder_(_fbb);
  builder_.add_name(name);
  builder_.add_damage(damage);
  return builder_.Finish();
}

inline flatbuffers::Offset<Weapon> CreateWeaponDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int16_t damage = 0) {
  return CreateWeapon(
      _fbb,
      name ? _fbb.CreateString(name) : 0,
      damage);
}

flatbuffers::Offset<Weapon> CreateWeapon(flatbuffers::FlatBufferBuilder &_fbb, const WeaponT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline MonsterT *Monster::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new MonsterT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Monster::UnPackTo(MonsterT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = pos(); if (_e) _o->pos = std::unique_ptr<Vec3>(new Vec3(*_e)); };
  { auto _e = mana(); _o->mana = _e; };
  { auto _e = hp(); _o->hp = _e; };
  { auto _e = name(); if (_e) _o->name = _e->str(); };
  { auto _e = inventory(); if (_e) for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->inventory.push_back(_e->Get(_i)); } };
  { auto _e = color(); _o->color = _e; };
  { auto _e = weapons(); if (_e) for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->weapons.push_back(std::unique_ptr<WeaponT>(_e->Get(_i)->UnPack(_resolver))); } };
  { auto _e = equipped_type(); _o->equipped.type = _e; };
  { auto _e = equipped(); if (_e) _o->equipped.table = EquipmentUnion::UnPack(_e, equipped_type(),_resolver); };
}

inline flatbuffers::Offset<Monster> Monster::Pack(flatbuffers::FlatBufferBuilder &_fbb, const MonsterT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateMonster(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Monster> CreateMonster(flatbuffers::FlatBufferBuilder &_fbb, const MonsterT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  auto _pos = _o->pos ? _o->pos.get() : 0;
  auto _mana = _o->mana;
  auto _hp = _o->hp;
  auto _name = _o->name.size() ? _fbb.CreateString(_o->name) : 0;
  auto _inventory = _o->inventory.size() ? _fbb.CreateVector(_o->inventory) : 0;
  auto _color = _o->color;
  auto _weapons = _o->weapons.size() ? _fbb.CreateVector<flatbuffers::Offset<Weapon>>(_o->weapons.size(), [&](size_t i) { return CreateWeapon(_fbb, _o->weapons[i].get(), _rehasher); }) : 0;
  auto _equipped_type = _o->equipped.type;
  auto _equipped = _o->equipped.Pack(_fbb);
  return CreateMonster(
      _fbb,
      _pos,
      _mana,
      _hp,
      _name,
      _inventory,
      _color,
      _weapons,
      _equipped_type,
      _equipped);
}

inline WeaponT *Weapon::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new WeaponT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Weapon::UnPackTo(WeaponT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = name(); if (_e) _o->name = _e->str(); };
  { auto _e = damage(); _o->damage = _e; };
}

inline flatbuffers::Offset<Weapon> Weapon::Pack(flatbuffers::FlatBufferBuilder &_fbb, const WeaponT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateWeapon(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Weapon> CreateWeapon(flatbuffers::FlatBufferBuilder &_fbb, const WeaponT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  auto _name = _o->name.size() ? _fbb.CreateString(_o->name) : 0;
  auto _damage = _o->damage;
  return CreateWeapon(
      _fbb,
      _name,
      _damage);
}

inline bool VerifyEquipment(flatbuffers::Verifier &verifier, const void *obj, Equipment type) {
  switch (type) {
    case Equipment_NONE: {
      return true;
    }
    case Equipment_Weapon: {
      auto ptr = reinterpret_cast<const Weapon *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline flatbuffers::NativeTable *EquipmentUnion::UnPack(const void *obj, Equipment type, const flatbuffers::resolver_function_t *resolver) {
  switch (type) {
    case Equipment_Weapon: {
      auto ptr = reinterpret_cast<const Weapon *>(obj);
      return ptr->UnPack(resolver);
    }
    default: return nullptr;
  }
}

inline flatbuffers::Offset<void> EquipmentUnion::Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *_rehasher) const {
  switch (type) {
    case Equipment_Weapon: {
      auto ptr = reinterpret_cast<const WeaponT *>(table);
      return CreateWeapon(_fbb, ptr, _rehasher).Union();
    }
    default: return 0;
  }
}

inline void EquipmentUnion::Reset() {
  switch (type) {
    case Equipment_Weapon: {
      auto ptr = reinterpret_cast<WeaponT *>(table);
      delete ptr;
      break;
    }
    default: break;
  }
  table = nullptr;
  type = Equipment_NONE;
}

inline const MyGame::Sample::Monster *GetMonster(const void *buf) {
  return flatbuffers::GetRoot<MyGame::Sample::Monster>(buf);
}

inline Monster *GetMutableMonster(void *buf) {
  return flatbuffers::GetMutableRoot<Monster>(buf);
}

inline bool VerifyMonsterBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<MyGame::Sample::Monster>(nullptr);
}

inline void FinishMonsterBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<MyGame::Sample::Monster> root) {
  fbb.Finish(root);
}

inline std::unique_ptr<MonsterT> UnPackMonster(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<MonsterT>(GetMonster(buf)->UnPack(res));
}

}  // namespace Sample
}  // namespace MyGame

#endif  // FLATBUFFERS_GENERATED_MONSTER_MYGAME_SAMPLE_H_
