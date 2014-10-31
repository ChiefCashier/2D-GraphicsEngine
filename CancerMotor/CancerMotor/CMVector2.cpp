#include "CMVector2.h"
#include <iostream>

namespace CML
{
	//template<typename T>
	CMVector2::CMVector2()
	{

	}

	CMVector2::CMVector2(int x, int y)
	{
		xi = x;
		yi = y;
	}

	CMVector2::~CMVector2()
	{

	}



	//Template version ? Possibly?
	//template<typename T>
	CML::CMVector2 operator+(const CML::CMVector2 &vec1, const CML::CMVector2 &vec2)
	{
		CML::CMVector2 result;
		result.xi = vec1.xi + vec2.xi;
		result.yi = vec1.yi + vec2.yi;
		return result;
	}

	/*
	//template<typename T>
	CML::CMVector2 operator -(const CML::CMVector2& vec1, const CML::CMVector2& vec2)
	{
	CML::CMVector2 result;
	result.xi = vec1.xi - vec2.xi;
	result.yi = vec1.yi - vec2.yi;
	return result;
	}*/
};