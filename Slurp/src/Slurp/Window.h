#pragma once

#include "Core.h"
#include <SFML/Graphics.hpp>

namespace Slurp
{
	class SLURP_API Window
	{
	public:
		Window();
		~Window();
		bool IsWindowOpen();
		void CloseWindow();
		bool pollEvent(sf::Event& event);

		void QueueDrawable(sf::Drawable* drawable);

		void Render();

	private:
		const unsigned int windowWidth = 1920;
		const unsigned int windowHeight = 1080;
		sf::RenderWindow* window;
		std::vector<sf::Drawable*> objects;
	};
}