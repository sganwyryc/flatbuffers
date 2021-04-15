// automatically generated by the FlatBuffers compiler, do not modify



use crate::include_test1_generated::*;
use std::mem;
use std::cmp::Ordering;

extern crate flatbuffers;
use self::flatbuffers::EndianScalar;

#[allow(unused_imports, dead_code)]
pub mod my_game {

  use crate::include_test1_generated::*;
  use std::mem;
  use std::cmp::Ordering;

  extern crate flatbuffers;
  use self::flatbuffers::EndianScalar;
#[allow(unused_imports, dead_code)]
pub mod other_name_space {

  use crate::include_test1_generated::*;
  use std::mem;
  use std::cmp::Ordering;

  extern crate flatbuffers;
  use self::flatbuffers::EndianScalar;

#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MIN_FROM_INCLUDE: i64 = 0;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MAX_FROM_INCLUDE: i64 = 0;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
#[allow(non_camel_case_types)]
pub const ENUM_VALUES_FROM_INCLUDE: [FromInclude; 1] = [
  FromInclude::IncludeVal,
];

#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash, Default)]
#[repr(transparent)]
pub struct FromInclude(pub i64);
#[allow(non_upper_case_globals)]
impl FromInclude {
  pub const IncludeVal: Self = Self(0);

  pub const ENUM_MIN: i64 = 0;
  pub const ENUM_MAX: i64 = 0;
  pub const ENUM_VALUES: &'static [Self] = &[
    Self::IncludeVal,
  ];
  /// Returns the variant's name or "" if unknown.
  pub fn variant_name(self) -> Option<&'static str> {
    match self {
      Self::IncludeVal => Some("IncludeVal"),
      _ => None,
    }
  }
}
impl std::fmt::Debug for FromInclude {
  fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
    if let Some(name) = self.variant_name() {
      f.write_str(name)
    } else {
      f.write_fmt(format_args!("<UNKNOWN {:?}>", self.0))
    }
  }
}
impl<'a> flatbuffers::Follow<'a> for FromInclude {
  type Inner = Self;
  #[inline]
  fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    let b = flatbuffers::read_scalar_at::<i64>(buf, loc);
    Self(b)
  }
}

impl flatbuffers::Push for FromInclude {
    type Output = FromInclude;
    #[inline]
    fn push(&self, dst: &mut [u8], _rest: &[u8]) {
        flatbuffers::emplace_scalar::<i64>(dst, self.0);
    }
}

impl flatbuffers::EndianScalar for FromInclude {
  #[inline]
  fn to_little_endian(self) -> Self {
    let b = i64::to_le(self.0);
    Self(b)
  }
  #[inline]
  #[allow(clippy::wrong_self_convention)]
  fn from_little_endian(self) -> Self {
    let b = i64::from_le(self.0);
    Self(b)
  }
}

impl<'a> flatbuffers::Verifiable for FromInclude {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    i64::run_verifier(v, pos)
  }
}

impl flatbuffers::SimpleToVerifyInSlice for FromInclude {}
// struct Unused, aligned to 4
#[repr(transparent)]
#[derive(Clone, Copy, PartialEq)]
pub struct Unused(pub [u8; 4]);
impl Default for Unused { 
  fn default() -> Self { 
    Self([0; 4])
  }
}
impl std::fmt::Debug for Unused {
  fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
    f.debug_struct("Unused")
      .field("a", &self.a())
      .finish()
  }
}

impl flatbuffers::SimpleToVerifyInSlice for Unused {}
impl flatbuffers::SafeSliceAccess for Unused {}
impl<'a> flatbuffers::Follow<'a> for Unused {
  type Inner = &'a Unused;
  #[inline]
  fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    <&'a Unused>::follow(buf, loc)
  }
}
impl<'a> flatbuffers::Follow<'a> for &'a Unused {
  type Inner = &'a Unused;
  #[inline]
  fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    flatbuffers::follow_cast_ref::<Unused>(buf, loc)
  }
}
impl<'b> flatbuffers::Push for Unused {
    type Output = Unused;
    #[inline]
    fn push(&self, dst: &mut [u8], _rest: &[u8]) {
        let src = unsafe {
            ::std::slice::from_raw_parts(self as *const Unused as *const u8, Self::size())
        };
        dst.copy_from_slice(src);
    }
}
impl<'b> flatbuffers::Push for &'b Unused {
    type Output = Unused;

