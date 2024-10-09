#include <iostream>
#include <string>
#include "simple_window.h"

int main(int argc, char* argv[])
{
	std::string windowName;
	int x, y, width, height;
	std::cout << "Enter the window name: ";
	std::getline(std::cin, windowName);
	std::cout << "Enter the window paremeters (x y width height): ";
	std::cin >> x >> y >> width >> height;
	Window myWindow = Window(windowName, x, y, width, height);
	myWindow.Run();
	return 0;
}