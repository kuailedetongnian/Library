//
// DataType.hpp
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C++/Include/BasicDataType/DataType.hpp
//

#ifndef _DATATYPE_HPP_
#define _DATATYPE_HPP_

#include "../wxh/wxh"
#include "BasicDataType.hpp"
#include "../../../C/Include/types.h"

_WXH_BEGIN

_INTERNAL_BEGIN

template <class _Ty>
class _DataType : public _BasicDataType<_Ty> {
public:
    static const size_t BYTES = sizeof(_Ty);
    static const size_t SIZE = BYTES * 8;
public:
    BASICDATATYPE_BITOPERATOR(_Ty, _DataType<_Ty>)
private:
    class reference {
    private:
        friend _DataType<_Ty>;
        _DataType<_Ty>* _ptr;
        size_t _index;
    public:
        reference& operator = (const bool bit) {
            _ptr->_byte = (_ptr->_byte | (1 << 7 - _index)) & ~(!bit << 7 - _index);
            return *this;
        }
        reference& operator = (const reference& other) {
            *this = (bool)other;
            return *this;
        }
        reference(_DataType<_Ty>* ptr, size_t index) : _ptr(ptr), _index(index) {
            return;
        }
        operator bool() const {
            return (_ptr->_value & (1 << 7 - _index));
        }
        template <class _Elem>
        friend std::basic_ostream<_Elem>& operator << (std::basic_ostream<_Elem>& os, const reference& ref) {
            os << (bool)ref;
            return os;
        }
        template <class _Elem>
        friend std::basic_istream<_Elem>& operator >> (std::basic_istream<_Elem>& is, reference& ref) {
            bool bit;
            is >> bit;
            ref = bit;
            return is;
        }
    };
public:
    reference operator [] (size_t index) {
        return reference(this, index);
    }
    const bool operator [] (size_t index) const {
        return (this->_ptr->_value & (1 << 7 - index));
    }
};

_INTERNAL_END

class Byte : public Internal::_DataType<byte> {
public:
    static const byte MAX = BYTE_MAX;
    static const byte MIN = BYTE_MIN;
    BASICDATATYPE_BITOPERATOR(byte, Byte)
    BASICDATATYPE_ASSIGNMENT(Byte)
    BASICDATATYPE_SELF_OPERATOR(Byte)
    BASICDATATYPE_MOD_OPERATORS(Byte)
    BASICDATATYPE_IOS(Byte)
};
class Word : public Internal::_DataType<word> {
public:
    static const word MAX = WORD_MAX;
    static const word MIN = WORD_MIN;
    BASICDATATYPE_BITOPERATOR(word, Word)
    BASICDATATYPE_ASSIGNMENT(Word)
    BASICDATATYPE_SELF_OPERATOR(Word)
    BASICDATATYPE_MOD_OPERATORS(Word)
    BASICDATATYPE_IOS(Word)
};
class DWord : public Internal::_DataType<dword> {
public:
    static const dword MAX = DWORD_MAX;
    static const dword MIN = DWORD_MIN;
    BASICDATATYPE_BITOPERATOR(dword, DWord)
    BASICDATATYPE_ASSIGNMENT(DWord)
    BASICDATATYPE_SELF_OPERATOR(DWord)
    BASICDATATYPE_MOD_OPERATORS(DWord)
    BASICDATATYPE_IOS(DWord)
};
class QWord : public Internal::_DataType<qword> {
public:
    static const qword MAX = QWORD_MAX;
    static const qword MIN = QWORD_MIN;
    BASICDATATYPE_BITOPERATOR(qword, QWord)
    BASICDATATYPE_ASSIGNMENT(QWord)
    BASICDATATYPE_SELF_OPERATOR(QWord)
    BASICDATATYPE_MOD_OPERATORS(QWord)
    BASICDATATYPE_IOS(QWord)
};

_WXH_END

#endif /* _DATATYPE_HPP_ */
