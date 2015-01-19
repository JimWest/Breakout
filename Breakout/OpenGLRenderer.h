#pragma once
#include "irenderer.h"
#include <GLFW/glfw3.h>

class OpenGLRenderer :
	public IRenderer
{

private:
	bool mRunning;
	GLFWwindow* mWindow;
	int m_Width, m_Height;

public:
	OpenGLRenderer(void);
	~OpenGLRenderer(void);

	virtual void createWindow(int width, int height);
	virtual void preRender();
	virtual void renderObject(StaticBox* box);
	virtual void postRender();
	virtual void renderString(const char *filename, const char *string, const size_t length, int pixel_size);
	virtual void closeWindow();
	virtual double getTime();
	virtual bool getRunning();
	virtual int getKey(int key);
};

