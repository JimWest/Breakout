#include "StdAfx.h"
#include "GameWindow.h"


void GameWindow::setRunning(bool newRunning)
{
	mRunning = newRunning;
}

bool GameWindow::getRunning()
{
	return mRunning && !glfwWindowShouldClose(mWindow);
}

GLFWwindow* GameWindow::getWindow()
{
	return this->mWindow;
}


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}



GameWindow::GameWindow(int width, int height)
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



GameWindow::~GameWindow(void)
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}


