// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_UNIONVECTOR_H_
#define FLATBUFFERS_GENERATED_UNIONVECTOR_H_

#include "flatbuffers/flatbuffers.h"

struct Attacker;
struct AttackerT;

struct Rapunzel;

struct BookReader;

struct Movie;
struct MovieT;

enum Character {
  Character_NONE = 0,
  Character_MuLan = 1,
  Character_Rapunzel = 2,
  Character_Belle = 3,
  Character_BookFan = 4,
  Character_Other = 5,
  Character_Unused = 6,
  Character_MIN = Character_NONE,
  Character_MAX = Character_Unused
};

inline Character (&EnumValuesCharacter())[7] {
  static Character values[] = {
    Character_NONE,
    Character_MuLan,
    Character_Rapunzel,
    Character_Belle,
    Character_BookFan,
    Character_Other,
    Character_Unused
  };
  return values;
}

inline const char **EnumNamesCharacter() {
  static const char *names[] = {
    "NONE",
    "MuLan",
    "Rapunzel",
    "Belle",
    "BookFan",
    "Other",
    "Unused",
    nullptr
  };
  return names;
}

inline const char *EnumNameCharacter(Character e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesCharacter()[index];
}

struct CharacterUnion {
  Character type;
  void *value;

  CharacterUnion() : type(Character_NONE), value(nullptr) {}
  CharacterUnion(CharacterUnion&& u) FLATBUFFERS_NOEXCEPT :
    type(Character_NONE), value(nullptr)
    { std::swap(type, u.type); std::swap(value, u.value); }
  CharacterUnion(const CharacterUnion &) FLATBUFFERS_NOEXCEPT;
  CharacterUnion &operator=(const CharacterUnion &u) FLATBUFFERS_NOEXCEPT
    { CharacterUnion t(u); std::swap(type, t.type); std::swap(value, t.value); return *this; }
  CharacterUnion &operator=(CharacterUnion &&u) FLATBUFFERS_NOEXCEPT
    { std::swap(type, u.type); std::swap(value, u.value); return *this; }
  ~CharacterUnion() { Reset(); }

  void Reset();

  static void *UnPack(const void *obj, Character type, const flatbuffers::resolver_function_t *resolver);
  flatbuffers::Offset<void> Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *_rehasher = nullptr) const;

  AttackerT *AsMuLan() {
    return type == Character_MuLan ?
      reinterpret_cast<AttackerT *>(value) : nullptr;
  }
  Rapunzel *AsRapunzel() {
    return type == Character_Rapunzel ?
      reinterpret_cast<Rapunzel *>(value) : nullptr;
  }
  BookReader *AsBelle() {
    return type == Character_Belle ?
      reinterpret_cast<BookReader *>(value) : nullptr;
  }
  BookReader *AsBookFan() {
    return type == Character_BookFan ?
      reinterpret_cast<BookReader *>(value) : nullptr;
  }
  std::string *AsOther() {
    return type == Character_Other ?
      reinterpret_cast<std::string *>(value) : nullptr;
  }
  std::string *AsUnused() {
    return type == Character_Unused ?
      reinterpret_cast<std::string *>(value) : nullptr;
  }
};

bool VerifyCharacter(flatbuffers::Verifier &verifier, const void *obj, Character type);
bool VerifyCharacterVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

MANUALLY_ALIGNED_STRUCT(4) Rapunzel FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t hair_length_;

 public:
  Rapunzel() {
    memset(this, 0, sizeof(Rapunzel));
  }
  Rapunzel(const Rapunzel &_o) {
    memcpy(this, &_o, sizeof(Rapunzel));
  }
  Rapunzel(int32_t _hair_length)
      : hair_length_(flatbuffers::EndianScalar(_hair_length)) {
  }
  int32_t hair_length() const {
    return flatbuffers::EndianScalar(hair_length_);
  }
  void mutate_hair_length(int32_t _hair_length) {
    flatbuffers::WriteScalar(&hair_length_, _hair_length);
  }
};
STRUCT_END(Rapunzel, 4);

