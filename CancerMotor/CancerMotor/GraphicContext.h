#pragma once
#include "glew.h"
#include <list>
#include "RenderingContext.h"
#include "CMRectangle.h"
#include <vector>
namespace CML
{
	class GraphicContext
	{
	public:
		struct drawable{
			std::vector<GLfloat> vertices;
			std::vector<GLuint> indices;
		};

		GraphicContext();
		~GraphicContext();
		void setShit();
		void BeginDraw(CML::CMWindow *window);
		void BeginDraw(RenderingContext *rcontext);
		void EndDraw();
		void Draw(CMRectangle rec);
	private:
		std::list<drawable> _drawables;
		RenderingContext *_rcontext;
		GLuint _texture;
		GLint _positionIndex;
		GLint _colorIndex;
		GLint _textureIndex;
		GLint _samplerLocation;
		GLint _projectionLocation;
		GLuint buffers[2];
	};

}