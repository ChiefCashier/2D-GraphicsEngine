#pragma once
#include "glew.h"
#include <list>
#include "RenderingContext.h"
#include "CMRectangle.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
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

		GLint _positionIndex;
		GLint _colorIndex;
		GLint _textureIndex;
		GLint _samplerLocation;
		GLint _projectionLocation;
		GLint _objectLocation;
		glm::mat4 _projection;
		GLuint buffers[2];
	};

}