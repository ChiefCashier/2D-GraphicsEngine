#pragma once

#include "glew.h"
#include "glm\glm.hpp"
#include <string>
#include <iostream>
#include "CMWindow.h"

// Examples

//typedef float vec3[3];
//vec3 black = { 0, 0, 0 };
//CMDraw::CMDrawShapeRectangle(100, 100, 250, 250, black);
////CMDraw::CMDrawShapeCircle(100, 100, 50, 10, black);

//CMDraw shaep;
//shaep.CMSetPoints(5);
//shaep.CMaddVertex(10, 10);

class CMDraw
{
public:
	CMDraw() {};
	~CMDraw() {};

	typedef GLfloat vec4[4];
	static void CMDrawShapeRectangle(float posX, float posY, float width, float height, vec4 color)
	{
		GLint m_viewport[4];
		// Gets screen x, y, width, height
		glGetIntegerv(GL_VIEWPORT, m_viewport);

		float  _screenWidth = m_viewport[2];
		float _screenHeight = m_viewport[3];

		int _vertexCount = 4;

		// Convert R G B Values to vertex color form
		vec4 nColor;
		for (int i = 0; i < 4; i++)
		{
			nColor[i] = color[i] / 255;
		}

		// x, y, r, g, b, alpha, tx, ty
		static const GLfloat RECTANGLE_DATA[] =
		{
			// 1st
			posX, posY,
			nColor[0], nColor[1], nColor[2], nColor[3],
			CMDraw::Convert(posX, _screenWidth), CMDraw::Convert(posY, _screenHeight),
			// 2nd
			posX + width, posY,
			nColor[0], nColor[1], nColor[2], nColor[3],
			CMDraw::Convert(posX + width, _screenWidth), CMDraw::Convert(posY, _screenHeight),
			// 3rd
			posX + width, posY - height,
			nColor[0], nColor[1], nColor[2], nColor[3],
			CMDraw::Convert(posX + width, _screenWidth), CMDraw::Convert(posY - height, _screenHeight),
			// 4th
			posX, posY - height,
			nColor[0], nColor[1], nColor[2], nColor[3],
			CMDraw::Convert(posX, _screenWidth), CMDraw::Convert(posY - height, _screenHeight),
		};
	};
	static void CMDrawShapeCircle(float posX, float posY, float size, int sides, vec4 color)
	{
		GLint m_viewport[4];
		// Gets screen x, y, width, height
		glGetIntegerv(GL_VIEWPORT, m_viewport);

		float  _screenWidth = m_viewport[2];
		float _screenHeight = m_viewport[3];

		// Convert R G B Values to vertex color form
		vec4 nColor;
		for (int i = 0; i < 4; i++)
		{
			nColor[i] = color[i] / 255;
		}

		static float* CIRCLE_DATA = new GLfloat[1024];

		// Creating data for 1st point
		// Center point
		CIRCLE_DATA[0] = Convert(posX, _screenWidth);
		CIRCLE_DATA[1] = Convert(posY, _screenHeight);

		// RGBA
		CIRCLE_DATA[2] = nColor[0];
		CIRCLE_DATA[3] = nColor[1];
		CIRCLE_DATA[4] = nColor[2];
		CIRCLE_DATA[5] = nColor[3];

		// Texture coordinates
		CIRCLE_DATA[6] = Convert(posX, _screenWidth);
		CIRCLE_DATA[7] = Convert(posY, _screenHeight);


		// Creating rest of the points here
		for (int i = 0; i < 360; i += sides)
		{
			for (int j = 8; j < 256; j++)
			{
				// x, y
				CIRCLE_DATA[j] = Convert(posX + size * cos(i), _screenWidth);
				CIRCLE_DATA[j + 1] = Convert(posY + size * sin(i), _screenHeight);
				// r, g, b, a
				CIRCLE_DATA[j + 2] = nColor[0];
				CIRCLE_DATA[j + 3] = nColor[1];
				CIRCLE_DATA[j + 4] = nColor[2];
				CIRCLE_DATA[j + 5] = nColor[3];
				// tx, ty
				CIRCLE_DATA[j + 6] = Convert(posX, _screenWidth);
				CIRCLE_DATA[j + 7] = Convert(posX, _screenHeight);
			}
		}

	}


	// Custom shapes

	// Define how many vertices you want
	void CMSetPoints(int size)
	{
		_psize = size;
	}

	// Add that many vertices
	void CMaddVertex(float posX, float posY)
	{
		static float* POINT_DATA = new GLfloat[];
		for (int i = 0; i < _psize; i++)
		{
			POINT_DATA[i] = posX;
			POINT_DATA[i + 1] = posY;
		}
	}

private:
	int _psize;

	// Conversion
	// (posX * 2) / _screenWidth - 1
	static float Convert(float x, float screenD)
	{
		return (x * 2) / screenD - 1;
	}

	/*static float* SHAPE_DATA = new GLfloat[];
	void CMWindow::otaDataa(GLfloat data, int size)
	{
	for (int i = 0; i < size; i++)
	{
	SHAPE_DATA[i] = data;
	}
	}*/


	/*for (int x = 0; x <= sizeof(RECTANGLE_DATA); x++)
	{
	CML::CMWindow::otaDataa(RECTANGLE_DATA[x], sizeof(RECTANGLE_DATA));
	}*/

};

