#include "pch.h"

int main()
{	
	const int fps = 100;
	const float timeInterval = 1.0f / fps;
	
	WaveData X = 
	{
		0.f //First Wave Position
		, 1.f //First Wave Speed
		, 0.5f //First Wave Length
		, 0.2f //First Wave Maximum Height
	};
	WaveData Y = 
	{ 
		1.f //Second Wave Position
		, -1.f //Second Wave Speed
		, 0.8f //Second Wave Length
		, 0.1f //Second Wave Maximum Height
	};

	std::array<float, kBufferSize> heightField;
		
	for (int Count = 0; 1000 > Count; ++Count)
	{
		//Update
		X.Update(timeInterval);
		Y.Update(timeInterval);

		memset(heightField.data(), 0, kBufferSize * sizeof(float));

		accumulateWaveToHeightField(&X, heightField);
		accumulateWaveToHeightField(&Y, heightField);

		DrawOnCMD(heightField);

		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
	}
	return 0;
}