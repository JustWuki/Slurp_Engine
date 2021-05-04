#include "Timestep.h"

namespace Slurp
{
	void Timestep::Init()
	{
		startTime = std::chrono::system_clock::now();
		SetMinimumFrameTime(1 / 60.f);
	}

	double Timestep::GetTimeSinceStart()
	{
		return std::chrono::duration<double>(std::chrono::system_clock::now() - startTime).count();
	}

	double Timestep::GetDeltaTime()
	{
		return DeltaTime;
	}

	void Timestep::SetDeltaTime(double deltaTime)
	{
		DeltaTime = deltaTime;
	}

	double Timestep::GetMinimumFrameTime()
	{
		return MinimumFrameTime;
	}

	void Timestep::SetMinimumFrameTime(double frameTime)
	{
		MinimumFrameTime = frameTime;
	}
}