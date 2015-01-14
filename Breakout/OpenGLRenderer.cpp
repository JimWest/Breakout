#include "StdAfx.h"
#include "OpenGLRenderer.h"


OpenGLRenderer::OpenGLRenderer(void)
{
}


OpenGLRenderer::~OpenGLRenderer(void)
{
}

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}


void OpenGLRenderer::createWindow(int width, int height)
{
	/* Initialize the library */
	glfwInit();  
	glfwSetErrorCallback(error_callback);
	

	mRunning = true;

	/* Create a windowed mode window and its OpenGL context */
	mWindow = glfwCreateWindow(width, height, "Breakout", NULL, NULL);

	if (!mWindow)
	{
		glfwTerminate();
	}	
	
	glfwMakeContextCurrent(mWindow);
	
	float ratio;
	glfwGetFramebufferSize(mWindow, &width, &height);
	ratio = width / (float) height;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLRenderer::closeWindow()
{
	glfwSetWindowShouldClose(mWindow, GL_TRUE);
	mRunning = false;
}

double OpenGLRenderer::getTime()
{
	return glfwGetTime();
}

bool OpenGLRenderer::getRunning()
{
	return mRunning && !glfwWindowShouldClose(mWindow);
}

int OpenGLRenderer::getKey(int key)
{
	return glfwGetKey(mWindow, key);
}
