#pragma once
#include <string>
#include <SDL.h>


struct Colour
{
	Uint8 red;
	Uint8 green;
	Uint8 blue;
	Uint8 alpha;
};

class Window
{
public:
	Window(const std::string& name, int x, int y, int width, int height);
	void Run();
	~Window();
	
private:
	bool m_isRunning;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	int m_windowX;
	int m_windowY;
	int m_windowWidth;
	int m_windowHeight;
	std::string m_windowName;

	bool Initialise();
	
};