MANUALLY_ALIGNED_STRUCT(4) BookReader FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t books_read_;

 public:
  BookReader() {
    memset(this, 0, sizeof(BookReader));
  }
  BookReader(const BookReader &_o) {
    memcpy(this, &_o, sizeof(BookReader));
  }
  BookReader(int32_t _books_read)
      : books_read_(flatbuffers::EndianScalar(_books_read)) {
  }
  int32_t books_read() const {
    return flatbuffers::EndianScalar(books_read_);
  }
  void mutate_books_read(int32_t _books_read) {
    flatbuffers::WriteScalar(&books_read_, _books_read);
  }
};
STRUCT_END(BookReader, 4);

struct AttackerT : public flatbuffers::NativeTable {
  typedef Attacker TableType;
  int32_t sword_attack_damage;
  AttackerT()
      : sword_attack_damage(0) {
  }
};

struct Attacker FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AttackerT NativeTableType;
  enum {
    VT_SWORD_ATTACK_DAMAGE = 4
  };
  int32_t sword_attack_damage() const {
    return GetField<int32_t>(VT_SWORD_ATTACK_DAMAGE, 0);
  }
  bool mutate_sword_attack_damage(int32_t _sword_attack_damage) {
    return SetField<int32_t>(VT_SWORD_ATTACK_DAMAGE, _sword_attack_damage, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_SWORD_ATTACK_DAMAGE) &&
           verifier.EndTable();
  }
  AttackerT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(AttackerT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Attacker> Pack(flatbuffers::FlatBufferBuilder &_fbb, const AttackerT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct AttackerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_sword_attack_damage(int32_t sword_attack_damage) {
    fbb_.AddElement<int32_t>(Attacker::VT_SWORD_ATTACK_DAMAGE, sword_attack_damage, 0);
  }
  AttackerBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AttackerBuilder &operator=(const AttackerBuilder &);
  flatbuffers::Offset<Attacker> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Attacker>(end);
    return o;
  }
};

inline flatbuffers::Offset<Attacker> CreateAttacker(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t sword_attack_damage = 0) {
  AttackerBuilder builder_(_fbb);
  builder_.add_sword_attack_damage(sword_attack_damage);
  return builder_.Finish();
}

