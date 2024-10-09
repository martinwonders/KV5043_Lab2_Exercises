#include <iostream>
#include <string>
#include "simple_window.h"

int main(int argc, char* argv[])
{
	const std::string windowName = "Test Window";
	int x = 100;
	int y = 300;
	int width = 800;
	int height = 600;
	Window myWindow = Window(windowName, x, y, width, height);
	myWindow.Run();
	return 0;
}