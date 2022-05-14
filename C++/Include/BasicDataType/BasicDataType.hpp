//
// BasicDataType.hpp
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C++/Include/BasicDataType/BasicDataType.hpp
//

template <class _Ty> class _BasicDataType;

#ifndef _BASICDATATYPE_HPP_
#define _BASICDATATYPE_HPP_

#include "../wxh/wxh"
#include "../../../C/Include/types.h"

#include <istream>

_WXH_BEGIN

_INTERNAL_BEGIN

template <class _Ty>
class _BasicDataType
{
public:
    _Ty _value;
public:
    static const size_t BYTES = sizeof(int);
    static const size_t SIZE = BYTES * 8;
};

_INTERNAL_END


#define BASICDATATYPE_BITOPERATOR(_Ty, className) \
    const className operator ~ () const { \
        className t = *this; \
        t._value = ~t._value; \
        return t; \
    } \
    const className operator & (const className& x) const { \
        className t = *this; \
        t._value &= x._value; \
        return t; \
    } \
    const className operator | (const className& x) const { \
        className t = *this; \
        t._value |= x._value; \
        return t; \
    } \
    const className operator ^ (const className& x) const { \
        className t = *this; \
        t._value ^= x._value; \
        return t; \
    } \
    const className operator << (const className& x) const { \
        className t = *this; \
        t._value <<= x._value; \
        return t; \
    } \
    const className operator >> (const className& x) const { \
        className t = *this; \
        t._value >>= x._value; \
        return t; \
    } \
    className & operator &= (const className& x) { \
        this->_value &= x._value; \
        return *this; \
    } \
    className & operator |= (const className& x) { \
        this->_value |= x._value; \
        return *this; \
    } \
    className & operator ^= (const className& x) { \
        this->_value ^= x._value; \
        return *this; \
    } \
    className & operator <<= (const className& x) { \
        this->_value <<= x._value; \
        return *this; \
    } \
    className & operator >>= (const className& x) { \
        this->_value >>= x._value; \
        return *this; \
    } \
    template <class _Type> \
    const className operator & (const _Type& x) const { \
        className t = *this; \
        t._value &= x; \
        return t; \
    } \
    template <class _Type> \
    const className operator | (const _Type& x) const { \
        className t = *this; \
        t._value |= x; \
        return t; \
    } \
    template <class _Type> \
    const className operator ^ (const _Type& x) const { \
        className t = *this; \
        t._value ^= x; \
        return t; \
    } \
    template <class _Type> \
    const className operator << (const _Type& x) const { \
        className t = *this; \
        t._value <<= x; \
        return t; \
    } \
    template <class _Type> \
    const className operator >> (const _Type& x) const { \
        className t = *this; \
        t._value >>= x; \
        return t; \
    } \
    template <class _Type> \
    className & operator &= (const _Type& x) { \
        this->_value &= x; \
        return *this; \
    } \
    template <class _Type> \
    className & operator |= (const _Type& x) { \
        this->_value |= x; \
        return *this; \
    } \
    template <class _Type> \
    className & operator ^= (const _Type& x) { \
        this->_value ^= x; \
        return *this; \
    } \
    template <class _Type> \
    className & operator <<= (const _Type& x) { \
        this->_value <<= x; \
        return *this; \
    } \
    template <class _Type> \
    className & operator >>= (const _Type& x) { \
        this->_value >>= x; \
        return *this; \
    } \
    template <class _Type> \
    friend const className operator & (const _Type& x, const className y) { \
        className t = x; \
        t._value &= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const className operator | (const _Type& x, const className y) { \
        className t = x; \
        t._value |= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const className operator ^ (const _Type& x, const className y) { \
        className t = x; \
        t._value ^= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend className & operator &= (_Type& x, const className& y) { \
        x &= y._value; \
        return x; \
    } \
    template <class _Type> \
    friend className & operator |= (_Type& x, const className& y) { \
        x |= y._value; \
        return x; \
    } \
    template <class _Type> \
    friend className & operator ^= (_Type& x, const className& y) { \
        x ^= y._value; \
        return x; \
    } \
    template <class _Type> \
    friend className & operator <<= (_Type& x, const className& y) { \
        x <<= y._value; \
        return x; \
    } \
    template <class _Type> \
    friend className & operator >>= (_Type& x, const className& y) { \
        x >>= y._value; \
        return x; \
    }
#define BASICDATATYPE_ASSIGNMENT(className) \
    className() {}; \
    ~className() {}; \
    className(const className& value) \
    { \
        this->_value = value._value; \
    } \
    className(className&& value) \
    { \
        this->_value = value._value; \
    } \
    className& operator = (const className& other) { \
        this->_value = other._value; \
        return *this; \
    } \
    className& operator = (className&& other) { \
        this->_value = std::move(other._value); \
        return *this; \
    } \
    className& operator = (className& other) { \
        this->_value = other._value; \
        return *this; \
    } \
    className* operator & () { \
        return this; \
    } \
    const className* operator & () const { \
        return this; \
    } \
    template <class _Type> \
    className& operator = (const _Type value) { \
        this->_value = value; \
        return *this; \
    } \
    template <class _Type> \
    className& operator = (const _Type& value) { \
        this->_value = value; \
        return *this; \
    } \
    template <class _Type> \
    className& operator = (_Type&& value) { \
        this->_value = std::move(value); \
        return *this; \
    } \
    className(const bool value) { \
        this->_value = value; \
    } \
    className(const char value) { \
        this->_value = value; \
    } \
    className(const unsigned char value) { \
        this->_value = value; \
    } \
    className(const short value) { \
        this->_value = value; \
    } \
    className(const unsigned short value) { \
        this->_value = value; \
    } \
    className(const int value) { \
        this->_value = value; \
    } \
    className(const unsigned int value) { \
        this->_value = value; \
    } \
    className(const long value) { \
        this->_value = value; \
    } \
    className(const unsigned long value) { \
        this->_value = value; \
    } \
    className(const long long value) { \
        this->_value = value; \
    } \
    className(const unsigned long long value) { \
        this->_value = value; \
    } \
    className(const float value) { \
        this->_value = value; \
    } \
    className(const double value) { \
        this->_value = value; \
    } \
    className(const long double value) { \
        this->_value = value; \
    }

#define BASICDATATYPE_IOS(className) \
    template <class _Elem> \
    friend std::basic_ostream<_Elem>& operator << (std::basic_ostream<_Elem>& os, const className& x) { \
        os << x._value; \
        return os; \
    } \
    template <class _Elem> \
    friend std::basic_istream<_Elem>& operator >> (std::basic_istream<_Elem>& is, className x) { \
        is >> x._value; \
        return is; \
    }

#define BASICDATATYPE_OPERATORS(className) \
    const className operator + (const className& x) const { \
        className t = *this; \
        t._value += x._value; \
        return t; \
    } \
    const className operator - (const className& x) const { \
        className t = *this; \
        t._value -= x._value; \
        return t; \
    } \
    const className operator * (const className& x) const { \
        className t = *this; \
        t._value *= x._value; \
        return t; \
    } \
    const className operator / (const className& x) const { \
        className t = *this; \
        t._value /= x._value; \
        return t; \
    } \
    const className& operator += (const className& x) { \
        _value += x._value; \
        return *this; \
    } \
    const className& operator -= (const className& x) { \
        _value -= x._value; \
        return *this; \
    } \
    const className& operator *= (const className& x) { \
        _value *= x._value; \
        return *this; \
    } \
    const className& operator /= (const className& x) { \
        _value /= x._value; \
        return *this; \
    } \
    const bool operator == (const className& x) const { \
        return _value == x._value; \
    } \
    const bool operator != (const className& x) const { \
        return _value != x._value; \
    } \
    const bool operator > (const className& x) const { \
        return _value > x._value; \
    } \
    const bool operator < (const className& x) const { \
        return _value < x._value; \
    } \
    const bool operator >= (const className& x) const { \
        return _value >= x._value; \
    } \
    const bool operator <= (const className& x) const { \
        return _value <= x._value; \
    } \
    const bool operator ! () const { \
        return !_value; \
    } \
    const className operator - () const { \
        className t = *this; \
        t._value = -t._value; \
        return t; \
    } \
    const className operator + () const { \
        return *this; \
    } \
    template <class _Type> \
    const className operator + (const _Type& x) const { \
        className t = *this; \
        t._value += x; \
        return t; \
    } \
    template <class _Type> \
    const className operator - (const _Type& x) const { \
        className t = *this; \
        t._value -= x; \
        return t; \
    } \
    template <class _Type> \
    const className operator * (const _Type& x) const { \
        className t = *this; \
        t._value *= x; \
        return t; \
    } \
    template <class _Type> \
    const className operator / (const _Type& x) const { \
        className t = *this; \
        t._value /= x; \
        return t; \
    } \
    template <class _Type> \
    const className& operator += (const _Type& x) { \
        _value += x; \
        return *this; \
    } \
    template <class _Type> \
    const className& operator -= (const _Type& x) { \
        _value -= x; \
        return *this; \
    } \
    template <class _Type> \
    const className& operator *= (const _Type& x) { \
        _value *= x; \
        return *this; \
    } \
    template <class _Type> \
    const className& operator /= (const _Type& x) { \
        _value /= x; \
        return *this; \
    } \
    template <class _Type> \
    const bool operator == (const _Type& x) const { \
        return _value == x; \
    } \
    template <class _Type> \
    const bool operator != (const _Type& x) const { \
        return _value != x; \
    } \
    template <class _Type> \
    const bool operator > (const _Type& x) const { \
        return _value > x; \
    } \
    template <class _Type> \
    const bool operator < (const _Type& x) const { \
        return _value < x; \
    } \
    template <class _Type> \
    const bool operator >= (const _Type& x) const { \
        return _value >= x; \
    } \
    template <class _Type> \
    const bool operator <= (const _Type& x) const { \
        return _value <= x; \
    } \
    template <class _Type> \
    friend const className operator + (const _Type& x, const className& y) { \
        className t = x; \
        t._value += y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const className operator - (const _Type& x, const className& y) { \
        className t = x; \
        t._value -= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const className operator * (const _Type& x, const className& y) { \
        className t = x; \
        t._value *= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const className operator / (const _Type& x, const className& y) { \
        className t = x; \
        t._value /= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const bool operator == (const _Type& x, const className& y) { \
        return x == y._value; \
    } \
    template <class _Type> \
    friend const bool operator != (const _Type& x, const className& y) { \
        return x != y._value; \
    } \
    template <class _Type> \
    friend const bool operator > (const _Type& x, const className& y) { \
        return x > y._value; \
    } \
    template <class _Type> \
    friend const bool operator < (const _Type& x, const className& y) { \
        return x < y._value; \
    } \
    template <class _Type> \
    friend const bool operator >= (const _Type& x, const className& y) { \
        return x >= y._value; \
    } \
    template <class _Type> \
    friend const bool operator <= (const _Type& x, const className& y) { \
        return x <= y._value; \
    } \
    template <class _Type> \
    friend const _Type operator + (const className& x, const _Type& y) { \
        _Type t = y; \
        t += x._value; \
        return t; \
    } \
    template <class _Type> \
    friend const _Type operator - (const className& x, const _Type& y) { \
        _Type t = y; \
        t -= x._value; \
        return t; \
    } \
    template <class _Type> \
    friend const _Type operator * (const className& x, const _Type& y) { \
        _Type t = y; \
        t *= x._value; \
        return t; \
    } \
    template <class _Type> \
    friend const _Type operator / (const className& x, const _Type& y) { \
        _Type t = y; \
        t /= x._value; \
        return t; \
    } \
    template <class _Type> \
    friend _Type & operator += (_Type& x, const className& y) { \
        x += y._value; \
        return x; \
    } \
    template <class _Type> \
    friend _Type & operator -= (_Type& x, const className& y) { \
        x -= y._value; \
        return x; \
    } \
    template <class _Type> \
    friend _Type & operator *= (_Type& x, const className& y) { \
        x *= y._value; \
        return x; \
    } \
    template <class _Type> \
    friend _Type & operator /= (_Type& x, const className& y) { \
        x /= y._value; \
        return x; \
    } \

#define BASICDATATYPE_SELF_OPERATOR(className) \
    const className& operator ++ () { \
        _value++; \
        return *this; \
    } \
    const className& operator -- () { \
        _value--; \
        return *this; \
    } \
    const className operator ++ (int) { \
        className t = *this; \
        _value++; \
        return t; \
    } \
    const className operator -- (int) { \
        className t = *this; \
        _value--; \
        return t; \
    }

#define BASICDATATYPE_MOD_OPERATORS(className) \
    const className operator % (const className& x) const { \
        className t = *this; \
        t._value %= x._value; \
        return t; \
    } \
    template <class _Type> \
    const className operator % (const _Type& x) const { \
        className t = *this; \
        t._value %= x; \
        return t; \
    } \
    template <class _Type> \
    const className& operator %= (const _Type& x) { \
        _value %= x; \
        return *this; \
    } \
    template <class _Type> \
    friend const className operator % (const _Type& x, const className& y) { \
        className t = x; \
        t._value %= y._value; \
        return t; \
    } \
    template <class _Type> \
    friend const _Type operator % (const className& x, const _Type& y) { \
        _Type t = y; \
        t %= x._value; \
        return t; \
    } \
    template <class _Type> \
    friend _Type & operator %= (_Type& x, const className& y) { \
        x %= y._value; \
        return x; \
    } \
    const className& operator %= (const className& x) { \
        _value %= x._value; \
        return *this; \
    } \

class Boolean : public Internal::_BasicDataType<bool> {
public:
    static const bool TRUE = true;
    static const bool FALSE = false;
    BASICDATATYPE_BITOPERATOR(bool, Boolean)
    BASICDATATYPE_ASSIGNMENT(Boolean)
    BASICDATATYPE_OPERATORS(Boolean)
    BASICDATATYPE_MOD_OPERATORS(Boolean)
    BASICDATATYPE_IOS(Boolean)
};

class Char : public Internal::_BasicDataType<char> {
public:
    static const char MAX = CHAR_MAX;
    static const char MIN = CHAR_MIN;
    BASICDATATYPE_BITOPERATOR(char, Char)
    BASICDATATYPE_ASSIGNMENT(Char)
    BASICDATATYPE_OPERATORS(Char)
    BASICDATATYPE_SELF_OPERATOR(Char)
    BASICDATATYPE_MOD_OPERATORS(Char)
    BASICDATATYPE_IOS(Char)
};

class Short : public Internal::_BasicDataType<short> {
public:
    static const short MAX = SHORT_MAX;
    static const short MIN = SHORT_MIN;
    BASICDATATYPE_BITOPERATOR(short, Short)
    BASICDATATYPE_ASSIGNMENT(Short)
    BASICDATATYPE_OPERATORS(Short)
    BASICDATATYPE_SELF_OPERATOR(Short)
    BASICDATATYPE_MOD_OPERATORS(Short)
    BASICDATATYPE_IOS(Short)
};

class Int : public Internal::_BasicDataType<int> {
public:
    static const int MAX = INT_MAX;
    static const int MIN = INT_MIN;
    BASICDATATYPE_BITOPERATOR(int, Int)
    BASICDATATYPE_ASSIGNMENT(Int)
    BASICDATATYPE_OPERATORS(Int)
    BASICDATATYPE_SELF_OPERATOR(Int)
    BASICDATATYPE_MOD_OPERATORS(Int)
    BASICDATATYPE_IOS(Int)
};

class Long : public Internal::_BasicDataType<long> {
public:
    static const long MAX = LONG_MAX;
    static const long MIN = LONG_MIN;
    BASICDATATYPE_BITOPERATOR(long, Long)
    BASICDATATYPE_ASSIGNMENT(Long)
    BASICDATATYPE_OPERATORS(Long)
    BASICDATATYPE_SELF_OPERATOR(Long)
    BASICDATATYPE_MOD_OPERATORS(Long)
    BASICDATATYPE_IOS(Long)
};

class LongLong : public Internal::_BasicDataType<long long> {
public:
    static const long long MAX = LLONG_MAX;
    static const long long MIN = LLONG_MIN;
    BASICDATATYPE_BITOPERATOR(long long, LongLong)
    BASICDATATYPE_ASSIGNMENT(LongLong)
    BASICDATATYPE_OPERATORS(LongLong)
    BASICDATATYPE_SELF_OPERATOR(LongLong)
    BASICDATATYPE_MOD_OPERATORS(LongLong)
    BASICDATATYPE_IOS(LongLong)
};

class UnsignedChar : public Internal::_BasicDataType<unsigned char> {
public:
    static const unsigned char MAX = UCHAR_MAX;
    static const unsigned char MIN = 0;
    BASICDATATYPE_BITOPERATOR(unsigned char, UnsignedChar)
    BASICDATATYPE_ASSIGNMENT(UnsignedChar)
    BASICDATATYPE_OPERATORS(UnsignedChar)
    BASICDATATYPE_SELF_OPERATOR(UnsignedChar)
    BASICDATATYPE_MOD_OPERATORS(UnsignedChar)
    BASICDATATYPE_IOS(UnsignedChar)
};

class UnsignedShort : public Internal::_BasicDataType<unsigned short> {
public:
    static const unsigned short MAX = USHORT_MAX;
    static const unsigned short MIN = 0;
    BASICDATATYPE_BITOPERATOR(unsigned short, UnsignedShort)
    BASICDATATYPE_ASSIGNMENT(UnsignedShort)
    BASICDATATYPE_OPERATORS(UnsignedShort)
    BASICDATATYPE_SELF_OPERATOR(UnsignedShort)
    BASICDATATYPE_MOD_OPERATORS(UnsignedShort)
    BASICDATATYPE_IOS(UnsignedShort)
};

class UnsignedInt : public Internal::_BasicDataType<unsigned int> {
public:
    static const unsigned int MAX = UINT_MAX;
    static const unsigned int MIN = 0;
    BASICDATATYPE_BITOPERATOR(unsigned int, UnsignedInt)
    BASICDATATYPE_ASSIGNMENT(UnsignedInt)
    BASICDATATYPE_OPERATORS(UnsignedInt)
    BASICDATATYPE_SELF_OPERATOR(UnsignedInt)
    BASICDATATYPE_MOD_OPERATORS(UnsignedInt)
    BASICDATATYPE_IOS(UnsignedInt)
};

class UnsignedLong : public Internal::_BasicDataType<unsigned long> {
public:
    static const unsigned long MAX = ULONG_MAX;
    static const unsigned long MIN = 0;
    BASICDATATYPE_BITOPERATOR(unsigned long, UnsignedLong)
    BASICDATATYPE_ASSIGNMENT(UnsignedLong)
    BASICDATATYPE_OPERATORS(UnsignedLong)
    BASICDATATYPE_SELF_OPERATOR(UnsignedLong)
    BASICDATATYPE_MOD_OPERATORS(UnsignedLong)
    BASICDATATYPE_IOS(UnsignedLong)
};

class UnsignedLongLong : public Internal::_BasicDataType<unsigned long long> {
public:
    static const unsigned long long MAX = ULLONG_MAX;
    static const unsigned long long MIN = 0;
    BASICDATATYPE_BITOPERATOR(unsigned long long, UnsignedLongLong)
    BASICDATATYPE_ASSIGNMENT(UnsignedLongLong)
    BASICDATATYPE_OPERATORS(UnsignedLongLong)
    BASICDATATYPE_SELF_OPERATOR(UnsignedLongLong)
    BASICDATATYPE_MOD_OPERATORS(UnsignedLongLong)
    BASICDATATYPE_IOS(UnsignedLongLong)
};

_WXH_END

#include "DataType.hpp"

_WXH_BEGIN

class Float : public Internal::_BasicDataType<float> {
public:
    static constexpr float MAX = FLT_MAX;
    static constexpr float MIN = FLT_MIN;
    BASICDATATYPE_ASSIGNMENT(Float)
    BASICDATATYPE_OPERATORS(Float)
    BASICDATATYPE_SELF_OPERATOR(Float)
    BASICDATATYPE_IOS(Float)
};

class Double : public Internal::_BasicDataType<double> {
public:
    static constexpr double MAX = DBL_MAX;
    static constexpr double MIN = DBL_MIN;
    BASICDATATYPE_ASSIGNMENT(Double)
    BASICDATATYPE_OPERATORS(Double)
    BASICDATATYPE_IOS(Double)
};

class LongDouble : public Internal::_BasicDataType<long double> {
public:
    static constexpr long double MAX = LDBL_MAX;
    static constexpr long double MIN = LDBL_MIN;
    BASICDATATYPE_ASSIGNMENT(LongDouble)
    BASICDATATYPE_OPERATORS(LongDouble)
    BASICDATATYPE_IOS(LongDouble)
};

#undef BASICDATATYPE_BITOPERATOR
#undef BASICDATATYPE_ASSIGNMENT
#undef BASICDATATYPE_OPERATORS
#undef BASICDATATYPE_SELF_OPERATOR
#undef BASICDATATYPE_MOD_OPERATORS
#undef BASICDATATYPE_IOS

_WXH_END

#endif /* _BASICDATATYPE_HPP_ */