flatbuffers::Offset<Attacker> CreateAttacker(flatbuffers::FlatBufferBuilder &_fbb, const AttackerT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct MovieT : public flatbuffers::NativeTable {
  typedef Movie TableType;
  CharacterUnion main_character;
  std::vector<CharacterUnion> characters;
  MovieT() {
  }
};

struct Movie FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MovieT NativeTableType;
  enum {
    VT_MAIN_CHARACTER_TYPE = 4,
    VT_MAIN_CHARACTER = 6,
    VT_CHARACTERS_TYPE = 8,
    VT_CHARACTERS = 10
  };
  Character main_character_type() const {
    return static_cast<Character>(GetField<uint8_t>(VT_MAIN_CHARACTER_TYPE, 0));
  }
  bool mutate_main_character_type(Character _main_character_type) {
    return SetField<uint8_t>(VT_MAIN_CHARACTER_TYPE, static_cast<uint8_t>(_main_character_type), 0);
  }
  const void *main_character() const {
    return GetPointer<const void *>(VT_MAIN_CHARACTER);
  }
  template<typename T> const T *main_character_as() const;
  const Attacker *main_character_as_MuLan() const {
    return main_character_type() == Character_MuLan ? static_cast<const Attacker *>(main_character()) : nullptr;
  }
  const Rapunzel *main_character_as_Rapunzel() const {
    return main_character_type() == Character_Rapunzel ? static_cast<const Rapunzel *>(main_character()) : nullptr;
  }
  const BookReader *main_character_as_Belle() const {
    return main_character_type() == Character_Belle ? static_cast<const BookReader *>(main_character()) : nullptr;
  }
  const BookReader *main_character_as_BookFan() const {
    return main_character_type() == Character_BookFan ? static_cast<const BookReader *>(main_character()) : nullptr;
  }
  const flatbuffers::String *main_character_as_Other() const {
    return main_character_type() == Character_Other ? static_cast<const flatbuffers::String *>(main_character()) : nullptr;
  }
  const flatbuffers::String *main_character_as_Unused() const {
    return main_character_type() == Character_Unused ? static_cast<const flatbuffers::String *>(main_character()) : nullptr;
  }
  void *mutable_main_character() {
    return GetPointer<void *>(VT_MAIN_CHARACTER);
  }
  const flatbuffers::Vector<uint8_t> *characters_type() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_CHARACTERS_TYPE);
  }
  flatbuffers::Vector<uint8_t> *mutable_characters_type() {
    return GetPointer<flatbuffers::Vector<uint8_t> *>(VT_CHARACTERS_TYPE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<void>> *characters() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<void>> *>(VT_CHARACTERS);
  }
  flatbuffers::Vector<flatbuffers::Offset<void>> *mutable_characters() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<void>> *>(VT_CHARACTERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_MAIN_CHARACTER_TYPE) &&
           VerifyOffset(verifier, VT_MAIN_CHARACTER) &&
           VerifyCharacter(verifier, main_character(), main_character_type()) &&
           VerifyOffset(verifier, VT_CHARACTERS_TYPE) &&
           verifier.Verify(characters_type()) &&
           VerifyOffset(verifier, VT_CHARACTERS) &&
           verifier.Verify(characters()) &&
           VerifyCharacterVector(verifier, characters(), characters_type()) &&
           verifier.EndTable();
  }
  MovieT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(MovieT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Movie> Pack(flatbuffers::FlatBufferBuilder &_fbb, const MovieT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct MovieBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_main_character_type(Character main_character_type) {
    fbb_.AddElement<uint8_t>(Movie::VT_MAIN_CHARACTER_TYPE, static_cast<uint8_t>(main_character_type), 0);
  }
  void add_main_character(flatbuffers::Offset<void> main_character) {
    fbb_.AddOffset(Movie::VT_MAIN_CHARACTER, main_character);
  }
  void add_characters_type(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> characters_type) {
    fbb_.AddOffset(Movie::VT_CHARACTERS_TYPE, characters_type);
  }
  void add_characters(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> characters) {
    fbb_.AddOffset(Movie::VT_CHARACTERS, characters);
  }
  MovieBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MovieBuilder &operator=(const MovieBuilder &);
  flatbuffers::Offset<Movie> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Movie>(end);
    return o;
  }
};

inline flatbuffers::Offset<Movie> CreateMovie(
    flatbuffers::FlatBufferBuilder &_fbb,
    Character main_character_type = Character_NONE,
    flatbuffers::Offset<void> main_character = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> characters_type = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> characters = 0) {
  MovieBuilder builder_(_fbb);
  builder_.add_characters(characters);
  builder_.add_characters_type(characters_type);
  builder_.add_main_character(main_character);
  builder_.add_main_character_type(main_character_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Movie> CreateMovieDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    Character main_character_type = Character_NONE,
    flatbuffers::Offset<void> main_character = 0,
    const std::vector<uint8_t> *characters_type = nullptr,
    const std::vector<flatbuffers::Offset<void>> *characters = nullptr) {
  return CreateMovie(
      _fbb,
      main_character_type,
      main_character,
      characters_type ? _fbb.CreateVector<uint8_t>(*characters_type) : 0,
      characters ? _fbb.CreateVector<flatbuffers::Offset<void>>(*characters) : 0);
}

flatbuffers::Offset<Movie> CreateMovie(flatbuffers::FlatBufferBuilder &_fbb, const MovieT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline AttackerT *Attacker::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new AttackerT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Attacker::UnPackTo(AttackerT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = sword_attack_damage(); _o->sword_attack_damage = _e; };
}

inline flatbuffers::Offset<Attacker> Attacker::Pack(flatbuffers::FlatBufferBuilder &_fbb, const AttackerT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateAttacker(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Attacker> CreateAttacker(flatbuffers::FlatBufferBuilder &_fbb, const AttackerT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const AttackerT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _sword_attack_damage = _o->sword_attack_damage;
  return CreateAttacker(
      _fbb,
      _sword_attack_damage);
}

inline MovieT *Movie::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new MovieT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Movie::UnPackTo(MovieT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = main_character_type(); _o->main_character.type = _e; };
  { auto _e = main_character(); if (_e) _o->main_character.value = CharacterUnion::UnPack(_e, main_character_type(), _resolver); };
  { auto _e = characters_type(); if (_e) { _o->characters.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->characters[_i].type = (Character)_e->Get(_i); } } };
  { auto _e = characters(); if (_e) { _o->characters.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->characters[_i].value = CharacterUnion::UnPack(_e->Get(_i), characters_type()->GetEnum<Character>(_i), _resolver); } } };
}

