# automatically generated, do not modify

# namespace: NamespaceA

import flatbuffers

class TableInFirstNS(object):
    __slots__ = ['_tab']

    # TableInFirstNS
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # TableInFirstNS
    def FooTable(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            x = self._tab.Indirect(o + self._tab.Pos)
            from .TableInNestedNS import TableInNestedNS
            obj = TableInNestedNS()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # TableInFirstNS
    def FooEnum(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # TableInFirstNS
    def FooStruct(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            x = o + self._tab.Pos
            from .StructInNestedNS import StructInNestedNS
            obj = StructInNestedNS()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

def TableInFirstNSStart(builder): builder.StartObject(3)
def TableInFirstNSAddFooTable(builder, fooTable): builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(fooTable), 0)
def TableInFirstNSAddFooEnum(builder, fooEnum): builder.PrependInt8Slot(1, fooEnum, 0)
def TableInFirstNSAddFooStruct(builder, fooStruct): builder.PrependStructSlot(2, flatbuffers.number_types.UOffsetTFlags.py_type(fooStruct), 0)
def TableInFirstNSEnd(builder): return builder.EndObject()
