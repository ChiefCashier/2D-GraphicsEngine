#pragma once
#include "glew.h"
#include <list>
#include "RenderingContext.h"
#include "CMShape.h"
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
		GraphicContext(RenderingContext *rcontext);
		~GraphicContext();
		void InitializeOpengl();
		void Initialize(CML::CMWindow *window);
		void Initialize(RenderingContext *rcontext);
		void EndDraw();
		void Draw(CMShape *rec);
		static void RemoveDrawable(CMShape* rec);
		void SetCameraX(float x);

		void SetCameraY(float y);
		float GetCameraX();

		float GetCameraY();
	private:
		float _cameraX;
		float _cameraY;
		static std::vector<CMShape*> _drawables;
		RenderingContext *_rcontext;


		GLint _positionIndex;
		GLint _colorIndex;
		GLint _textureIndex;
		GLint _samplerLocation;
		GLint _projectionLocation;
		GLint _viewLocation;
		GLint _objectLocation;
		GLint _alphaChannel;
		glm::mat4 _projection;
		glm::mat4 _defaultProjection;
		glm::mat4 _view;
		GLuint buffers[2];
	};

}