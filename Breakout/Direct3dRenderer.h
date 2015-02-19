#pragma once
#include "irenderer.h"
class Direct3dRenderer :
	public IRenderer
{
		
private:
	bool mRunning;	
	//HWND hWnd;
	int m_Width, m_Height;	
	

public:
	Direct3dRenderer(void);
	~Direct3dRenderer(void);

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

