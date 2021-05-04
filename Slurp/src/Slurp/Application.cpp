#include "Application.h"

namespace Slurp
{
	Application::Application()
	{
		Timestep::Init();
		window = new Window();
	}

	Application::~Application()
	{
		delete window;
	}

	void Application::Run()
	{
		double previousTime = Timestep::GetTimeSinceStart();
		double lag = 0.0;

		while (window->IsWindowOpen())
		{
			double currentTime = Timestep::GetTimeSinceStart();
			Timestep::SetDeltaTime(currentTime - previousTime);
			previousTime = currentTime;
			lag += Timestep::GetDeltaTime();

			sf::Event event;

			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window->CloseWindow();
				}
			}

			while (lag >= Timestep::GetMinimumFrameTime())
			{
				Update(Timestep::GetMinimumFrameTime());
				lag -= Timestep::GetMinimumFrameTime();
			}

			window->Render();
		}
	}

	void Application::Update(double deltaTime)
	{
	}
}
