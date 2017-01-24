// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_UNIONVECTOR_H_
#define FLATBUFFERS_GENERATED_UNIONVECTOR_H_

#include "flatbuffers/flatbuffers.h"

struct MuLan;

struct Rapunzel;

struct Belle;

struct Movie;

enum Character {
  Character_NONE = 0,
  Character_MuLan = 1,
  Character_Rapunzel = 2,
  Character_Belle = 3,
  Character_MIN = Character_NONE,
  Character_MAX = Character_Belle
};

inline const char **EnumNamesCharacter() {
  static const char *names[] = {
    "NONE",
    "MuLan",
    "Rapunzel",
    "Belle",
    nullptr
  };
  return names;
}

inline const char *EnumNameCharacter(Character e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesCharacter()[index];
}

template<typename T> struct CharacterTraits {
  static const Character enum_value = Character_NONE;
};

template<> struct CharacterTraits<MuLan> {
  static const Character enum_value = Character_MuLan;
};

template<> struct CharacterTraits<Rapunzel> {
  static const Character enum_value = Character_Rapunzel;
};

template<> struct CharacterTraits<Belle> {
  static const Character enum_value = Character_Belle;
};

bool VerifyCharacter(flatbuffers::Verifier &verifier, const void *obj, Character type);
bool VerifyCharacterVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct MuLan FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SWORD_ATTACK_DAMAGE = 4
  };
  int32_t sword_attack_damage() const {
    return GetField<int32_t>(VT_SWORD_ATTACK_DAMAGE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_SWORD_ATTACK_DAMAGE) &&
           verifier.EndTable();
  }
};

struct MuLanBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_sword_attack_damage(int32_t sword_attack_damage) {
    fbb_.AddElement<int32_t>(MuLan::VT_SWORD_ATTACK_DAMAGE, sword_attack_damage, 0);
  }
  MuLanBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MuLanBuilder &operator=(const MuLanBuilder &);
  flatbuffers::Offset<MuLan> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<MuLan>(end);
    return o;
  }
};

inline flatbuffers::Offset<MuLan> CreateMuLan(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t sword_attack_damage = 0) {
  MuLanBuilder builder_(_fbb);
  builder_.add_sword_attack_damage(sword_attack_damage);
  return builder_.Finish();
}

struct Rapunzel FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_HAIR_LENGTH = 4
  };
  int32_t hair_length() const {
    return GetField<int32_t>(VT_HAIR_LENGTH, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_HAIR_LENGTH) &&
           verifier.EndTable();
  }
};

struct RapunzelBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_hair_length(int32_t hair_length) {
    fbb_.AddElement<int32_t>(Rapunzel::VT_HAIR_LENGTH, hair_length, 0);
  }
  RapunzelBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RapunzelBuilder &operator=(const RapunzelBuilder &);
  flatbuffers::Offset<Rapunzel> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<Rapunzel>(end);
    return o;
  }
};

inline flatbuffers::Offset<Rapunzel> CreateRapunzel(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t hair_length = 0) {
  RapunzelBuilder builder_(_fbb);
  builder_.add_hair_length(hair_length);
  return builder_.Finish();
}

struct Belle FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_BOOKS_READ = 4
  };
  int32_t books_read() const {
    return GetField<int32_t>(VT_BOOKS_READ, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_BOOKS_READ) &&
           verifier.EndTable();
  }
};

struct BelleBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_books_read(int32_t books_read) {
    fbb_.AddElement<int32_t>(Belle::VT_BOOKS_READ, books_read, 0);
  }
  BelleBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  BelleBuilder &operator=(const BelleBuilder &);
  flatbuffers::Offset<Belle> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<Belle>(end);
    return o;
  }
};

inline flatbuffers::Offset<Belle> CreateBelle(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t books_read = 0) {
  BelleBuilder builder_(_fbb);
  builder_.add_books_read(books_read);
  return builder_.Finish();
}

struct Movie FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHARACTERS_TYPE = 4,
    VT_CHARACTERS = 6
  };
  const flatbuffers::Vector<uint8_t> *characters_type() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_CHARACTERS_TYPE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<void>> *characters() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<void>> *>(VT_CHARACTERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_CHARACTERS_TYPE) &&
           verifier.Verify(characters_type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_CHARACTERS) &&
           verifier.Verify(characters()) &&
           VerifyCharacterVector(verifier, characters(), characters_type()) &&
           verifier.EndTable();
  }
};

struct MovieBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
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
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Movie>(end);
    return o;
  }
};

inline flatbuffers::Offset<Movie> CreateMovie(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> characters_type = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> characters = 0) {
  MovieBuilder builder_(_fbb);
  builder_.add_characters(characters);
  builder_.add_characters_type(characters_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Movie> CreateMovieDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *characters_type = nullptr,
    const std::vector<flatbuffers::Offset<void>> *characters = nullptr) {
  return CreateMovie(
      _fbb,
      characters_type ? _fbb.CreateVector<uint8_t>(*characters_type) : 0,
      characters ? _fbb.CreateVector<flatbuffers::Offset<void>>(*characters) : 0);
}

inline bool VerifyCharacter(flatbuffers::Verifier &verifier, const void *obj, Character type) {
  switch (type) {
    case Character_NONE: {
      return true;
    }
    case Character_MuLan: {
      auto ptr = reinterpret_cast<const MuLan *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Character_Rapunzel: {
      auto ptr = reinterpret_cast<const Rapunzel *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Character_Belle: {
      auto ptr = reinterpret_cast<const Belle *>(obj);
      return verifier.VerifyTable(ptr);
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

inline const Movie *GetMovie(const void *buf) {
  return flatbuffers::GetRoot<Movie>(buf);
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

#endif  // FLATBUFFERS_GENERATED_UNIONVECTOR_H_
