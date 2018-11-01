-- automatically generated by the FlatBuffers compiler, do not modify

-- namespace: Example

local flatbuffers = require('flatbuffers')

-- /// an example documentation comment: monster object
local Monster = {} -- the module
local Monster_mt = {} -- the class metatable

function Monster.New()
    local o = {}
    setmetatable(o, {__index = Monster_mt})
    return o
end
function Monster.GetRootAsMonster(buf, offset)
    local n = flatbuffers.N.UOffsetT:Unpack(buf, offset)
    local o = Monster.New()
    o:Init(buf, n + offset)
    return o
end
function Monster_mt:Init(buf, pos)
    self.view = flatbuffers.view.New(buf, pos)
end
function Monster_mt:Pos()
    local o = self.view:Offset(4)
    if o ~= 0 then
        local x = o + self.view.pos
        local obj = require('MyGame.Example.Vec3').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:Mana()
    local o = self.view:Offset(6)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int16, o + self.view.pos)
    end
    return 150
end
function Monster_mt:Hp()
    local o = self.view:Offset(8)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int16, o + self.view.pos)
    end
    return 100
end
function Monster_mt:Name()
    local o = self.view:Offset(10)
    if o ~= 0 then
        return self.view:String(o + self.view.pos)
    end
end
function Monster_mt:Inventory(j)
    local o = self.view:Offset(14)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Uint8, a + ((j-1) * 1))
    end
    return 0
end
function Monster_mt:InventoryLength()
    local o = self.view:Offset(14)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Color()
    local o = self.view:Offset(16)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int8, o + self.view.pos)
    end
    return 8
end
function Monster_mt:TestType()
    local o = self.view:Offset(18)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint8, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Test()
    local o = self.view:Offset(20)
    if o ~= 0 then
        local obj = flatbuffers.view.New(require('flatbuffers.binaryarray').New(0), 0)
        self.view:Union(obj, o)
        return obj
    end
end
function Monster_mt:Test4(j)
    local o = self.view:Offset(22)
    if o ~= 0 then
        local x = self.view:Vector(o)
        x = x + ((j-1) * 4)
        local obj = require('MyGame.Example.Test').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:Test4Length()
    local o = self.view:Offset(22)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Testarrayofstring(j)
    local o = self.view:Offset(24)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:String(a + ((j-1) * 4))
    end
    return ''
end
function Monster_mt:TestarrayofstringLength()
    local o = self.view:Offset(24)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
-- /// an example documentation comment: this will end up in the generated code
-- /// multiline too
function Monster_mt:Testarrayoftables(j)
    local o = self.view:Offset(26)
    if o ~= 0 then
        local x = self.view:Vector(o)
        x = x + ((j-1) * 4)
        x = self.view:Indirect(x)
        local obj = require('MyGame.Example.Monster').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:TestarrayoftablesLength()
    local o = self.view:Offset(26)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Enemy()
    local o = self.view:Offset(28)
    if o ~= 0 then
        local x = self.view:Indirect(o + self.view.pos)
        local obj = require('MyGame.Example.Monster').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:Testnestedflatbuffer(j)
    local o = self.view:Offset(30)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Uint8, a + ((j-1) * 1))
    end
    return 0
end
function Monster_mt:TestnestedflatbufferLength()
    local o = self.view:Offset(30)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Testempty()
    local o = self.view:Offset(32)
    if o ~= 0 then
        local x = self.view:Indirect(o + self.view.pos)
        local obj = require('MyGame.Example.Stat').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:Testbool()
    local o = self.view:Offset(34)
    if o ~= 0 then
        return (self.view:Get(flatbuffers.N.Bool, o + self.view.pos) ~= 0)
    end
    return false
end
function Monster_mt:Testhashs32Fnv1()
    local o = self.view:Offset(36)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int32, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashu32Fnv1()
    local o = self.view:Offset(38)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint32, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashs64Fnv1()
    local o = self.view:Offset(40)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashu64Fnv1()
    local o = self.view:Offset(42)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashs32Fnv1a()
    local o = self.view:Offset(44)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int32, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashu32Fnv1a()
    local o = self.view:Offset(46)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint32, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashs64Fnv1a()
    local o = self.view:Offset(48)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Int64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testhashu64Fnv1a()
    local o = self.view:Offset(50)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:Testarrayofbools(j)
    local o = self.view:Offset(52)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Bool, a + ((j-1) * 1))
    end
    return 0
end
function Monster_mt:TestarrayofboolsLength()
    local o = self.view:Offset(52)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Testf()
    local o = self.view:Offset(54)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Float32, o + self.view.pos)
    end
    return 3.14159
