#pragma once
class IRenderer
{
public:
	virtual ~IRenderer(void);

	virtual void createWindow(int width, int height);
	virtual void closeWindow();
	virtual double getTime();
	virtual bool getRunning();
	virtual int getKey(int key);
};

