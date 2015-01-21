#include "StdAfx.h"
#include "OpenGLRenderer.h"


OpenGLRenderer::OpenGLRenderer(void)
{
	const char *file = "arial.font";
	font = new OpenGLFont(file);
}


OpenGLRenderer::~OpenGLRenderer(void)
{
	delete font;
	glfwTerminate();
}


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}


void OpenGLRenderer::createWindow(int width, int height)
{
	m_Width = width;
	m_Height = height;
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
	glEnable(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void OpenGLRenderer::preRender()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glOrtho(0 ,m_Width, m_Height, 0, -1, 1);
}

void OpenGLRenderer::renderObject(StaticBox* box)
{	
	glColor3f(box->getColor().getR(), box->getColor().getG(), box->getColor().getB()); // (0.5, 0, 1) is half red and full blue, giving dark purple.

	 glBegin(GL_QUADS); 
		glVertex2f(box->getOrigin().x, box->getOrigin().y);
		glVertex2f(box->getOrigin().x + box->getWidth(), box->getOrigin().y);
		glVertex2f(box->getOrigin().x + box->getWidth(), box->getOrigin().y + box->getHeight());
		glVertex2f(box->getOrigin().x, box->getOrigin().y + box->getHeight());
	glEnd( );
}


void OpenGLRenderer::postRender()
{	
	glPopMatrix();

	/*
	glPushMatrix();	
	glTranslatef(200, 0, 0);
	glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex2f(0.0f, 0.0f);

		glColor3ub(0, 0 ,255);
		glVertex2f(800.0f, 600.0f);
	glEnd();

	glPopMatrix();
	*/

	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}


void OpenGLRenderer::renderString(const std::string& str, float x, float y)
{	
	font->Draw_String(str, x, y);
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
