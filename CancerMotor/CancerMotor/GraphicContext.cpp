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
		//texture stuff

		glGenTextures(1, &_texture);//generates texture
	}
	void GraphicContext::EndDraw()
	{
		drawable a = *_drawables.begin();
		//remove

		//remove
			//set vertex data
			glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * a.vertices.size(), &a.vertices[0], GL_STATIC_DRAW);//sizeof(_vertexBufferInput) might return a value that is not always correct...
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			std::cout << "vertexBufferInput works, yay" << std::endl;
			//set fragment data
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*a.indices.size(), &a.indices[0], GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			std::cout << "FragmentBufferInput works too, another yay" << std::endl;

			const glm::mat4 _projection = glm::ortho(0.0f, static_cast<float>(_rcontext->getWindow()->_windowWidht), 0.0f, static_cast<float>(_rcontext->getWindow()->_windowHeight), -1.0f, 1.0f);

			glUseProgram(_rcontext->getProgramIndex());
			glUniformMatrix4fv(_projectionLocation, 1, GL_FALSE, reinterpret_cast<const float*>(&_projection));

			glUseProgram(0u);



			//actual draw
			glFlush();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(_rcontext->getProgramIndex());



			glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

			glVertexAttribPointer(_positionIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(0));

			glVertexAttribPointer(_colorIndex, 3, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(8));

			glVertexAttribPointer(_textureIndex, 2, GL_FLOAT, GL_FALSE, 28, reinterpret_cast<GLvoid*>(20));


			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);

			glBindTexture(_rcontext->getProgramIndex(), _texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glDrawElements(GL_TRIANGLES, a.indices.size(), GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));
			glBindTexture(_rcontext->getProgramIndex(), 0u);
			glDeleteTextures(1, &_texture);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glUseProgram(0);

			SwapBuffers(_rcontext->getHDC());//Bring back buffer to foreground


		_drawables.clear();
	}
	void GraphicContext::Draw(Rectangle rec)
	{
		//CML::CMSprite sprite = CML::CMSprite::CMSprite(0.0f, 0.0f, 200.0f, 150.0f, "Sample.png");
		CML::CMSprite sprite2 = CML::CMSprite::CMSprite(200.0f, 150.0f, 400.0f, 300.0f, "Sample.png");

		glTexImage2D(GL_TEXTURE_2D, 0, 4, sprite2.GetImage().getWidth(), sprite2.GetImage().getHeight(), 0, sprite2.GetImage().getImageFormat(), GL_UNSIGNED_BYTE, FreeImage_GetBits(sprite2.GetImage().getBITMAP()));

		glBindTexture(_rcontext->getProgramIndex(), _texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0u);

		glActiveTexture(GL_TEXTURE0);
		drawable d;
		//top left
		d.vertices.push_back((GLfloat)rec.GetX());
		d.vertices.push_back((GLfloat)rec.GetY());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)0.0f);//rec.GetX());
		d.vertices.push_back((GLfloat)-1.0f);//rec.GetY() - rec.GetHeight());
		//top right
		d.vertices.push_back((GLfloat)rec.GetX()+rec.GetWidth());
		d.vertices.push_back((GLfloat)rec.GetY());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)0.0f);//rec.GetX());
		d.vertices.push_back((GLfloat)0.0f);//rec.GetY());
		//bottom right
		d.vertices.push_back((GLfloat)rec.GetX() + rec.GetWidth());
		d.vertices.push_back((GLfloat)rec.GetY() - rec.GetHeight());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)1.0f);//rec.GetX()+rec.GetWidth());
		d.vertices.push_back((GLfloat)0.0f);//rec.GetY());
		//bottom left
		d.vertices.push_back((GLfloat)rec.GetX());
		d.vertices.push_back((GLfloat)rec.GetY() - rec.GetHeight());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)rec.GetColor());
		d.vertices.push_back((GLfloat)1.0f);//rec.GetX()+ rec.GetWidth());
		d.vertices.push_back((GLfloat)-1.0f);//rec.GetY() - rec.GetHeight());

		d.indices.push_back(0u);
		d.indices.push_back(1u);
		d.indices.push_back(2u);
		d.indices.push_back(2u);
		d.indices.push_back(3u);
		d.indices.push_back(0u);
		_drawables.push_back(d);



	}
}