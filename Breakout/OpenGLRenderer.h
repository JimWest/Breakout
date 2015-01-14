#pragma once
#include "irenderer.h"
#include <GLFW/glfw3.h>

class OpenGLRenderer :
	public IRenderer
{

private:
	bool mRunning;
	GLFWwindow* mWindow;

public:
	OpenGLRenderer(void);
	~OpenGLRenderer(void);

	virtual void createWindow(int width, int height);
	virtual void closeWindow();
	virtual double getTime();
	virtual bool getRunning();
	virtual int getKey(int key);
};

