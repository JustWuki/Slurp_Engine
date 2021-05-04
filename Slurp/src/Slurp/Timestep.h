#pragma once

#include "Core.h"
#include <chrono>

namespace Slurp
{
	class SLURP_API Timestep
	{
	public:
		static void Init();
		static double GetTimeSinceStart();

		static double GetDeltaTime();
		static void SetDeltaTime(double deltaTime);
		
		static double GetMinimumFrameTime();
		static void SetMinimumFrameTime(double frameTime);

	private:
		inline static std::chrono::system_clock::time_point startTime;
		inline static double MinimumFrameTime;
		inline static double DeltaTime;
	};
}