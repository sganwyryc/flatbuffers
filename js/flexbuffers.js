var flexbuffers = {};

flexbuffers.BitWidth = {
  WIDTH8: 0,
  WIDTH16: 1,
  WIDTH32: 2,
  WIDTH64: 3,
};

flexbuffers.BitWidthUtil = {};

flexbuffers.BitWidthUtil.toByteWidth = (bitWidth) => {
  return 1 << bitWidth;
};

flexbuffers.BitWidthUtil.iwidth = (value) => {
  if (value >= -128 && value <= 127) return 0/*flexbuffers.BitWidth.WIDTH8*/;
  if (value >= -32768 && value <= 32767) return 1/*flexbuffers.BitWidth.WIDTH16*/;
  if (value >= -2147483648 && value <= 2147483647) return 2/*flexbuffers.BitWidth.WIDTH32*/;
  return 3/*flexbuffers.BitWidth.WIDTH64*/;
};

flexbuffers.BitWidthUtil.fwidth = (value) => {
  return value === Math.fround(value) ? 2 /*flexbuffers.BitWidth.WIDTH32*/: 3 /*flexbuffers.BitWidth.WIDTH64*/;
};

flexbuffers.BitWidthUtil.uwidth = (value) => {
  if (value <= 255) return 0; //flexbuffers.BitWidth.WIDTH8;
  if (value <= 65535) return 1; //flexbuffers.BitWidth.WIDTH16;
  if (value <= 4294967295) return 2; //flexbuffers.BitWidth.WIDTH32;
  return 3; //flexbuffers.BitWidth.WIDTH64;
};

flexbuffers.BitWidthUtil.fromByteWidth = (value) => {
  if (value === 1) return 0; //flexbuffers.BitWidth.WIDTH8;
  if (value === 2) return 1; //flexbuffers.BitWidth.WIDTH16;
  if (value === 4) return 2; //flexbuffers.BitWidth.WIDTH32;
  return 3; //flexbuffers.BitWidth.WIDTH64;
};

flexbuffers.BitWidthUtil.paddingSize = (bufSize, scalarSize) => {
  return (~bufSize + 1) & (scalarSize - 1);
};

flexbuffers.ValueType = {
  NULL: 0,
  INT: 1,
  UINT: 2,
  FLOAT: 3,
  KEY: 4,
  STRING: 5,
  INDIRECT_INT: 6,
  INDIRECT_UINT: 7,
  INDIRECT_FLOAT: 8,
  MAP: 9,
  VECTOR: 10,
  VECTOR_INT: 11,
  VECTOR_UINT: 12,
  VECTOR_FLOAT: 13,
  VECTOR_KEY: 14,
  VECTOR_STRING_DEPRECATED: 15,
  VECTOR_INT2: 16,
  VECTOR_UINT2: 17,
  VECTOR_FLOAT2: 18,
  VECTOR_INT3: 19,
  VECTOR_UINT3: 20,
  VECTOR_FLOAT3: 21,
  VECTOR_INT4: 22,
  VECTOR_UINT4: 23,
  VECTOR_FLOAT4: 24,
  BLOB: 25,
  BOOL: 26,
  VECTOR_BOOL: 36,
};

flexbuffers.ValueTypeUtil = {};

flexbuffers.ValueTypeUtil.isInline = (value) => {
  return value === flexbuffers.ValueType.BOOL
    || value <= flexbuffers.ValueType.FLOAT;
};

flexbuffers.ValueTypeUtil.isNumber = (value) => {
  return value >= flexbuffers.ValueType.INT
    && value <= flexbuffers.ValueType.FLOAT;
};

flexbuffers.ValueTypeUtil.isIndirectNumber = (value) => {
  return value >= flexbuffers.ValueType.INDIRECT_INT
    && value <= flexbuffers.ValueType.INDIRECT_FLOAT;
};

flexbuffers.ValueTypeUtil.isTypedVectorElement = (value) => {
  return value === flexbuffers.ValueType.BOOL
    || (value >= flexbuffers.ValueType.INT
      && value <= flexbuffers.ValueType.STRING);
};

flexbuffers.ValueTypeUtil.isTypedVector = (value) => {
  return value === flexbuffers.ValueType.VECTOR_BOOL
    || (value >= flexbuffers.ValueType.VECTOR_INT
      && value <= flexbuffers.ValueType.VECTOR_STRING_DEPRECATED);
};

flexbuffers.ValueTypeUtil.isFixedTypedVector = (value) => {
  return value >= flexbuffers.ValueType.VECTOR_INT2
    && value <= flexbuffers.ValueType.VECTOR_FLOAT4;
};

flexbuffers.ValueTypeUtil.isAVector = (value) => {
  return flexbuffers.ValueTypeUtil.isTypedVector(value)
    || flexbuffers.ValueTypeUtil.isFixedTypedVector(value)
    || value === flexbuffers.ValueType.VECTOR;
};

