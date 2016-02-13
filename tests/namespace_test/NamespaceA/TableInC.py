# automatically generated, do not modify

# namespace: NamespaceA

import flatbuffers

class TableInC(object):
    __slots__ = ['_tab']

    # TableInC
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # TableInC
    def ReferToA1(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            x = self._tab.Indirect(o + self._tab.Pos)
            from .TableInFirstNS import TableInFirstNS
            obj = TableInFirstNS()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # TableInC
    def ReferToA2(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            x = self._tab.Indirect(o + self._tab.Pos)
            from .SecondTableInA import SecondTableInA
            obj = SecondTableInA()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

def TableInCStart(builder): builder.StartObject(2)
def TableInCAddReferToA1(builder, referToA1): builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(referToA1), 0)
def TableInCAddReferToA2(builder, referToA2): builder.PrependUOffsetTRelativeSlot(1, flatbuffers.number_types.UOffsetTFlags.py_type(referToA2), 0)
def TableInCEnd(builder): return builder.EndObject()
