#pragma once

#include "Core.h"
#include "Timestep.h"
#include "Window.h"

namespace Slurp
{
	class SLURP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		//Method Should be overriden in sandbox
		virtual void Update(double deltaTime);

		Window* window;
	};

	// To be defined in client
	Application* CreateApplication();
}


