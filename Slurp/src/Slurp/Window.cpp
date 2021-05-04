#include "Window.h"

namespace Slurp
{
	Window::Window()
	{
		window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Window");
	}

	Window::~Window()
	{
		delete window;
	}

	bool Window::IsWindowOpen()
	{
		return window->isOpen();
	}

	void Window::CloseWindow()
	{
		window->close();
	}

	bool Window::pollEvent(sf::Event& event)
	{
		return window->pollEvent(event);
	}

	// save object to be drawn
	void Window::QueueDrawable(sf::Drawable* drawable)
	{
		objects.push_back(drawable);
	}

	//draw all objects that have been stored
	void Window::Render()
	{
		window->clear();
		for (auto i = objects.begin(); i != objects.end(); i++)
		{
			window->draw(**i);
		}
		window->display();
	}
}