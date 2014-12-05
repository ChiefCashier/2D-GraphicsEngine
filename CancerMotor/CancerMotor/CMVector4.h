#pragma once
#include <iostream>

namespace CML
{
	template <typename T>
	class CMVector4
	{
		friend 	std::ostream& operator<<(std::ostream& os, const CMVector4<T>& p)
		{
			os << "X: " << p.x << " Y: " << p.y << "Z: " << p.z << " K: " << p.k;
			return os;
		}

	public:

		T getX(){ return x; };
		T getY(){ return y; };
		T getZ(){ return x; };
		T getK(){ return y; };

		void setX(T t){ x = t; };
		void setY(T t){ y = t; };
		void setZ(T t){ z = t; };
		void setK(T t){ k = t; };

		void setShitBooleanPaskafixJustForJPCozHeLovesThis(T t, T tt, T ttt, T tttt){ x = t; y = tt; z = ttt; k = tttt; };

		CMVector4(){};

		CMVector4(T X, T Y, T Z, T K)
		{
			x = X; y = Y; k =K; z = Z;
		}
		CMVector4<T> operator + (const CMVector4<T>& right)
		{
			x = x + right.x;
			y = y + right.y;
			z = z + right.z;
			k = k + right.k;
			return *this;
		}
		CMVector4<T> operator - (const CMVector4<T>& right)
		{
			x = x - right.x;
			y = y - right.y;
			z = z - right.z;
			k = k - right.k;
			return *this;
		}
		bool operator == (const CMVector4<T>& right)
		{
			return x == right.x && y == right.y && x == right.x && y == right.y;
		}

		CMVector4<T> operator *=(CMVector4<T>& left)
		{
			x *= left.x;
			y *= left.y;
			z *= left.z;
			k *= left.k;
			return *this;
		}
		CMVector4<T> operator /=(CMVector4<T>& left)
		{
			x /= left.x;
			y /= left.y;
			z /= left.z;
			k /= left.k;
			return *this;
		}
		CMVector4<T> operator +=(CMVector4<T>& left)
		{
			x += left.x;
			y += left.y;
			z += left.z;
			k += left.k;
			return *this;
		}
		CMVector4<T> operator -=(CMVector4<T>& left)
		{
			x -= left.x;
			y -= left.y;
			z -= left.z;
			k -= left.k;
			return *this;
		}
	private:
		T x;
		T y;
		T z;
		T k;
	};

};