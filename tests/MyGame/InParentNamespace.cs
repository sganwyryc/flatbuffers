// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace MyGame
{

using global::System;
using global::System.Collections.Generic;
using global::FlatBuffers;

public struct InParentNamespace : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_1_11_1(); }
  public static InParentNamespace GetRootAsInParentNamespace(ByteBuffer _bb) { return GetRootAsInParentNamespace(_bb, new InParentNamespace()); }
  public static InParentNamespace GetRootAsInParentNamespace(ByteBuffer _bb, InParentNamespace obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public InParentNamespace __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }


  public static void StartInParentNamespace(FlatBufferBuilder builder) { builder.StartTable(0); }
  public static Offset<MyGame.InParentNamespace> EndInParentNamespace(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<MyGame.InParentNamespace>(o);
  }
  public InParentNamespaceT UnPack() {
    var _o = new InParentNamespaceT();
    this.UnPackTo(_o);
    return _o;
  }
  public void UnPackTo(InParentNamespaceT _o) {
  }
  public static Offset<MyGame.InParentNamespace> Pack(FlatBufferBuilder builder, InParentNamespaceT _o) {
    if (_o == null) return default(Offset<MyGame.InParentNamespace>);
    StartInParentNamespace(builder);
    return EndInParentNamespace(builder);
  }
};

public class InParentNamespaceT
{

  public InParentNamespaceT() {
  }
}


}
