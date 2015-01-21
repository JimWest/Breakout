#pragma once
#include "irenderer.h"
#include <GLFW/glfw3.h>
#include "OpenGLFont.h"

class OpenGLRenderer :
	public IRenderer
{

private:
	bool mRunning;
	GLFWwindow* mWindow;
	int m_Width, m_Height;
	OpenGLFont* font;

public:
	OpenGLRenderer(void);
	~OpenGLRenderer(void);

	virtual void createWindow(int width, int height);
	virtual void preRender();
	virtual void renderObject(StaticBox* box);
	virtual void postRender();
	virtual void renderString(const std::string& str, float x, float y);
	virtual void closeWindow();
	virtual double getTime();
	virtual bool getRunning();
	virtual int getKey(int key);
};

