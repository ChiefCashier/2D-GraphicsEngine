#include "GraphicContext.h"
#include <assert.h>
namespace CML
{
	GraphicContext::GraphicContext()
	{
	}


	GraphicContext::~GraphicContext()
	{
	}
	void GraphicContext::Initialize(CML::CMWindow *window)
	{
		this->_rcontext = new RenderingContext(window);
		_rcontext->createVertexShader();
		_rcontext->createFragmentShader();
		InitializeOpengl();
	}
	void GraphicContext::Initialize(RenderingContext *rcontext)
	{

		this->_rcontext = rcontext;//new RenderingContext();
		InitializeOpengl();
	}
	void GraphicContext::InitializeOpengl()
	{
		glGenBuffers(2, buffers);
		//activate attribute arrays
		_positionIndex = glGetAttribLocation(_rcontext->getProgramIndex(), "attrPosition");
		assert(_positionIndex >= 0);
		glEnableVertexAttribArray(_positionIndex);

		_colorIndex = glGetAttribLocation(_rcontext->getProgramIndex(), "attrColor");
		assert(_colorIndex >= 0);
		glEnableVertexAttribArray(_colorIndex);

		_textureIndex = glGetAttribLocation(_rcontext->getProgramIndex(), "attrTexCoord");
		assert(_textureIndex >= 0);
		glEnableVertexAttribArray(_textureIndex);


		_samplerLocation = glGetUniformLocation(_rcontext->getProgramIndex(), "myTexture");
		assert(_samplerLocation >= 0);

		_projectionLocation = glGetUniformLocation(_rcontext->getProgramIndex(), "unifProjection");
		assert(_projectionLocation >= 0);

		glUseProgram(_rcontext->getProgramIndex());


		_projection = glm::ortho(0.0f,	static_cast<float>(_rcontext->getWindow()->_windowWidht),
												 0.0f,	static_cast<float>(_rcontext->getWindow()->_windowHeight),
												 -1.0f, 1.0f);


		glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

		glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

		glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

		glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));

		glUseProgram(0u);


	}
	void GraphicContext::EndDraw()
	{
		glFlush();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		//actual draw

		CMShape a = *_drawables.begin();
			
		glUseProgram(_rcontext->getProgramIndex());

		int helevetin冝iootti = _drawables.size();
		for (int i = 0; i < helevetin冝iootti; i++)
		{
			a = *_drawables.begin();

			//elegant way of transforming primitives
			//first projection, as it should be
			_projection = glm::ortho(0.0f, static_cast<float>(_rcontext->getWindow()->_windowWidht),
				0.0f, static_cast<float>(_rcontext->getWindow()->_windowHeight),
				-1.0f, 1.0f);
			//then translate the primitive where it should be 
			_projection = glm::translate(_projection, glm::vec3(a.GetX(), a.GetY(), 0.0f));
			//then scale the primitive as it should be 
			//_projection = glm::scale(_projection, glm::vec3(a.GetSize(), a.GetSize(), 0.0f));
			//then rotate the primitive as it should be 
			_projection = glm::rotate(_projection, (float)a.GetRotation() , glm::vec3(0.0f, 0.0f, 1.0f));
			//finish with a touch of mint and glUniformMatrix4fv, and voilá!
			glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));
			//you got yourself a handy way of dumping your workload to the GPU!


			//set vertex data
			glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* a.GetVertices().size(), &a.GetVertices()[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			//set fragment data


			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*a.GetIndices().size(), &a.GetIndices()[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

			glBindTexture(GL_TEXTURE_2D, a.GetImage()->getTextureId());

			glDrawElements(GL_TRIANGLES, a.GetIndices().size(), GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));

		
			
			_drawables.erase(_drawables.begin());
		}
			glBindTexture(GL_TEXTURE_2D, 0u);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glUseProgram(0);

			SwapBuffers(_rcontext->getHDC());//Bring back buffer to foreground

			wglMakeCurrent(GetDC(_rcontext->getWindow()->CMWindowHandle()), _rcontext->getRenderingContext());

			_drawables.clear();
	}
void GraphicContext::Draw(CMRectangle rec)
	{	
		_drawables.push_back(rec);
	}
}