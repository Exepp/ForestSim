#pragma once
#include <cmath>


template<class T>
struct Vec2
{
	template <typename U>
	explicit Vec2(const Vec2<U> & vec);

	Vec2(T x, T y);

	Vec2();


	T length() const;


	T x;
	T y;


	static const Vec2<T> ZeroVector;

	static const Vec2<T> OneVector;
};




template<class T>
const Vec2<T> Vec2<T>::ZeroVector = Vec2<T>(0, 0);
template<class T>
const Vec2<T> Vec2<T>::OneVector = Vec2<T>(1, 1);


typedef Vec2<size_t>	Vec2u;

typedef Vec2<ptrdiff_t>	Vec2i;

typedef Vec2<float_t>	Vec2f;

typedef Vec2<double_t>	Vec2d;


template<class T>
template<class U>
inline Vec2<T>::Vec2(const Vec2<U>& vec) : x(T(vec.x)), y(T(vec.y))
{
}

template<class T>
inline Vec2<T>::Vec2(T x, T y) : x(x), y(y)
{
}

template<class T>
inline Vec2<T>::Vec2() : x(0), y(0)
{
}

template<class T>
inline T Vec2<T>::length() const
{
	return T(sqrtf(x * x + y * y));
}

////////////////////////////////////////////////////////// operators //////////////////////////////////////////////////////////

template<class T>
inline Vec2<T> operator+(const Vec2<T> & left, const Vec2<T> & right)
{
	return Vec2<T>(left.x + right.x, left.y + right.y);
}

template<class T>
inline Vec2<T> operator-(const Vec2<T> & right)
{
	return Vec2<T>(-right.x, -right.y);
}

template<class T>
inline Vec2<T> operator-(const Vec2<T> & left, const Vec2<T> & right)
{
	return left + (-right);
}

template<class T>
inline Vec2<T> operator*(const Vec2<T> & left, T right)
{
	return Vec2<T>(left.x * right, left.y * right);
}

template<class T>
inline Vec2<T> operator*(T left, const Vec2<T> & right)
{
	return right * left;
}

// if right == 0, returns zero vector
template<class T>
inline Vec2<T> operator/(const Vec2<T> & left, T right)
{
	if (right)
		return Vec2<T>(left.x / right, left.y / right);
	else
		return Vec2<T>();
}
// if one of vector's components == 0, in returned vector that component value will also be 0 
template<class T>
inline Vec2<T> operator/(T left, const Vec2<T> & right)
{
	return Vec2<T>(right.x != 0 ? left / right.x : 0, right.y != 0 ? left / right.y : 0);
}

template<class T>
inline Vec2<T>& operator+=(Vec2<T> & left, const Vec2<T> & right)
{
	return left = (left + right);
}

template<class T>
inline Vec2<T>& operator-=(Vec2<T> & left, const Vec2<T> & right)
{
	return left = (left - right);
}

template<class T>
inline Vec2<T>& operator*=(Vec2<T> & left, T right)
{
	return left = (left * right);
}

// if right == 0, returns zero vector
template<class T>
inline Vec2<T>& operator/=(Vec2<T> & left, T right)
{
	if (right)
	{
		left.x /= right;
		left.y /= right;
	}
	else
		left = Vec2<T>::ZeroVector;
	return left;
}



template<class T>
inline bool operator==(const Vec2<T> & left, const Vec2<T> & right)
{
	return left.x == right.x && left.y == right.y;
}

template<class T>
inline bool operator!=(const Vec2<T> & left, const Vec2<T> & right)
{
	return !(left == right);
}