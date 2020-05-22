#ifndef FUNCTION_H__
#define FUNCTION_H__

HeightInfo CalcHeight(const float _x, const float _quarterWaveLength, const float maxHeight, int Count, int _kBufferSize)
{
	int iNew = Count;
	if (0 > Count)
	{
		iNew = -Count - 1;
	}
	else if (Count >= static_cast<int>(_kBufferSize))
	{
		iNew = 2 * _kBufferSize - Count - 1;
	}

	float distance = std::fabs((Count + 0.5f) / _kBufferSize - _x);
	float height = maxHeight * 0.5f * (std::cos(std::fminf(distance * M_PI / _quarterWaveLength, M_PI))) + 1.0f;

	return HeightInfo(iNew, height);
}

void accumulateWaveToHeightField(WaveData* _Data, std::array<float, kBufferSize>& heightField)
{
	const int size = heightField.size();
	const int first = (*_Data).Start(heightField.size());
	const int last = (*_Data).End(heightField.size());
	for (int Index = first; last > Index;++Index)
	{
		HeightInfo GetHeight = CalcHeight((*_Data).Position, (*_Data).QuarterWaveLength, (*_Data).MaxHeight, Index, size);
		heightField.data()[GetHeight.Index] = GetHeight.Height;
	}
}

void DrawOnCMD(std::array<float, kBufferSize>& heightField)
{
	int ArraySize = heightField.size();

	std::string buffer(ArraySize, ' ');

	for (size_t Index = 0; ArraySize > Index; ++Index)
	{
		float height = heightField[Index];
		size_t tableIndex = std::min(static_cast<size_t>(std::floor(kGrayScaleTableSize * height)), kGrayScaleTableSize - 1);
		buffer[Index] = kGrayScaleTable[tableIndex];
	}

	for (size_t Index = 0; ArraySize > Index; ++Index)
	{
		printf("\b");
	}

	// Draw new buffer
	printf("%s", buffer.c_str());
	fflush (stdout);
}

#endif