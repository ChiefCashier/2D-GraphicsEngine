/*
#pragma once

namespace CML
{
	class CMVector2
	{
		friend CMVector2 operator+(const CMVector2 &vec1, const CMVector2 &vec2);
		//friend CMVector2 operator -(const CMVector2& vec1, const CMVector2& vec2);
	public:
		CMVector2();
		//CMVector2(T X, T Y);
		CMVector2(int x, int y);
		//CMVector2(float x, float y);
		~CMVector2();

		//CMVector2 operator +(const CMVector2& vec1, const CMVector2& vec2);
		//CMVector2 operator -(const CMVector2& vec1, const CMVector2& vec2);

		//template<typename U>
		//explicit CMVector2(const Vector2<U>& vector2);

		//T x;
		//T y;


		int xi;
		int yi;

		//float xf;
		//float yf;

	};

	//CMVector2 operator +(const CMVector2& vector1, const CMVector2& vector2);

	//CMVector2 operator -(const CMVector2& vector1, const CMVector2& vector2);
}*/

#pragma once
#include <iostream>

namespace CML
{
	template <typename T>
	class CMVector2
	{
		//friend CMVector2<T> operator+(const CMVector2<T> &vec1, const CMVector2<T> &vec2);
		//friend CMVector2 operator -(const CMVector2& vec1, const CMVector2& vec2);
		friend 	std::ostream& operator<<(std::ostream& os, const CMVector2<T>& p)
		{
			os << "X: " << p.x << " Y: " << p.y;
			return os;
		}
	public:
		
		T x;
		T y;

		CMVector2();
		
		CMVector2(T X, T Y)
		{
			x = X;
			y = Y;
		}

		//CMVector2(int x, int y);
		//CMVector2(float x, float y);

		//CMVector2 operator +(const CMVector2& vec1, const CMVector2& vec2);
		//CMVector2 operator -(const CMVector2& vec1, const CMVector2& vec2);

		//template<typename U>
		//explicit CMVector2(const Vector2<U>& vector2);



		CMVector2<T> operator + ( const CMVector2<T>& right)
		{
			x = x + right.x;
			y = y+ right.y;
			return *this;
		}
		CMVector2<T> operator - (const CMVector2<T>& right)
		{
			x = x - right.x;
			y = y - right.y;
			return *this;
		}
		bool operator == (const CMVector2<T>& right)
		{
			return x == right.x && y == right.y;
		}
	
		CMVector2<T> operator *=(CMVector2<T>& left)
		{
			x *= left.x;
			y *= left.y;
			return *this;
		}
		CMVector2<T> operator /=(CMVector2<T>& left)
		{
			x /= left.x;
			y /= left.y;
			return *this;
		}
		CMVector2<T> operator +=(CMVector2<T>& left)
		{
			x += left.x;
			y += left.y;
			return *this;
		}
		CMVector2<T> operator -=(CMVector2<T>& left)
		{
			x -= left.x;
			y -= left.y;
			return *this;
		}
	};






};