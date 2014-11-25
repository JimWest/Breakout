#pragma once
#include <GLFW/glfw3.h>

class GameWindow
{

private:
	bool mRunning;
	GLFWwindow* mWindow;

public:	
	void setRunning(bool newRunning);
	bool getRunning();
	GLFWwindow* getWindow();

	GameWindow(int width, int height);
	~GameWindow(void);
};

