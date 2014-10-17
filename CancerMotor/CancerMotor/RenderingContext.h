#pragma once
#include "CMWindow.h"
class RenderingContext
{
public:
	RenderingContext(CML::CMWindow *window);
	RenderingContext(){};
	~RenderingContext();
	void createVertexShader(char *filename);
	void createFragmentShader(char *filename);
	void linkProgram();
	GLuint getProgramIndex(){ return _program; };
	HDC getHDC(){ return g_HDC; };
	HGLRC getRenderingContext(){ return renderingContext; };
private:
	HGLRC renderingContext;
	HDC g_HDC;
	GLuint _program;
	GLuint vertexShader;
	GLuint fragmentShader;
	
};

