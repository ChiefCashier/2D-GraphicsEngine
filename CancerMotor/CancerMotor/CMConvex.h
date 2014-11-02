#pragma once
#include "CMShape.h"
namespace CML
{
	class CMConvex :
		public CMShape
	{
		typedef float vec2[2];
	public:
		CMConvex(int a);
		CMConvex();
		~CMConvex();

		void SetVertexAmount(int a);
		int GetVertexAmount();

		void AddVertex(float x, float y);

	private:
		int _vertexAmount;
	};
}