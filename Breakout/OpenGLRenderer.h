#pragma once
#include "irenderer.h"
#include <GLFW/glfw3.h>
#include "KeyInput.h"

#include "0.c"		
#include "1.c"		
#include "2.c"		
#include "3.c"		
#include "4.c"		
#include "5.c"		
#include "6.c"		
#include "7.c"		
#include "8.c"		
#include "9.c"	

class OpenGLRenderer :
	public IRenderer
{

private:
	bool mRunning;
	GLFWwindow* mWindow;
	int m_Width, m_Height;
	GLuint score;

public:
	OpenGLRenderer(void);
	~OpenGLRenderer(void);

	virtual void createWindow(int width, int height);
	virtual void preRender();
	virtual void renderObject(StaticBox* box);
	virtual void postRender();
	virtual void renderNumber(int number, int x, int y);
	virtual void closeWindow();
	virtual double getTime();
	virtual bool getRunning();
	virtual int getKey(int key);
};

