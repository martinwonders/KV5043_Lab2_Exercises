#include "window.h"
#include <iostream>
#include <SDL.h>


Window::Window(const std::string& name, int x, int y, int width, int height)
	: 
	m_windowName(name),
	m_windowX(x),
	m_windowY(y),
	m_windowWidth(width),
	m_windowHeight(height),
	m_isRunning(true)
{	
	if (!Initialise())
	{
		m_isRunning = false;
		std::cerr << "Error initialising SDL..." << std::endl;
	}
}

void Window::Run()
{
	while (m_isRunning)
	{
		
		/////////////////////////////////////
		//Process input here
		/////////////////////////////////////
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				m_isRunning = false;
			}

		}

		/////////////////////////////////////
		//Render any elements here
		/////////////////////////////////////
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderClear(m_renderer);
		
		/////////////////////////////////////
		//Present
		/////////////////////////////////////
		SDL_RenderPresent(m_renderer);
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Window::Initialise()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return false;
	}
	m_window = SDL_CreateWindow(m_windowName.c_str(), m_windowX, m_windowY, m_windowWidth, m_windowHeight, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	return true;
}