flexbuffers.ValueTypeUtil.toTypedVector = (valueType, length) => {
  if (length === 0) return valueType - flexbuffers.ValueType.INT + flexbuffers.ValueType.VECTOR_INT;
  if (length === 2) return valueType - flexbuffers.ValueType.INT + flexbuffers.ValueType.VECTOR_INT2;
  if (length === 3) return valueType - flexbuffers.ValueType.INT + flexbuffers.ValueType.VECTOR_INT3;
  if (length === 4) return valueType - flexbuffers.ValueType.INT + flexbuffers.ValueType.VECTOR_INT4;
  throw "Unexpected length " + length;
};

flexbuffers.ValueTypeUtil.typedVectorElementType = (valueType) => {
  return valueType - flexbuffers.ValueType.VECTOR_INT + flexbuffers.ValueType.INT;
};

flexbuffers.ValueTypeUtil.fixedTypedVectorElementType = (valueType) => {
  return ((valueType - flexbuffers.ValueType.VECTOR_INT2) % 3) + flexbuffers.ValueType.INT;
};

flexbuffers.ValueTypeUtil.fixedTypedVectorElementSize = (valueType) => {
  // The x / y >> 0 trick is to have an int division. Suppose to be faster than Math.floor()
  return (((valueType - flexbuffers.ValueType.VECTOR_INT2) / 3) >> 0)  + 2;
};

flexbuffers.ValueTypeUtil.packedType = (valueType, bitWidth) => {
  return bitWidth | (valueType << 2);
};