end
function Monster_mt:Testf2()
    local o = self.view:Offset(56)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Float32, o + self.view.pos)
    end
    return 3.0
end
function Monster_mt:Testf3()
    local o = self.view:Offset(58)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Float32, o + self.view.pos)
    end
    return 0.0
end
function Monster_mt:Testarrayofstring2(j)
    local o = self.view:Offset(60)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:String(a + ((j-1) * 4))
    end
    return ''
end
function Monster_mt:Testarrayofstring2Length()
    local o = self.view:Offset(60)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Testarrayofsortedstruct(j)
    local o = self.view:Offset(62)
    if o ~= 0 then
        local x = self.view:Vector(o)
        x = x + ((j-1) * 8)
        local obj = require('MyGame.Example.Ability').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:TestarrayofsortedstructLength()
    local o = self.view:Offset(62)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Flex(j)
    local o = self.view:Offset(64)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Uint8, a + ((j-1) * 1))
    end
    return 0
end
function Monster_mt:FlexLength()
    local o = self.view:Offset(64)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:Test5(j)
    local o = self.view:Offset(66)
    if o ~= 0 then
        local x = self.view:Vector(o)
        x = x + ((j-1) * 4)
        local obj = require('MyGame.Example.Test').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:Test5Length()
    local o = self.view:Offset(66)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:VectorOfLongs(j)
    local o = self.view:Offset(68)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Int64, a + ((j-1) * 8))
    end
    return 0
end
function Monster_mt:VectorOfLongsLength()
    local o = self.view:Offset(68)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:VectorOfDoubles(j)
    local o = self.view:Offset(70)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Float64, a + ((j-1) * 8))
    end
    return 0
end
function Monster_mt:VectorOfDoublesLength()
    local o = self.view:Offset(70)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:ParentNamespaceTest()
    local o = self.view:Offset(72)
    if o ~= 0 then
        local x = self.view:Indirect(o + self.view.pos)
        local obj = require('MyGame.InParentNamespace').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:VectorOfReferrables(j)
    local o = self.view:Offset(74)
    if o ~= 0 then
        local x = self.view:Vector(o)
        x = x + ((j-1) * 4)
        x = self.view:Indirect(x)
        local obj = require('MyGame.Example.Referrable').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:VectorOfReferrablesLength()
    local o = self.view:Offset(74)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:SingleWeakReference()
    local o = self.view:Offset(76)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:VectorOfWeakReferences(j)
    local o = self.view:Offset(78)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Uint64, a + ((j-1) * 8))
    end
    return 0
end
function Monster_mt:VectorOfWeakReferencesLength()
    local o = self.view:Offset(78)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:VectorOfStrongReferrables(j)
    local o = self.view:Offset(80)
    if o ~= 0 then
        local x = self.view:Vector(o)
        x = x + ((j-1) * 4)
        x = self.view:Indirect(x)
        local obj = require('MyGame.Example.Referrable').New()
        obj:Init(self.view.bytes, x)
        return obj
    end
end
function Monster_mt:VectorOfStrongReferrablesLength()
    local o = self.view:Offset(80)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:CoOwningReference()
    local o = self.view:Offset(82)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:VectorOfCoOwningReferences(j)
    local o = self.view:Offset(84)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Uint64, a + ((j-1) * 8))
    end
    return 0
end
function Monster_mt:VectorOfCoOwningReferencesLength()
    local o = self.view:Offset(84)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:NonOwningReference()
    local o = self.view:Offset(86)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint64, o + self.view.pos)
    end
    return 0
end
function Monster_mt:VectorOfNonOwningReferences(j)
    local o = self.view:Offset(88)
    if o ~= 0 then
        local a = self.view:Vector(o)
        return self.view:Get(flatbuffers.N.Uint64, a + ((j-1) * 8))
    end
    return 0
end
function Monster_mt:VectorOfNonOwningReferencesLength()
    local o = self.view:Offset(88)
    if o ~= 0 then
        return self.view:VectorLen(o)
    end
    return 0
end
function Monster_mt:AnyUniqueType()
    local o = self.view:Offset(90)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint8, o + self.view.pos)
    end
    return 0
end
function Monster_mt:AnyUnique()
    local o = self.view:Offset(92)
    if o ~= 0 then
        local obj = flatbuffers.view.New(require('flatbuffers.binaryarray').New(0), 0)
        self.view:Union(obj, o)
        return obj
    end
