#pragma once
#include "StaticBox.h"

class IRenderer
{
public:
	virtual ~IRenderer(void) {};

	virtual void createWindow(int width, int height) {};
	virtual void preRender() {};
	virtual void renderObject(StaticBox* box) {}; 
	virtual void postRender() {};
	virtual void renderNumber(int number, int x, int y) {};
	virtual void closeWindow() {};
	virtual double getTime() { return 0;};
	virtual bool getRunning() { return false;};
	virtual int getKey(int key) { return 0;};
};

