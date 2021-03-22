#pragma once

#ifdef SLURP_PLATFORM_WINDOWS

extern Slurp::Application* Slurp::CreateApplication();

int main(int argc, char** argv)
{
	Slurp::Log::Init();
	SLURP_CORE_INFO("Initialized Log!");
	auto app = Slurp::CreateApplication();
	app->Run();
	delete app;
}

#endif