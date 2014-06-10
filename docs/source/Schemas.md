# Writing a schema

The syntax of the schema language (aka IDL, Interface Definition
Language) should look quite familiar to users of any of the C family of
languages, and also to users of other IDLs. Let's look at an example
first:

    // example IDL file

    namespace MyGame;

    enum Color : byte { Red = 1, Green, Blue }

    union Any { Monster, Weapon, Pickup }

    struct Vec3 {
      x:float;
      y:float;
      z:float;
    }

    table Monster {
      pos:Vec3;
      mana:short = 150;
      hp:short = 100;
      name:string;
      friendly:bool = false (deprecated, priority: 1);
      inventory:[ubyte];
      color:Color = Blue;
      test:Any;
    }

    root_type Monster;

(Weapon & Pickup not defined as part of this example).

### Tables

Tables are the main way of defining objects in FlatBuffers, and consist
of a name (here `Monster`) and a list of fields. Each field has a name,
a type, and optionally a default value (if omitted, it defaults to 0 /
NULL).

Each field is optional: It does not have to appear in the wire
representation, and you can choose to omit fields for each individual
object. As a result, you have the flexibility to add fields without fear of
bloating your data. This design is also FlatBuffer's mechanism for forward
and backwards compatibility. Note that:

-   You can add new fields in the schema ONLY at the end of a table
    definition. Older data will still
    read correctly, and give you the default value when read. Older code
    will simply ignore the new field.

-   You cannot delete fields you don't use anymore from the schema,
    but you can simply
    stop writing them into your data for almost the same effect.
    Additionally you can mark them as `deprecated` as in the example
    above, which will prevent the generation of accessors in the
    generated C++, as a way to enforce the field not being used any more.
    (careful: this may break code!).

-   You may change field names and table names, if you're ok with your
    code breaking until you've renamed them there too.



### Structs

Similar to a table, only now none of the fields are optional (so no defaults
either), and fields may not be added or be deprecated. Structs may only contain
scalars or other structs. Use this for
simple objects where you are very sure no changes will ever be made
(as quite clear in the example `Vec3`). Structs use less memory than
tables and are even faster to access (they are always stored in-line in their
parent object, and use no virtual table).

### Types

Builtin scalar types are:

-   8 bit: `byte ubyte bool`

-   16 bit: `short ushort`

-   32 bit: `int uint float`

-   64 bit: `long ulong double`

-   Vector of any other type (denoted with `[type]`). Nesting vectors
    require you wrap the inner vector in a struct/table rather than
    writing `[[type]]`.

-   `string`, which may only hold UTF-8 or 7-bit ASCII. For other text encodings
    or general binary data use vectors (`[byte]` or `[ubyte]`) instead.

-   References to other tables or structs, enums or unions (see
    below).

You can't change types of fields once they're used, with the exception
of same-size data where a `reinterpret_cast` would give you a desirable result,
e.g. you could change a `uint` to an `int` if no values in current data use the
high bit yet.

### (Default) Values

Values are a sequence of digits, optionally followed by a `.` and more digits
for float constants, and optionally prefixed by a `-`. Non-scalar defaults are
currently not supported (always NULL).

You generally do not want to change default values after they're initially
defined. Fields that have the default value are not actually stored in the
serialized data but are generated in code, so when you change the default, you'd
now get a different value than from code generated from an older version of
the schema. There are situations however where this may be
desirable, especially if you can ensure a simultaneous rebuild of
all code.

### Enums

Define a sequence of named constants, each with a given value, or
increasing by one from the previous one. The default first value
is `0`. As you can see in the enum declaration, you specify the underlying
integral type of the enum with `:` (in this case `byte`), which then determines
the type of any fields declared with this enum type. If you omit the underlying
type, it will be `short`.

### Unions

Unions share a lot of properties with enums, but instead of new names
for constants, you use names of tables. You can then declare
a union field which can hold a reference to any of those types, and
additionally a hidden field with the suffix `_type` is generated that
holds the corresponding enum value, allowing you to know which type to
cast to at runtime.

### Namespaces

These will generate the corresponding namespace in C++ for all helper
code, and packages in Java. You can use `.` to specify nested namespaces /
packages.

### Root type

This declares what you consider to be the root table (or struct) of the
serialized data.

### Comments & documentation

May be written as in most C-based languages. Additionally, a triple
comment (`///`) on a line by itself signals that a comment is documentation
for whatever is declared on the line after it
(table/struct/field/enum/union/element), and the comment is output
in the corresponding C++ code. Multiple such lines per item are allowed.

### Attributes

Attributes may be attached to a declaration, behind a field, or after
the name of a table/struct/enum/union. These may either have a value or
not. Some attributes like `deprecated` are understood by the compiler,
others are simply ignored (like `priority`), but are available to query
if you parse the schema at runtime.
This is useful if you write your own code generators/editors etc., and
you wish to add additional information specific to your tool (such as a
help text).

Current understood attributes:

-   `deprecated` (on a field): do not generate accessors for this field
    anymore, code should stop using this data.
-   `original_order` (on a table): since elements in a table do not need
    to be stored in any particular order, they are often optimized for
    space by sorting them to size. This attribute stops that from happening.
-   `force_align: size` (on a struct): force the alignment of this struct
    to be something higher than what it is naturally aligned to. Causes
    these structs to be aligned to that amount inside a buffer, IF that
    buffer is allocated with that alignment (which is not necessarily
    the case for buffers accessed directly inside a `FlatBufferBuilder`).

## Gotchas

### Schemas and version control

FlatBuffers relies on new field declarations being added at the end, and earlier
declarations to not be removed, but be marked deprecated when needed. We think
this is an improvement over the manual number assignment that happens in
Protocol Buffers.

One place where this is possibly problematic however is source control. If user
A adds a field, generates new binary data with this new schema, then tries to
commit both to source control after user B already committed a new field also,
and just auto-merges the schema, the binary files are now invalid compared to
the new schema.

The solution of course is that you should not be generating binary data before
your schema changes have been committed, ensuring consistency with the rest of
the world.

