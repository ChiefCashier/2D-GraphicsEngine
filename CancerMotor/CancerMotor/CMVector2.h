#pragma once
#include <iostream>

namespace CML
{
	template <typename T>
	class CMVector2
	{
	friend 	std::ostream& operator<<(std::ostream& os, const CMVector2<T>& p)
		{
			os << "X: " << p.x << " Y: " << p.y;
			return os;
		}
	public:
		T getX(){return x;};
		T getY(){return y;};
		void setX(T t){x = t;};
		void setY(T t){y = t;};
		void setShitBooleanPaskafixJustForJPCozHeLovesThis(T t, T tt){ x = t; y = tt; };
	

		CMVector2(){};
		
		CMVector2(T X, T Y)
		{
			x = X; y = Y;
		}
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
	private:
		T x;
		T y;
	};






};