inline flatbuffers::Offset<Movie> Movie::Pack(flatbuffers::FlatBufferBuilder &_fbb, const MovieT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateMovie(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Movie> CreateMovie(flatbuffers::FlatBufferBuilder &_fbb, const MovieT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const MovieT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _main_character_type = _o->main_character.type;
  auto _main_character = _o->main_character.Pack(_fbb);
  auto _characters_type = _o->characters.size() ? _fbb.CreateVector<uint8_t>(_o->characters.size(), [](size_t i, _VectorArgs *__va) { return static_cast<uint8_t>(__va->__o->characters[i].type); }, &_va) : 0;
  auto _characters = _o->characters.size() ? _fbb.CreateVector<flatbuffers::Offset<void>>(_o->characters.size(), [](size_t i, _VectorArgs *__va) { return __va->__o->characters[i].Pack(*__va->__fbb, __va->__rehasher); }, &_va) : 0;
  return CreateMovie(
      _fbb,
      _main_character_type,
      _main_character,
      _characters_type,
      _characters);
}

inline bool VerifyCharacter(flatbuffers::Verifier &verifier, const void *obj, Character type) {
  switch (type) {
    case Character_NONE: {
      return true;
    }
    case Character_MuLan: {
      auto ptr = reinterpret_cast<const Attacker *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Character_Rapunzel: {
      return true;
    }
    case Character_Belle: {
      return true;
    }
    case Character_BookFan: {
      return true;
    }
    case Character_Other: {
      auto ptr = reinterpret_cast<const flatbuffers::String *>(obj);
      return verifier.Verify(ptr);
    }
    case Character_Unused: {
      auto ptr = reinterpret_cast<const flatbuffers::String *>(obj);
      return verifier.Verify(ptr);
    }
    default: return false;
  }
}

inline bool VerifyCharacterVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyCharacter(
        verifier,  values->Get(i), types->GetEnum<Character>(i))) {
      return false;
    }
  }
  return true;
}

inline void *CharacterUnion::UnPack(const void *obj, Character type, const flatbuffers::resolver_function_t *resolver) {
  switch (type) {
    case Character_MuLan: {
      auto ptr = reinterpret_cast<const Attacker *>(obj);
      return ptr->UnPack(resolver);
    }
    case Character_Rapunzel: {
      auto ptr = reinterpret_cast<const Rapunzel *>(obj);
      return new Rapunzel(*ptr);
    }
    case Character_Belle: {
      auto ptr = reinterpret_cast<const BookReader *>(obj);
      return new BookReader(*ptr);
    }
    case Character_BookFan: {
      auto ptr = reinterpret_cast<const BookReader *>(obj);
      return new BookReader(*ptr);
    }
    case Character_Other: {
      auto ptr = reinterpret_cast<const flatbuffers::String *>(obj);
      return new std::string(ptr->c_str(), ptr->size());
    }
    case Character_Unused: {
      auto ptr = reinterpret_cast<const flatbuffers::String *>(obj);
      return new std::string(ptr->c_str(), ptr->size());
    }
    default: return nullptr;
  }
}