flexbuffers.toReference = (buffer) => {

  // Add to readInt, readUInt, readFloat in order to check for offset bugs
  function validateOffset(dataView, offset, width) {
    if (dataView.byteLength <= offset + width || offset & (flexbuffers.BitWidthUtil.toByteWidth(width) - 1) !== 0) {
      throw "Bad offset: " + offset + ", width: " + width;
    }
  }

  function readInt(dataView, offset, width) {
    if (width < 2) {
      if (width < 1) {
        return dataView.getInt8(offset);
      } else {
        return dataView.getInt16(offset, true);
      }
    } else {
      if (width < 3) {
        return dataView.getInt32(offset, true)
      } else {
        if (dataView.setBigInt64 === undefined) {
          return {
            low: dataView.getInt32(offset, true),
            high: dataView.getInt32(offset + 4, true)
          }
        }
        return dataView.getBigInt64(offset, true)
      }
    }
  }

  function readUInt(dataView, offset, width) {
    if (width < 2) {
      if (width < 1) {
        return dataView.getUint8(offset);
      } else {
        return dataView.getUint16(offset, true);
      }
    } else {
      if (width < 3) {
        return dataView.getUint32(offset, true)
      } else {
        if (dataView.getBigUint64 === undefined) {
          return {
            low: dataView.getUint32(offset, true),
            high: dataView.getUint32(offset + 4, true)
          }
        }
        return dataView.getBigUint64(offset, true)
      }
    }
  }

  function readFloat(dataView, offset, width) {
    if (width < 2 /*flexbuffers.BitWidth.WIDTH32*/) {
      throw "Bad width: " + width;
    }
    if (width === 2 /*flexbuffers.BitWidth.WIDTH32*/) {
      return dataView.getFloat32(offset, true);
    }
    return dataView.getFloat64(offset, true);
  }

  function indirect(dataView, offset, width) {
    const step = readUInt(dataView, offset, width);
    return offset - step;
  }

  function keyIndex(key, dataView, offset, parentWidth, byteWidth, length) {
    const input = toUTF8Array(key);
    const keysVectorOffset = indirect(dataView, offset, parentWidth) - byteWidth * 3;
    const bitWidth = flexbuffers.BitWidthUtil.fromByteWidth(byteWidth);
    const indirectOffset = keysVectorOffset - readUInt(dataView, keysVectorOffset, bitWidth);
    const _byteWidth = readUInt(dataView, keysVectorOffset + byteWidth, bitWidth);
    let low = 0;
    let high = length - 1;
    while (low <= high) {
      const mid = (high + low) >> 1;
      const dif = diffKeys(input, mid, dataView, indirectOffset, _byteWidth);
      if (dif === 0) return mid;
      if (dif < 0) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return null;
  }

  function diffKeys(input, index, dataView, offset, width) {
    const keyOffset = offset + index * width;
    const keyIndirectOffset = keyOffset - readUInt(dataView, keyOffset, flexbuffers.BitWidthUtil.fromByteWidth(width));
    for (let i = 0; i < input.length; i++) {
      const dif = input[i] - dataView.getUint8(keyIndirectOffset + i);
      if (dif !== 0) {
        return dif;
      }
    }
    return dataView.getUint8(keyIndirectOffset + input.length) === 0 ? 0 : -1;
  }

  function valueForIndexWithKey(index, key, dataView, offset, parentWidth, byteWidth, length, path) {
    const _indirect = indirect(dataView, offset, parentWidth);
    const elementOffset = _indirect + index * byteWidth;
    const packedType = dataView.getUint8(_indirect + length * byteWidth + index);
    return Reference(dataView, elementOffset, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth), packedType, `${path}/${key}`)
  }

  function keyForIndex(index, dataView, offset, parentWidth, byteWidth) {
    const keysVectorOffset = indirect(dataView, offset, parentWidth) - byteWidth * 3;
    const bitWidth = flexbuffers.BitWidthUtil.fromByteWidth(byteWidth);
    const indirectOffset = keysVectorOffset - readUInt(dataView, keysVectorOffset, bitWidth);
    const _byteWidth = readUInt(dataView, keysVectorOffset + byteWidth, bitWidth);
    const keyOffset = indirectOffset + index * _byteWidth;
    const keyIndirectOffset = keyOffset - readUInt(dataView, keyOffset, flexbuffers.BitWidthUtil.fromByteWidth(_byteWidth));
    let length = 0;
    while (dataView.getUint8(keyIndirectOffset + length) !== 0) {
      length++;
    }
    return fromUTF8Array(new Uint8Array(dataView.buffer, keyIndirectOffset, length));
  }

  function Reference(dataView, offset, parentWidth, packedType, path) {
    const byteWidth = 1 << (packedType & 3);
    const valueType = packedType >> 2;
    let length = -1;
    return {
      isNull: function() { return valueType === flexbuffers.ValueType.NULL; },
      isNumber: function() { return flexbuffers.ValueTypeUtil.isNumber(valueType) || flexbuffers.ValueTypeUtil.isIndirectNumber(valueType); },
      isFloat: function() { return flexbuffers.ValueType.FLOAT === valueType || flexbuffers.ValueType.INDIRECT_FLOAT === valueType; },
      isInt: function() { return this.isNumber() && !this.isFloat(); },
      isString: function() { return flexbuffers.ValueType.STRING === valueType || flexbuffers.ValueType.KEY === valueType; },
      isBool: function() { return flexbuffers.ValueType.BOOL === valueType; },
      isBlob: function() { return flexbuffers.ValueType.BLOB === valueType; },
      isVector: function() { return flexbuffers.ValueTypeUtil.isAVector(valueType); },
      isMap: function() { return flexbuffers.ValueType.MAP === valueType; },

      boolValue: function() {
        if (this.isBool()) {
          return readInt(dataView, offset, parentWidth) > 0;
        }
        return null;
      },

      intValue: function() {
        if (valueType === flexbuffers.ValueType.INT) {
          return readInt(dataView, offset, parentWidth);
        }
        if (valueType === flexbuffers.ValueType.UINT) {
          return readUInt(dataView, offset, parentWidth);
        }
        if (valueType === flexbuffers.ValueType.INDIRECT_INT) {
          return readInt(dataView, indirect(dataView, offset, parentWidth), flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
        }
        if (valueType === flexbuffers.ValueType.INDIRECT_UINT) {
          return readUInt(dataView, indirect(dataView, offset, parentWidth), flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
        }
        return null;
      },

      floatValue: function() {
        if (valueType === flexbuffers.ValueType.FLOAT) {
          return readFloat(dataView, offset, parentWidth);
        }
        if (valueType === flexbuffers.ValueType.INDIRECT_FLOAT) {
          return readFloat(dataView, indirect(dataView, offset, parentWidth), flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
        }
        return null;
      },

      numericValue: function() { return this.floatValue() || this.intValue()},

      stringValue: function() {
        if (valueType === flexbuffers.ValueType.STRING || valueType === flexbuffers.ValueType.KEY) {
          const begin = indirect(dataView, offset, parentWidth);
          return fromUTF8Array(new Uint8Array(dataView.buffer, begin, this.length()));
        }
        return null;
      },

      blobValue: function() {
        if (this.isBlob()) {
          const begin = indirect(dataView, offset, parentWidth);
          return new Uint8Array(dataView.buffer, begin, this.length());
        }
        return null;
      },

      get: function(key) {
        const length = this.length();
        if (Number.isInteger(key) && flexbuffers.ValueTypeUtil.isAVector(valueType)) {
          if (key >= length || key < 0) {
            throw `Key: [${key}] is not applicable on ${path} of ${valueType} length: ${length}`;
          }
          const _indirect = indirect(dataView, offset, parentWidth);
          const elementOffset = _indirect + key * byteWidth;
          let _packedType = dataView.getUint8(_indirect + length * byteWidth + key);
          if (flexbuffers.ValueTypeUtil.isTypedVector(valueType)) {
            const _valueType = flexbuffers.ValueTypeUtil.typedVectorElementType(valueType);
            _packedType = flexbuffers.ValueTypeUtil.packedType(_valueType, flexbuffers.BitWidth.WIDTH8);
          } else if (flexbuffers.ValueTypeUtil.isFixedTypedVector(valueType)) {
            const _valueType = flexbuffers.ValueTypeUtil.fixedTypedVectorElementType(valueType);
            _packedType = flexbuffers.ValueTypeUtil.packedType(_valueType, flexbuffers.BitWidth.WIDTH8);
          }
          return Reference(dataView, elementOffset, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth), _packedType, `${path}[${key}]`);
        }
        if (typeof key === 'string') {
          const index = keyIndex(key, dataView, offset, parentWidth, byteWidth, length);
          if (index !== null) {
            return valueForIndexWithKey(index, key, dataView, offset, parentWidth, byteWidth, length, path)
          }
        }
        throw `Key [${key}] is not applicable on ${path} of ${valueType}`;
      },

      length: function() {
        let size;
        if (length > -1) {
          return length;
        }
        if (flexbuffers.ValueTypeUtil.isFixedTypedVector(valueType)) {
          length = flexbuffers.ValueTypeUtil.fixedTypedVectorElementSize(valueType);
        } else if (valueType === flexbuffers.ValueType.BLOB
          || valueType === flexbuffers.ValueType.MAP
          || flexbuffers.ValueTypeUtil.isAVector(valueType)) {
          length = readUInt(dataView, indirect(dataView, offset, parentWidth) - byteWidth, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth))
        } else if (valueType === flexbuffers.ValueType.NULL) {
          length = 0;
        } else if (valueType === flexbuffers.ValueType.STRING) {
          const _indirect = indirect(dataView, offset, parentWidth);
          let sizeByteWidth = byteWidth;
          size = readUInt(dataView, _indirect - sizeByteWidth, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
          while (dataView.getInt8(_indirect + size) !== 0) {
            sizeByteWidth <<= 1;
            size = readUInt(dataView, _indirect - sizeByteWidth, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
          }
          length = size;
        } else if (valueType === flexbuffers.ValueType.KEY) {
          const _indirect = indirect(dataView, offset, parentWidth);
          size = 1;
          while (dataView.getInt8(_indirect + size) !== 0) {
            size++;
          }
          length = size;
        } else {
          length = 1;
        }
        return length;
      },

      toObject: function() {
        const length = this.length();
        if (this.isVector()) {
          let result = [];
          for (let i = 0; i < length; i++) {
            result.push(this.get(i).toObject());
          }
          return result;
        }
        if (this.isMap()) {
          let result = {};
          for (let i = 0; i < length; i++) {
            let key = keyForIndex(i, dataView, offset, parentWidth, byteWidth);
            result[key] = valueForIndexWithKey(i, key, dataView, offset, parentWidth, byteWidth, length, path).toObject();
          }
          return result;
        }
        if (this.isNull()) {
          return null;
        }
        if (this.isBool()) {
          return this.boolValue();
        }
        if (this.isNumber()) {
          return this.numericValue();
        }
        return this.blobValue() || this.stringValue();
      }
    }
  }

  const len = buffer.byteLength;

  if (len < 3) {
    throw "Buffer needs to be bigger than 3";
  }

  const dataView = new DataView(buffer);
  const byteWidth = dataView.getUint8(len - 1);
  const packedType = dataView.getUint8(len - 2);
  const parentWidth = flexbuffers.BitWidthUtil.fromByteWidth(byteWidth);
  const offset = len - byteWidth - 2;

  return Reference(dataView, offset, parentWidth, packedType, "/")
};

flexbuffers.toObject = (buffer) => {
  return flexbuffers.toReference(buffer).toObject();
};

flexbuffers.builder = (size = 2048, deduplicateString = true, deduplicateKeys = true, deduplicateKeyVectors = true) => {
  let buffer = new ArrayBuffer(size > 0 ? size : 2048);
  let view = new DataView(buffer);
  const stack = [];
  const stackPointers = [];
  let offset = 0;
  let finished = false;
  const stringLookup = {};
  const keyLookup = {};
  const keyVectorLookup = {};
  const indirectIntLookup = {};
  const indirectUIntLookup = {};
  const indirectFloatLookup = {};

  let dedupStrings = deduplicateString;
  let dedupKeys = deduplicateKeys;
  let dedupKeyVectors = deduplicateKeyVectors;

  function align(width) {
    const byteWidth = flexbuffers.BitWidthUtil.toByteWidth(width);
    offset += flexbuffers.BitWidthUtil.paddingSize(offset, byteWidth);
    return byteWidth;
  }

  function computeOffset(newValueSize) {
    const targetOffset = offset + newValueSize;
    let size = buffer.byteLength;
    const prevSize = size;
    while (size < targetOffset) {
      size <<= 1;
    }
    if (prevSize < size) {
      const prevBuffer = buffer;
      buffer = new ArrayBuffer(size);
      view = new DataView(buffer);
      new Uint8Array(buffer).set(new Uint8Array(prevBuffer), 0);
    }
    return targetOffset;
  }

  function pushInt(value, width) {
    if (width === flexbuffers.BitWidth.WIDTH8) {
      view.setInt8(offset, value);
    } else if (width === flexbuffers.BitWidth.WIDTH16) {
      view.setInt16(offset, value, true);
    } else if (width === flexbuffers.BitWidth.WIDTH32) {
      view.setInt32(offset, value, true);
    } else if (width === flexbuffers.BitWidth.WIDTH64) {
      view.setBigInt64(offset, BigInt(value), true);
    } else {
      throw `Unexpected width: ${width} for value: ${value}`;
    }
  }

  function pushUInt(value, width) {
    if (width === flexbuffers.BitWidth.WIDTH8) {
      view.setUint8(offset, value);
    } else if (width === flexbuffers.BitWidth.WIDTH16) {
      view.setUint16(offset, value, true);
    } else if (width === flexbuffers.BitWidth.WIDTH32) {
      view.setUint32(offset, value, true);
    } else if (width === flexbuffers.BitWidth.WIDTH64) {
      view.setBigUint64(offset, BigInt(value), true);
    } else {
      throw `Unexpected width: ${width} for value: ${value}`;
    }
  }

  function writeInt(value, byteWidth) {
    const newOffset = computeOffset(byteWidth);
    pushInt(value, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
    offset = newOffset;
  }

  function writeUInt(value, byteWidth) {
    const newOffset = computeOffset(byteWidth);
    pushUInt(value, flexbuffers.BitWidthUtil.fromByteWidth(byteWidth));
    offset = newOffset;
  }

  function writeBlob(arrayBuffer) {
    const length = arrayBuffer.byteLength;
    const bitWidth = flexbuffers.BitWidthUtil.uwidth(length);
    const byteWidth = align(bitWidth);
    writeUInt(length, byteWidth);
    const blobOffset = offset;
    const newOffset = computeOffset(length);
    new Uint8Array(buffer).set(new Uint8Array(arrayBuffer), blobOffset);
    stack.push(offsetStackValue(blobOffset, flexbuffers.ValueType.BLOB, bitWidth));
    offset = newOffset;
  }

  function writeString(str) {
    if (dedupStrings && stringLookup.hasOwnProperty(str)) {
      stack.push(stringLookup[str]);
      return;
    }
    const utf8 = toUTF8Array(str);
    const length = utf8.length;
    const bitWidth = flexbuffers.BitWidthUtil.uwidth(length);
    const byteWidth = align(bitWidth);
    writeUInt(length, byteWidth);
    const stringOffset = offset;
    const newOffset = computeOffset(length + 1);
    new Uint8Array(buffer).set(utf8, stringOffset);
    const stackValue = offsetStackValue(stringOffset, flexbuffers.ValueType.STRING, bitWidth);
    stack.push(stackValue);
    if (dedupStrings) {
      stringLookup[str] = stackValue;
    }
    offset = newOffset;
  }

  function writeKey(str) {
    if (dedupKeys && keyLookup.hasOwnProperty(str)) {
      stack.push(keyLookup[str]);
      return;
    }
    const utf8 = toUTF8Array(str);
    const length = utf8.length;
    const newOffset = computeOffset(length + 1);
    new Uint8Array(buffer).set(utf8, offset);
    const stackValue = offsetStackValue(offset, flexbuffers.ValueType.KEY, flexbuffers.BitWidth.WIDTH8);
    stack.push(stackValue);
    if (dedupKeys) {
      keyLookup[str] = stackValue;
    }
    offset = newOffset;
  }

  function writeStackValue(value, byteWidth) {
    const newOffset = computeOffset(byteWidth);
    if (value.isOffset) {
      const relativeOffset = offset - value.offset;
      if (byteWidth === 8 || BigInt(relativeOffset) < (1n << BigInt(byteWidth * 8))) {
        writeUInt(relativeOffset, byteWidth);
      } else {
        throw `Unexpected size ${byteWidth}. This might be a bug. Please create an issue https://github.com/google/flatbuffers/issues/new`
      }
    } else {
      value.writeToBuffer(byteWidth);
    }
    offset = newOffset;
  }

  function integrityCheckOnValueAddition() {
    if (finished) {
      throw "Adding values after finish is prohibited";
    }
    if (stackPointers.length !== 0 && stackPointers[stackPointers.length - 1].isVector === false) {
      if (stack[stack.length - 1].type !== flexbuffers.ValueType.KEY) {
        throw "Adding value to a map before adding a key is prohibited";
      }
    }
  }

  function integrityCheckOnKeyAddition() {
    if (finished) {
      throw "Adding values after finish is prohibited";
    }
    if (stackPointers.length === 0 || stackPointers[stackPointers.length - 1].isVector) {
      throw "Adding key before starting a map is prohibited";
    }
  }

  function startVector() {
    stackPointers.push({stackPosition: stack.length, isVector: true});
  }

  function startMap(presorted = false) {
    stackPointers.push({stackPosition: stack.length, isVector: false, presorted: presorted});
  }

  function endVector(stackPointer) {
    const vecLength = stack.length - stackPointer.stackPosition;
    const vec = createVector(stackPointer.stackPosition, vecLength, 1);
    stack.splice(stackPointer.stackPosition, vecLength);
    stack.push(vec);
  }

  function endMap(stackPointer) {
    if (!stackPointer.presorted) {
      sort(stackPointer);
    }
    let keyVectorHash = "";
    for (let i = stackPointer.stackPosition; i < stack.length; i += 2) {
      keyVectorHash += `,${stack[i].offset}`;
    }
    const vecLength = (stack.length - stackPointer.stackPosition) >> 1;

    if (dedupKeyVectors && !keyVectorLookup.hasOwnProperty(keyVectorHash)) {
      keyVectorLookup[keyVectorHash] = createVector(stackPointer.stackPosition, vecLength, 2);
    }
    const keysStackValue = dedupKeyVectors ? keyVectorLookup[keyVectorHash] : createVector(stackPointer.stackPosition, vecLength, 2);
    const valuesStackValue = createVector(stackPointer.stackPosition + 1, vecLength, 2, keysStackValue);
    stack.splice(stackPointer.stackPosition, vecLength << 1);
    stack.push(valuesStackValue);
  }

  function sort(stackPointer) {
    function shouldFlip(v1, v2) {
      if (v1.type !== flexbuffers.ValueType.KEY || v2.type !== flexbuffers.ValueType.KEY) {
        throw `Stack values are not keys ${v1} | ${v2}. Check if you combined [addKey] with add... method calls properly.`
      }
      let c1, c2;
      let index = 0;
      do {
        c1 = view.getUint8(v1.offset + index);
        c2 = view.getUint8(v2.offset + index);
        if (c2 < c1) return true;
        if (c1 < c2) return false;
        index += 1;
      } while (c1 !== 0 && c2 !== 0);
      return false;
    }

    function swap(stack, flipIndex, i) {
      if (flipIndex === i) return;
      const k = stack[flipIndex];
      const v = stack[flipIndex + 1];
      stack[flipIndex] = stack[i];
      stack[flipIndex + 1] = stack[i + 1];
      stack[i] = k;
      stack[i + 1] = v;
    }

    function selectionSort() {
      for (let i = stackPointer.stackPosition; i < stack.length; i += 2) {
        let flipIndex = i;
        for (let j = i + 2; j < stack.length; j += 2) {
          if (shouldFlip(stack[flipIndex], stack[j])) {
            flipIndex = j;
          }
        }
        if (flipIndex !== i) {
          swap(stack, flipIndex, i);
        }
      }
    }

    function smaller(v1, v2) {
      if (v1.type !== flexbuffers.ValueType.KEY || v2.type !== flexbuffers.ValueType.KEY) {
        throw `Stack values are not keys ${v1} | ${v2}. Check if you combined [addKey] with add... method calls properly.`
      }
      if(v1.offset === v2.offset) {
        return false;
      }
      let c1, c2;
      let index = 0;
      do {
        c1 = view.getUint8(v1.offset + index);
        c2 = view.getUint8(v2.offset + index);
        if(c1 < c2) return true;
        if(c2 < c1) return false;
        index += 1;
      } while (c1 !== 0 && c2 !== 0);
      return false;
    }

    function quickSort(left, right) {

      if (left < right) {
        let mid = left + (((right - left) >> 2)) * 2;
        let pivot = stack[mid],
          left_new = left,
          right_new = right;

        do {
          while (smaller(stack[left_new], pivot)) {
            left_new += 2;
          }
          while (smaller(pivot, stack[right_new])) {
            right_new -= 2;
          }
          if (left_new <= right_new) {
            swap(stack, left_new, right_new);
            left_new += 2;
            right_new -= 2;
          }
        } while (left_new <= right_new);

        quickSort(left, right_new);
        quickSort(left_new, right);

      }
    }

    let sorted = true;
    for (let i = stackPointer.stackPosition; i < stack.length - 2; i += 2) {
      if (shouldFlip(stack[i], stack[i + 2])) {
        sorted = false;
        break;
      }
    }

    if (!sorted) {
      if (stack.length - stackPointer.stackPosition > 40) {
        quickSort(stackPointer.stackPosition, stack.length - 2);
      } else {
        selectionSort();
      }
    }
  }

  function end() {
    if (stackPointers.length < 1) return;
    const pointer = stackPointers.pop();
    if (pointer.isVector) {
      endVector(pointer);
    } else {
      endMap(pointer);
    }
  }

  function createVector(start, vecLength, step, keys = null) {
    let bitWidth = flexbuffers.BitWidthUtil.uwidth(vecLength);
    let prefixElements = 1;
    if (keys !== null) {
      const elementWidth = keys.elementWidth(offset, 0);
      if (elementWidth > bitWidth) {
        bitWidth = elementWidth;
      }
      prefixElements += 2;
    }
    let vectorType = flexbuffers.ValueType.KEY;
    let typed = keys === null;
    for (let i = start; i < stack.length; i += step) {
      const elementWidth = stack[i].elementWidth(offset, i + prefixElements);
      if (elementWidth > bitWidth) {
        bitWidth = elementWidth;
      }
      if (i === start) {
        vectorType = stack[i].type;
        typed &= flexbuffers.ValueTypeUtil.isTypedVectorElement(vectorType);
      } else {
        if (vectorType !== stack[i].type) {
          typed = false;
        }
      }
    }
    const byteWidth = align(bitWidth);
    const fix = typed && flexbuffers.ValueTypeUtil.isNumber(vectorType) && vecLength >= 2 && vecLength <= 4;
    if (keys !== null) {
      writeStackValue(keys, byteWidth);
      writeUInt(1 << keys.width, byteWidth);
    }
    if (!fix) {
      writeUInt(vecLength, byteWidth);
    }
    const vecOffset = offset;
    for (let i = start; i < stack.length; i += step) {
      writeStackValue(stack[i], byteWidth);
    }
    if (!typed) {
      for (let i = start; i < stack.length; i += step) {
        writeUInt(stack[i].storedPackedType(), 1);
      }
    }
    if (keys !== null) {
      return offsetStackValue(vecOffset, flexbuffers.ValueType.MAP, bitWidth);
    }
    if (typed) {
      const vType = flexbuffers.ValueTypeUtil.toTypedVector(vectorType, fix ? vecLength : 0);
      return offsetStackValue(vecOffset, vType, bitWidth);
    }
    return offsetStackValue(vecOffset, flexbuffers.ValueType.VECTOR, bitWidth);
  }

  function StackValue(type, width, value, _offset) {
    return {
      type: type,
      width: width,
      value: value,
      offset: _offset,
      elementWidth: function (size, index) {
        if (flexbuffers.ValueTypeUtil.isInline(this.type)) return this.width;
        for (let i = 0; i < 4; i++) {
          const width = 1 << i;
          const offsetLoc = size + flexbuffers.BitWidthUtil.paddingSize(size, width) + index * width;
          const offset = offsetLoc - this.offset;
          const bitWidth = flexbuffers.BitWidthUtil.uwidth(offset);
          if (1 << bitWidth === width) {
            return bitWidth;
          }
        }
        throw `Element is unknown. Size: ${size} at index: ${index}. This might be a bug. Please create an issue https://github.com/google/flatbuffers/issues/new`;
      },
      writeToBuffer: function (byteWidth) {
        const newOffset = computeOffset(byteWidth);
        if (this.type === flexbuffers.ValueType.FLOAT) {
          if (this.width === flexbuffers.BitWidth.WIDTH32) {
            view.setFloat32(offset, this.value, true);
          } else {
            view.setFloat64(offset, this.value, true);
          }
        } else if (this.type === flexbuffers.ValueType.INT) {
          const bitWidth = flexbuffers.BitWidthUtil.fromByteWidth(byteWidth);
          pushInt(value, bitWidth);
        } else if (this.type === flexbuffers.ValueType.UINT) {
          const bitWidth = flexbuffers.BitWidthUtil.fromByteWidth(byteWidth);
          pushUInt(value, bitWidth);
        } else if (this.type === flexbuffers.ValueType.NULL) {
          pushInt(0, this.width);
        } else if (this.type === flexbuffers.ValueType.BOOL) {
          pushInt(value ? 1 : 0, this.width);
        } else {
          throw `Unexpected type: ${type}. This might be a bug. Please create an issue https://github.com/google/flatbuffers/issues/new`
        }
        offset = newOffset;
      },
      storedWidth: function (width = flexbuffers.BitWidth.WIDTH8) {
        return flexbuffers.ValueTypeUtil.isInline(this.type) ? Math.max(width, this.width) : this.width;
      },
      storedPackedType: function (width = flexbuffers.BitWidth.WIDTH8) {
        return flexbuffers.ValueTypeUtil.packedType(this.type, this.storedWidth(width));
      },
      isOffset: !flexbuffers.ValueTypeUtil.isInline(type)
    }
  }

  function nullStackValue() {
    return StackValue(flexbuffers.ValueType.NULL, flexbuffers.BitWidth.WIDTH8);
  }

  function boolStackValue(value) {
    return StackValue(flexbuffers.ValueType.BOOL, flexbuffers.BitWidth.WIDTH8, value);
  }

  function intStackValue(value) {
    return StackValue(flexbuffers.ValueType.INT, flexbuffers.BitWidthUtil.iwidth(value), value);
  }

  function uintStackValue(value) {
    return StackValue(flexbuffers.ValueType.UINT, flexbuffers.BitWidthUtil.uwidth(value), value);
  }

  function floatStackValue(value) {
    return StackValue(flexbuffers.ValueType.FLOAT, flexbuffers.BitWidthUtil.fwidth(value), value);
  }

  function offsetStackValue(offset, valueType, bitWidth) {
    return StackValue(valueType, bitWidth, null, offset);
  }

  function finishBuffer() {
    if (stack.length !== 1) {
      throw `Stack has to be exactly 1, but it is ${stack.length}. You have to end all started vectors and maps before calling [finish]`;
    }
    const value = stack[0];
    const byteWidth = align(value.elementWidth(offset, 0));
    writeStackValue(value, byteWidth);
    writeUInt(value.storedPackedType(), 1);
    writeUInt(byteWidth, 1);
    finished = true;
  }

  return  {
    add: function (value) {
      integrityCheckOnValueAddition();
      if (typeof value === 'undefined') {
        throw "You need to provide a value";
      }
      if (value === null) {
        stack.push(nullStackValue());
      } else if (typeof value === "boolean") {
        stack.push(boolStackValue(value));
      } else if (typeof value === "bigint") {
        stack.push(intStackValue(value));
      } else if (typeof value == 'number') {
        if (Number.isInteger(value)) {
          stack.push(intStackValue(value));
        } else {
          stack.push(floatStackValue(value));
        }
      } else if (ArrayBuffer.isView(value)){
        writeBlob(value.buffer);
      } else if (typeof value === 'string' || value instanceof String) {
        writeString(value);
      } else if (Array.isArray(value)) {
        startVector();
        for (let i = 0; i < value.length; i++) {
          this.add(value[i]);
        }
        end();
      } else if (typeof value === 'object'){
        const properties = Object.getOwnPropertyNames(value).sort();
        startMap(true);
        for (let i = 0; i < properties.length; i++) {
          const key = properties[i];
          this.addKey(key);
          this.add(value[key]);
        }
        end();
      } else {
        throw `Unexpected value input ${value}`;
      }
    },
    finish: function() {
      if (!finished) {
        finishBuffer();
      }
      const result = buffer.slice(0, offset);
      return new Uint8Array(result);
    },
    isFinished: function() {
      return finished;
    },
    addKey: function(key) {
      integrityCheckOnKeyAddition();
      writeKey(key);
    },
    addInt: function(value, indirect = false, deduplicate = false) {
      integrityCheckOnValueAddition();
      if (!indirect) {
        stack.push(intStackValue(value));
        return;
      }
      if (deduplicate && indirectIntLookup.hasOwnProperty(value)) {
        stack.push(indirectIntLookup[value]);
        return;
      }
      const stackValue = intStackValue(value);
      const byteWidth = align(stackValue.width);
      const newOffset = computeOffset(byteWidth);
      const valueOffset = offset;
      stackValue.writeToBuffer(byteWidth);
      const stackOffset = offsetStackValue(valueOffset, flexbuffers.ValueType.INDIRECT_INT, stackValue.width);
      stack.push(stackOffset);
      offset = newOffset;
      if (deduplicate) {
        indirectIntLookup[value] = stackOffset;
      }
    },
    addUInt: function(value, indirect = false, deduplicate = false) {
      integrityCheckOnValueAddition();
      if (!indirect) {
        stack.push(uintStackValue(value));
        return;
      }
      if (deduplicate && indirectUIntLookup.hasOwnProperty(value)) {
        stack.push(indirectUIntLookup[value]);
        return;
      }
      const stackValue = uintStackValue(value);
      const byteWidth = align(stackValue.width);
      const newOffset = computeOffset(byteWidth);
      const valueOffset = offset;
      stackValue.writeToBuffer(byteWidth);
      const stackOffset = offsetStackValue(valueOffset, flexbuffers.ValueType.INDIRECT_UINT, stackValue.width);
      stack.push(stackOffset);
      offset = newOffset;
      if (deduplicate) {
        indirectUIntLookup[value] = stackOffset;
      }
    },
    addFloat: function(value, indirect = false, deduplicate = false) {
      integrityCheckOnValueAddition();
      if (!indirect) {
        stack.push(floatStackValue(value));
        return;
      }
      if (deduplicate && indirectFloatLookup.hasOwnProperty(value)) {
        stack.push(indirectFloatLookup[value]);
        return;
      }
      const stackValue = floatStackValue(value);
      const byteWidth = align(stackValue.width);
      const newOffset = computeOffset(byteWidth);
      const valueOffset = offset;
      stackValue.writeToBuffer(byteWidth);
      const stackOffset = offsetStackValue(valueOffset, flexbuffers.ValueType.INDIRECT_FLOAT, stackValue.width);
      stack.push(stackOffset);
      offset = newOffset;
      if (deduplicate) {
        indirectFloatLookup[value] = stackOffset;
      }
    },
    startVector: function() {
      startVector();
    },
    startMap: function() {
      startMap();
    },
    end: function() {
      end();
    }
  };
};

flexbuffers.encode = (object, size = 2048, deduplicateStrings = true, deduplicateKeys = true, deduplicateKeyVectors = true) => {
  const builder = flexbuffers.builder(size > 0 ? size : 2048, deduplicateStrings, deduplicateKeys, deduplicateKeyVectors);
  builder.add(object);
  return builder.finish();
};



function fromUTF8Array(data) {
  const decoder = new TextDecoder();
  return decoder.decode(data);
}

function toUTF8Array(str) {
  const encoder = new TextEncoder();
  return encoder.encode(str);
}
// Exports for Node.js and RequireJS
this.flexbuffers = flexbuffers;
