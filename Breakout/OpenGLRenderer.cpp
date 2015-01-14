#include "StdAfx.h"
#include "OpenGLRenderer.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_GLCOREARB


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

void OpenGLRenderer::preRender()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::renderObject(StaticBox* box)
{	
	glPushMatrix();
	glTranslatef(box->getOrigin().x, box->getOrigin().y, 0);

	glColor3f(box->getColor().getR(), box->getColor().getG(), box->getColor().getB()); // (0.5, 0, 1) is half red and full blue, giving dark purple.

	glBegin(GL_POLYGON);	
		glVertex2f(0.0f, 0.0f);
		glVertex2f(box->getWidth(), 0.0f);
		glVertex2f(box->getWidth(), box->getHeight());
		glVertex2f(0.0f, box->getHeight());
	glEnd( );

	glPopMatrix();
}

void OpenGLRenderer::postRender()
{
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
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