end
function Monster_mt:AnyAmbiguousType()
    local o = self.view:Offset(94)
    if o ~= 0 then
        return self.view:Get(flatbuffers.N.Uint8, o + self.view.pos)
    end
    return 0
end
function Monster_mt:AnyAmbiguous()
    local o = self.view:Offset(96)
    if o ~= 0 then
        local obj = flatbuffers.view.New(require('flatbuffers.binaryarray').New(0), 0)
        self.view:Union(obj, o)
        return obj
    end
end
function Monster.Start(builder) builder:StartObject(47) end
function Monster.AddPos(builder, pos) builder:PrependStructSlot(0, pos, 0) end
function Monster.AddMana(builder, mana) builder:PrependInt16Slot(1, mana, 150) end
function Monster.AddHp(builder, hp) builder:PrependInt16Slot(2, hp, 100) end
function Monster.AddName(builder, name) builder:PrependUOffsetTRelativeSlot(3, name, 0) end
function Monster.AddInventory(builder, inventory) builder:PrependUOffsetTRelativeSlot(5, inventory, 0) end
function Monster.StartInventoryVector(builder, numElems) return builder:StartVector(1, numElems, 1) end
function Monster.AddColor(builder, color) builder:PrependInt8Slot(6, color, 8) end
function Monster.AddTestType(builder, testType) builder:PrependUint8Slot(7, testType, 0) end
function Monster.AddTest(builder, test) builder:PrependUOffsetTRelativeSlot(8, test, 0) end
function Monster.AddTest4(builder, test4) builder:PrependUOffsetTRelativeSlot(9, test4, 0) end
function Monster.StartTest4Vector(builder, numElems) return builder:StartVector(4, numElems, 2) end
function Monster.AddTestarrayofstring(builder, testarrayofstring) builder:PrependUOffsetTRelativeSlot(10, testarrayofstring, 0) end
function Monster.StartTestarrayofstringVector(builder, numElems) return builder:StartVector(4, numElems, 4) end
function Monster.AddTestarrayoftables(builder, testarrayoftables) builder:PrependUOffsetTRelativeSlot(11, testarrayoftables, 0) end
function Monster.StartTestarrayoftablesVector(builder, numElems) return builder:StartVector(4, numElems, 4) end
function Monster.AddEnemy(builder, enemy) builder:PrependUOffsetTRelativeSlot(12, enemy, 0) end
function Monster.AddTestnestedflatbuffer(builder, testnestedflatbuffer) builder:PrependUOffsetTRelativeSlot(13, testnestedflatbuffer, 0) end
function Monster.StartTestnestedflatbufferVector(builder, numElems) return builder:StartVector(1, numElems, 1) end
function Monster.AddTestempty(builder, testempty) builder:PrependUOffsetTRelativeSlot(14, testempty, 0) end
function Monster.AddTestbool(builder, testbool) builder:PrependBoolSlot(15, testbool, 0) end
function Monster.AddTesthashs32Fnv1(builder, testhashs32Fnv1) builder:PrependInt32Slot(16, testhashs32Fnv1, 0) end
function Monster.AddTesthashu32Fnv1(builder, testhashu32Fnv1) builder:PrependUint32Slot(17, testhashu32Fnv1, 0) end
function Monster.AddTesthashs64Fnv1(builder, testhashs64Fnv1) builder:PrependInt64Slot(18, testhashs64Fnv1, 0) end
function Monster.AddTesthashu64Fnv1(builder, testhashu64Fnv1) builder:PrependUint64Slot(19, testhashu64Fnv1, 0) end
function Monster.AddTesthashs32Fnv1a(builder, testhashs32Fnv1a) builder:PrependInt32Slot(20, testhashs32Fnv1a, 0) end
function Monster.AddTesthashu32Fnv1a(builder, testhashu32Fnv1a) builder:PrependUint32Slot(21, testhashu32Fnv1a, 0) end
function Monster.AddTesthashs64Fnv1a(builder, testhashs64Fnv1a) builder:PrependInt64Slot(22, testhashs64Fnv1a, 0) end
function Monster.AddTesthashu64Fnv1a(builder, testhashu64Fnv1a) builder:PrependUint64Slot(23, testhashu64Fnv1a, 0) end
function Monster.AddTestarrayofbools(builder, testarrayofbools) builder:PrependUOffsetTRelativeSlot(24, testarrayofbools, 0) end
function Monster.StartTestarrayofboolsVector(builder, numElems) return builder:StartVector(1, numElems, 1) end
function Monster.AddTestf(builder, testf) builder:PrependFloat32Slot(25, testf, 3.14159) end
function Monster.AddTestf2(builder, testf2) builder:PrependFloat32Slot(26, testf2, 3.0) end
function Monster.AddTestf3(builder, testf3) builder:PrependFloat32Slot(27, testf3, 0.0) end
function Monster.AddTestarrayofstring2(builder, testarrayofstring2) builder:PrependUOffsetTRelativeSlot(28, testarrayofstring2, 0) end
function Monster.StartTestarrayofstring2Vector(builder, numElems) return builder:StartVector(4, numElems, 4) end
function Monster.AddTestarrayofsortedstruct(builder, testarrayofsortedstruct) builder:PrependUOffsetTRelativeSlot(29, testarrayofsortedstruct, 0) end
function Monster.StartTestarrayofsortedstructVector(builder, numElems) return builder:StartVector(8, numElems, 4) end
function Monster.AddFlex(builder, flex) builder:PrependUOffsetTRelativeSlot(30, flex, 0) end
function Monster.StartFlexVector(builder, numElems) return builder:StartVector(1, numElems, 1) end
function Monster.AddTest5(builder, test5) builder:PrependUOffsetTRelativeSlot(31, test5, 0) end
function Monster.StartTest5Vector(builder, numElems) return builder:StartVector(4, numElems, 2) end
function Monster.AddVectorOfLongs(builder, vectorOfLongs) builder:PrependUOffsetTRelativeSlot(32, vectorOfLongs, 0) end
function Monster.StartVectorOfLongsVector(builder, numElems) return builder:StartVector(8, numElems, 8) end
function Monster.AddVectorOfDoubles(builder, vectorOfDoubles) builder:PrependUOffsetTRelativeSlot(33, vectorOfDoubles, 0) end
function Monster.StartVectorOfDoublesVector(builder, numElems) return builder:StartVector(8, numElems, 8) end
function Monster.AddParentNamespaceTest(builder, parentNamespaceTest) builder:PrependUOffsetTRelativeSlot(34, parentNamespaceTest, 0) end
function Monster.AddVectorOfReferrables(builder, vectorOfReferrables) builder:PrependUOffsetTRelativeSlot(35, vectorOfReferrables, 0) end
function Monster.StartVectorOfReferrablesVector(builder, numElems) return builder:StartVector(4, numElems, 4) end
function Monster.AddSingleWeakReference(builder, singleWeakReference) builder:PrependUint64Slot(36, singleWeakReference, 0) end
function Monster.AddVectorOfWeakReferences(builder, vectorOfWeakReferences) builder:PrependUOffsetTRelativeSlot(37, vectorOfWeakReferences, 0) end
function Monster.StartVectorOfWeakReferencesVector(builder, numElems) return builder:StartVector(8, numElems, 8) end
function Monster.AddVectorOfStrongReferrables(builder, vectorOfStrongReferrables) builder:PrependUOffsetTRelativeSlot(38, vectorOfStrongReferrables, 0) end
function Monster.StartVectorOfStrongReferrablesVector(builder, numElems) return builder:StartVector(4, numElems, 4) end
function Monster.AddCoOwningReference(builder, coOwningReference) builder:PrependUint64Slot(39, coOwningReference, 0) end
function Monster.AddVectorOfCoOwningReferences(builder, vectorOfCoOwningReferences) builder:PrependUOffsetTRelativeSlot(40, vectorOfCoOwningReferences, 0) end
function Monster.StartVectorOfCoOwningReferencesVector(builder, numElems) return builder:StartVector(8, numElems, 8) end
function Monster.AddNonOwningReference(builder, nonOwningReference) builder:PrependUint64Slot(41, nonOwningReference, 0) end
function Monster.AddVectorOfNonOwningReferences(builder, vectorOfNonOwningReferences) builder:PrependUOffsetTRelativeSlot(42, vectorOfNonOwningReferences, 0) end
function Monster.StartVectorOfNonOwningReferencesVector(builder, numElems) return builder:StartVector(8, numElems, 8) end
function Monster.AddAnyUniqueType(builder, anyUniqueType) builder:PrependUint8Slot(43, anyUniqueType, 0) end
function Monster.AddAnyUnique(builder, anyUnique) builder:PrependUOffsetTRelativeSlot(44, anyUnique, 0) end
function Monster.AddAnyAmbiguousType(builder, anyAmbiguousType) builder:PrependUint8Slot(45, anyAmbiguousType, 0) end
function Monster.AddAnyAmbiguous(builder, anyAmbiguous) builder:PrependUOffsetTRelativeSlot(46, anyAmbiguous, 0) end
function Monster.End(builder) return builder:EndObject() end

return Monster -- return the module