    #[inline]
    fn push(&self, dst: &mut [u8], _rest: &[u8]) {
        let src = unsafe {
            ::std::slice::from_raw_parts(*self as *const Unused as *const u8, Self::size())
        };
        dst.copy_from_slice(src);
    }
}

impl<'a> flatbuffers::Verifiable for Unused {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    v.in_buffer::<Self>(pos)
  }
}
impl Unused {
  #[allow(clippy::too_many_arguments)]
  pub fn new(
    a: i32,
  ) -> Self {
    let mut s = Self([0; 4]);
    s.set_a(a);
    s
  }

  pub fn a(&self) -> i32 {
    let mut mem = core::mem::MaybeUninit::<i32>::uninit();
    unsafe {
      core::ptr::copy_nonoverlapping(
        self.0[0..].as_ptr(),
        mem.as_mut_ptr() as *mut u8,
        core::mem::size_of::<i32>(),
      );
      mem.assume_init()
    }.from_little_endian()
  }

  pub fn set_a(&mut self, x: i32) {
    let x_le = x.to_little_endian();
    unsafe {
      core::ptr::copy_nonoverlapping(
        &x_le as *const i32 as *const u8,
        self.0[0..].as_mut_ptr(),
        core::mem::size_of::<i32>(),
      );
    }
  }

}

pub enum TableBOffset {}
#[derive(Copy, Clone, PartialEq)]

pub struct TableB<'a> {
  pub _tab: flatbuffers::Table<'a>,
}

impl<'a> flatbuffers::Follow<'a> for TableB<'a> {
    type Inner = TableB<'a>;
    #[inline]
    fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
        Self { _tab: flatbuffers::Table { buf, loc } }
    }
}

impl<'a> TableB<'a> {
    #[inline]
    pub fn init_from_table(table: flatbuffers::Table<'a>) -> Self {
        TableB { _tab: table }
    }
    #[allow(unused_mut)]
    pub fn create<'bldr: 'args, 'args: 'mut_bldr, 'mut_bldr>(
        _fbb: &'mut_bldr mut flatbuffers::FlatBufferBuilder<'bldr>,
        args: &'args TableBArgs<'args>) -> flatbuffers::WIPOffset<TableB<'bldr>> {
      let mut builder = TableBBuilder::new(_fbb);
      if let Some(x) = args.a { builder.add_a(x); }
      builder.finish()
    }

    pub const VT_A: flatbuffers::VOffsetT = 4;

  #[inline]
  pub fn a(&self) -> Option<super::super::TableA<'a>> {
    self._tab.get::<flatbuffers::ForwardsUOffset<super::super::TableA>>(TableB::VT_A, None)
  }
}

impl flatbuffers::Verifiable for TableB<'_> {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    v.visit_table(pos)?
     .visit_field::<flatbuffers::ForwardsUOffset<super::super::TableA>>(&"a", Self::VT_A, false)?
     .finish();
    Ok(())
  }
}
pub struct TableBArgs<'a> {
    pub a: Option<flatbuffers::WIPOffset<super::super::TableA<'a>>>,
}
impl<'a> Default for TableBArgs<'a> {
    #[inline]
    fn default() -> Self {
        TableBArgs {
            a: None,
        }
    }
}
pub struct TableBBuilder<'a: 'b, 'b> {
  fbb_: &'b mut flatbuffers::FlatBufferBuilder<'a>,
  start_: flatbuffers::WIPOffset<flatbuffers::TableUnfinishedWIPOffset>,
}
impl<'a: 'b, 'b> TableBBuilder<'a, 'b> {
  #[inline]
  pub fn add_a(&mut self, a: flatbuffers::WIPOffset<super::super::TableA<'b >>) {
    self.fbb_.push_slot_always::<flatbuffers::WIPOffset<super::super::TableA>>(TableB::VT_A, a);
  }
  #[inline]
  pub fn new(_fbb: &'b mut flatbuffers::FlatBufferBuilder<'a>) -> TableBBuilder<'a, 'b> {
    let start = _fbb.start_table();
    TableBBuilder {
      fbb_: _fbb,
      start_: start,
    }
  }
  #[inline]
  pub fn finish(self) -> flatbuffers::WIPOffset<TableB<'a>> {
    let o = self.fbb_.end_table(self.start_);
    flatbuffers::WIPOffset::new(o.value())
  }
}

impl std::fmt::Debug for TableB<'_> {
  fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
    let mut ds = f.debug_struct("TableB");
      ds.field("a", &self.a());
      ds.finish()
  }
}
}  // pub mod OtherNameSpace
}  // pub mod MyGame

