#include "Window.h

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

	void Window::AddDrawable(sf::Drawable* drawable)
	{
		// Add drawable object
		objects.push_back(drawable);
	}

	void Window::RemoveDrawable(sf::Drawable* drawable)
	{
		// Remove drawable object
		objects.erase(std::find(objects.begin(), objects.end(), drawable));
	}

	void Window::Render()
	{
		// Render all objects
		window->clear();
		for (auto it = objects.begin(); it != objects.end(); it++)
		{
			window->draw(**it);
		}
		window->display();
	}
}