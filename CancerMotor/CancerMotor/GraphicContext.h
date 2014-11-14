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
	

		GraphicContext();
		~GraphicContext();
		void InitializeOpengl();
		void Initialize(CML::CMWindow *window);
		void Initialize(RenderingContext *rcontext);
		void EndDraw();
		void Draw(CMRectangle rec);
	private:
		std::list<CMShape> _drawables;
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