#include <iostream>
#include "simple_window.h"

int main(int argc, char* argv[])
{
	Window myWindow = Window("test", 100, 300, 800, 600);
	myWindow.Run();
	return 0;
}