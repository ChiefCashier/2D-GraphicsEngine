#include "GraphicContext.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

#include <assert.h>
namespace CML
{
	GraphicContext::GraphicContext()
	{
	}


	GraphicContext::~GraphicContext()
	{
	}
	void GraphicContext::BeginDraw(CML::CMWindow *window)
	{
		this->_rcontext = new RenderingContext(window);
		_rcontext->createVertexShader();
		_rcontext->createFragmentShader();
		setShit();
	}
	void GraphicContext::BeginDraw(RenderingContext *rcontext)
	{

		this->_rcontext = rcontext;//new RenderingContext();
		setShit();
	}
	void GraphicContext::setShit()
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


		const glm::mat4 _projection = glm::ortho(0.0f,	static_cast<float>(_rcontext->getWindow()->_windowWidht),
												 0.0f,	static_cast<float>(_rcontext->getWindow()->_windowHeight),
												 -1.0f, 1.0f);


		glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

		glUseProgram(0u);


	}
	void GraphicContext::EndDraw()
	{
		glFlush();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//remove

		//remove




		//actual draw


			

		glUseProgram(_rcontext->getProgramIndex());

		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

		glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

		glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

		glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));
		

		for (int i = 0; i < _drawables.size(); i++)
		{
			drawable a = *_drawables.begin();
			//set vertex data
			glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* a.vertices.size(), &a.vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			//set fragment data
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*a.indices.size(), &a.indices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

			glBindTexture(1, _texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glDrawElements(GL_TRIANGLES, a.indices.size(), GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));

		
			
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



		glActiveTexture(rec.GetImage().getTextureId());
		drawable d;
		//top left
		for (int i = 0; i < 28; i++)
			d.vertices.push_back(rec.GetVertices()[i]);

		for (int j = 0; j < 6; j++)
			d.indices.push_back(rec.GetIndices()[j]);
		_drawables.push_back(d);



	}
}