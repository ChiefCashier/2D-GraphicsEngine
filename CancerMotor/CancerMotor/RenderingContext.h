#pragma once
#include "CMWindow.h"
namespace CML
{
	class RenderingContext
	{
	public:
		RenderingContext(CML::CMWindow *window);
		RenderingContext(){};
		~RenderingContext();
		void createVertexShader(char *filename = "VertexSource.txt");
		void createFragmentShader(char *filename = "FragmentSource.txt");
		void linkProgram();
		GLuint getProgramIndex(){ return _program; };
		HDC getHDC(){ return g_HDC; };

		HGLRC getRenderingContext(){ return renderingContext; };
		CML::CMWindow *getWindow();
	private:
		CML::CMWindow *_window;
		HGLRC renderingContext;
		HDC g_HDC;
		GLuint _program;
		GLuint vertexShader;
		GLuint fragmentShader;

	};

}