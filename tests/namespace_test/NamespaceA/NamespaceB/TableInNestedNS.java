// automatically generated by the FlatBuffers compiler, do not modify

package NamespaceA.NamespaceB;

import java.nio.*;
import java.lang.*;
import java.util.*;
import com.google.flatbuffers.*;

@SuppressWarnings("unused")
public final class TableInNestedNS extends Table {
  public static TableInNestedNS getRootAsTableInNestedNS(ByteBuffer _bb) { return getRootAsTableInNestedNS(_bb, new TableInNestedNS()); }
  public static TableInNestedNS getRootAsTableInNestedNS(ByteBuffer _bb, TableInNestedNS obj) { _bb.order(ByteOrder.LITTLE_ENDIAN); return (obj.__init(_bb.getInt(_bb.position()) + _bb.position(), _bb)); }
  public TableInNestedNS __init(int _i, ByteBuffer _bb) { bb_pos = _i; bb = _bb; return this; }

  public int foo() { int o = __offset(4); return o != 0 ? bb.getInt(o + bb_pos) : 0; }
  public boolean mutateFoo(int foo) { int o = __offset(4); if (o != 0) { bb.putInt(o + bb_pos, foo); return true; } else { return false; } }

  public static int createTableInNestedNS(FlatBufferBuilder builder,
      int foo) {
    builder.startObject(1);
    TableInNestedNS.addFoo(builder, foo);
    return TableInNestedNS.endTableInNestedNS(builder);
  }

  public static void startTableInNestedNS(FlatBufferBuilder builder) { builder.startObject(1); }
  public static void addFoo(FlatBufferBuilder builder, int foo) { builder.addInt(0, foo, 0); }
  public static int endTableInNestedNS(FlatBufferBuilder builder) {
    int o = builder.endObject();
    return o;
  }
};

