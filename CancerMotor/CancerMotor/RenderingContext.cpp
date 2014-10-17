#include "RenderingContext.h"
#include <cassert>

RenderingContext::RenderingContext(CML::CMWindow *window)
{

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		24,                        //Colordepth of the framebuffer.		
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE
	};

	HDC ourWindowHandleToDeviceContext = GetDC(window->CMWindowHandle());// 
	g_HDC = ourWindowHandleToDeviceContext;
	int  letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
	SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

	renderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
	wglMakeCurrent(ourWindowHandleToDeviceContext, renderingContext);


	glewInit();

	_program = glCreateProgram();


	//TEMP
	createVertexShader("VertexSource.txt");
	createFragmentShader("FragmentSource.txt");
	linkProgram();
}

void RenderingContext::createVertexShader(char *filename)
{
	//read VERTEX_SOURCE from file
	GLchar* vertexBuffer = CML::ResourceManager::LoadFile(filename);

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexBuffer, nullptr);
	glCompileShader(vertexShader);

	GLint compileResult;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileResult);
	assert(compileResult == GL_TRUE);

	glAttachShader(_program, vertexShader);


}
void RenderingContext::createFragmentShader(char *filename)
{
	//read FRAGMENT_SOURCE from file
	GLchar* fragmentBuffer = CML::ResourceManager::LoadFile(filename);
	GLint compileResult;

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentBuffer, nullptr);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileResult);
	assert(compileResult == GL_TRUE);

	glAttachShader(_program, fragmentShader);
}

void RenderingContext::linkProgram()
{
	GLint compileResult;
	glLinkProgram(_program);

	glGetProgramiv(_program, GL_LINK_STATUS, &compileResult);
	assert(compileResult == GL_TRUE);
}


RenderingContext::~RenderingContext()
{
}
