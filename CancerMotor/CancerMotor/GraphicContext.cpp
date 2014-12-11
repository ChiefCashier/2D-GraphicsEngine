#include "GraphicContext.h"
#include <assert.h>
namespace CML
{
	std::vector<CMShape*> GraphicContext::_drawables;
	GraphicContext::GraphicContext()
	{
		
	}
	GraphicContext::GraphicContext(RenderingContext *rcontext)
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
		this->_rcontext = rcontext;
		InitializeOpengl();
	}
	void GraphicContext::InitializeOpengl()
	{
		glGenBuffers(2, buffers);
		//activate attribute arrays
		_positionIndex = glGetAttribLocation(_rcontext->getProgramIndex(), "attrPosition");
		assert(_positionIndex >= 0);
		glEnableVertexAttribArray(_positionIndex);

		_colorIndex = glGetUniformLocation(_rcontext->getProgramIndex(), "attrColor");
		assert(_colorIndex >= 0);
		glEnableVertexAttribArray(_colorIndex);

		_textureIndex = glGetAttribLocation(_rcontext->getProgramIndex(), "attrTexCoord");
		assert(_textureIndex >= 0);
		glEnableVertexAttribArray(_textureIndex);


		_samplerLocation = glGetUniformLocation(_rcontext->getProgramIndex(), "myTexture");
		assert(_samplerLocation >= 0);

		_projectionLocation = glGetUniformLocation(_rcontext->getProgramIndex(), "unifProjection");
		assert(_projectionLocation >= 0);

		_alphaChannel = glGetUniformLocation(_rcontext->getProgramIndex(), "alphaChannel");
		assert(_alphaChannel >= 0);

		glUseProgram(_rcontext->getProgramIndex());


		_defaultProjection = glm::ortho(0.0f,	static_cast<float>(_rcontext->getWindow()->_windowWidht),
												 0.0f,	static_cast<float>(_rcontext->getWindow()->_windowHeight),
												 -1.0f, 1.0f);


		glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

		glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

		glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

		glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));

		glUseProgram(0u);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void GraphicContext::EndDraw()
	{
		//wglMakeCurrent(GetDC(_rcontext->getWindow()->CMWindowHandle()), _rcontext->getRenderingContext());
		glFlush();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		//actual draw

		CMShape *_drawableShape = *_drawables.begin();
			
		glUseProgram(_rcontext->getProgramIndex());


		for (int i = 0; i < _drawables.size(); i++)
		{
			_drawableShape = _drawables.at(i);
			//elegant way of transforming primitives

			if (_drawableShape->GetIndices().size() == 0)
			{
				RemoveDrawable(_drawableShape);
				i--;
				continue;
			}
			//first projection, as it should be
			_projection = _defaultProjection;


			//then translate the primitive where it should be 
			_projection = glm::translate(_projection, glm::vec3(_drawableShape->GetX(), _drawableShape->GetY(), 0.0f));


			//then scale the primitive as it should be 
			if (_drawableShape->GetSize().getX() != 1 || _drawableShape->GetSize().getY() !=1)
				_projection = glm::scale(_projection, glm::vec3(_drawableShape->GetSize().getX(), _drawableShape->GetSize().getY(), 0.0f));


			//then rotate the primitive as it should be
			if (_drawableShape->GetRotation() != 0 || _drawableShape->GetOrigon().getX() != 0 || _drawableShape->GetOrigon().getY() != 0)
			{
				_projection	= glm::rotate(_projection, (float)_drawableShape->GetRotation(), glm::vec3(0.0f, 0.0f, 1.0f))* glm::translate(glm::vec3(-_drawableShape->GetOrigon().getX(), -_drawableShape->GetOrigon().getY(), 0.0f));
			}

			//finish with a touch of mint and glUniformMatrix4fv, and voilá!
			glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));
			//you got yourself a handy way of dumping your workload to the GPU!

			glUniform3f(_colorIndex, _drawableShape->GetColorR(), _drawableShape->GetColorG(), _drawableShape->GetColorB());
			glUniform1f(_alphaChannel, _drawableShape->GetColorA());
			

			//set vertex data
			glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* _drawableShape->GetVertices().size(), &_drawableShape->GetVertices()[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			//set fragment data


			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*_drawableShape->GetIndices().size(), &_drawableShape->GetIndices()[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

			glBindTexture(GL_TEXTURE_2D, _drawableShape->GetImage()->getTextureId());

			glDrawElements(GL_TRIANGLES, _drawableShape->GetIndices().size(), GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));

		
			
			

		
			
		}
			glBindTexture(GL_TEXTURE_2D, 0u);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glUseProgram(0);

			SwapBuffers(_rcontext->getHDC());//Bring back buffer to foreground

			

	}
	void GraphicContext::Draw(CMShape *rec)
	{
		if (std::find(_drawables.begin(), _drawables.end(), rec) == _drawables.end()) {
			/* v contains x */
			
			_drawables.push_back(rec);
		}
	}
	void GraphicContext::RemoveDrawable(CMShape* rec)
	{
		for (std::vector<CMShape*>::iterator it = _drawables.begin(); it != _drawables.end(); it++)
		{
			/* v contains x */
			if (*it == rec)
			{
				std::cout << "hullut paevat" << std::endl;
				_drawables.erase(it);
				break;
			}
		}
	
	}
}