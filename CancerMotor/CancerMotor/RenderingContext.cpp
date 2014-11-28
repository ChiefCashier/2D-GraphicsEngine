#include "RenderingContext.h"
#include <cassert>
namespace CML
{
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
		WORD  nSize = sizeof(PIXELFORMATDESCRIPTOR);
		WORD  nVersion  = 1;
		DWORD dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits  = 24;
		pfd.cRedBits  = 0;
		pfd.cRedShift  = 0;
		pfd.cGreenBits  = 0;
		pfd.cGreenShift  = 0;
		pfd.cBlueBits  = 0;
		pfd.cBlueShift  = 0;
		pfd.cAlphaBits  = 0;
		pfd.cAlphaShift  = 0;
		pfd.cAccumBits  = 0;
		pfd.cAccumRedBits  = 0;
		pfd.cAccumGreenBits  = 0;
		pfd.cAccumBlueBits  = 0;
		pfd.cAccumAlphaBits  = 0;
		pfd.cDepthBits  = 24;
		pfd.cStencilBits  = 8;
		pfd.cAuxBuffers  = 0;
		pfd.iLayerType  = 0;
		pfd.bReserved  = 0;
		DWORD dwLayerMask  = NULL;
		DWORD dwVisibleMask  = NULL;
		DWORD dwDamageMask  = NULL;


		_window = window;
		HDC ourWindowHandleToDeviceContext = GetDC(window->CMWindowHandle());// 
		g_HDC = ourWindowHandleToDeviceContext;
		int  letWindowsChooseThisPixelFormat;
		letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
		SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

		renderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
		wglMakeCurrent(ourWindowHandleToDeviceContext, renderingContext);


		glewInit();


		_program = glCreateProgram();

		createVertexShader();
		createFragmentShader();

		
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

		linkProgram();
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

		linkProgram();
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
	CML::CMWindow *RenderingContext::getWindow()
	{
		return _window;
	}
}