inline flatbuffers::Offset<void> CharacterUnion::Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *_rehasher) const {
  switch (type) {
    case Character_MuLan: {
      auto ptr = reinterpret_cast<const AttackerT *>(value);
      return CreateAttacker(_fbb, ptr, _rehasher).Union();
    }
    case Character_Rapunzel: {
      auto ptr = reinterpret_cast<const Rapunzel *>(value);
      return _fbb.CreateStruct(*ptr).Union();
    }
    case Character_Belle: {
      auto ptr = reinterpret_cast<const BookReader *>(value);
      return _fbb.CreateStruct(*ptr).Union();
    }
    case Character_BookFan: {
      auto ptr = reinterpret_cast<const BookReader *>(value);
      return _fbb.CreateStruct(*ptr).Union();
    }
    case Character_Other: {
      auto ptr = reinterpret_cast<const std::string *>(value);
      return _fbb.CreateString(*ptr).Union();
    }
    case Character_Unused: {
      auto ptr = reinterpret_cast<const std::string *>(value);
      return _fbb.CreateString(*ptr).Union();
    }
    default: return 0;
  }
}

inline CharacterUnion::CharacterUnion(const CharacterUnion &u) FLATBUFFERS_NOEXCEPT : type(u.type), value(nullptr) {
  switch (type) {
    case Character_MuLan: {
      value = new AttackerT(*reinterpret_cast<AttackerT *>(u.value));
      break;
    }
    case Character_Rapunzel: {
      value = new Rapunzel(*reinterpret_cast<Rapunzel *>(u.value));
      break;
    }
    case Character_Belle: {
      value = new BookReader(*reinterpret_cast<BookReader *>(u.value));
      break;
    }
    case Character_BookFan: {
      value = new BookReader(*reinterpret_cast<BookReader *>(u.value));
      break;
    }
    case Character_Other: {
      value = new std::string(*reinterpret_cast<std::string *>(u.value));
      break;
    }
    case Character_Unused: {
      value = new std::string(*reinterpret_cast<std::string *>(u.value));
      break;
    }
    default:
      break;
  }
}

inline void CharacterUnion::Reset() {
  switch (type) {
    case Character_MuLan: {
      auto ptr = reinterpret_cast<AttackerT *>(value);
      delete ptr;
      break;
    }
    case Character_Rapunzel: {
      auto ptr = reinterpret_cast<Rapunzel *>(value);
      delete ptr;
      break;
    }
    case Character_Belle: {
      auto ptr = reinterpret_cast<BookReader *>(value);
      delete ptr;
      break;
    }
    case Character_BookFan: {
      auto ptr = reinterpret_cast<BookReader *>(value);
      delete ptr;
      break;
    }
    case Character_Other: {
      auto ptr = reinterpret_cast<std::string *>(value);
      delete ptr;
      break;
    }
    case Character_Unused: {
      auto ptr = reinterpret_cast<std::string *>(value);
      delete ptr;
      break;
    }
    default: break;
  }
  value = nullptr;
  type = Character_NONE;
}

inline const Movie *GetMovie(const void *buf) {
  return flatbuffers::GetRoot<Movie>(buf);
}

inline Movie *GetMutableMovie(void *buf) {
  return flatbuffers::GetMutableRoot<Movie>(buf);
}

inline const char *MovieIdentifier() {
  return "MOVI";
}

inline bool MovieBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, MovieIdentifier());
}

inline bool VerifyMovieBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Movie>(MovieIdentifier());
}

inline void FinishMovieBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Movie> root) {
  fbb.Finish(root, MovieIdentifier());
}

inline flatbuffers::unique_ptr<MovieT> UnPackMovie(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return flatbuffers::unique_ptr<MovieT>(GetMovie(buf)->UnPack(res));
}

#endif  // FLATBUFFERS_GENERATED_UNIONVECTOR_H_
