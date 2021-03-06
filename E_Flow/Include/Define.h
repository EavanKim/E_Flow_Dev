#ifndef DEFINE_H__
#define DEFINE_H__

const size_t kBufferSize = 100;

const char* kGrayScaleTable = " .:-=+*#%@";
const size_t kGrayScaleTableSize = sizeof(kGrayScaleTable) / sizeof(char);

#define M_E        2.71828182845904523536f   // e
#define M_LOG2E    1.44269504088896340736f   // log2(e)
#define M_LOG10E   0.434294481903251827651f  // log10(e)
#define M_LN2      0.693147180559945309417f  // ln(2)
#define M_LN10     2.30258509299404568402f   // ln(10)
#define M_PI       3.14159265358979323846f   // pi
#define M_PI_2     1.57079632679489661923f   // pi/2
#define M_PI_4     0.785398163397448309616f  // pi/4
#define M_1_PI     0.318309886183790671538f  // 1/pi
#define M_2_PI     0.636619772367581343076f  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390f   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880f   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401f  // 1/sqrt(2)

struct WaveData
{
	WaveData(float _Pos, float _Speed, float _WLength, float _MaxHeight)
	{
		Position = _Pos;
		Speed = _Speed;
		WaveLength = _WLength;
		MaxHeight = _MaxHeight;
		QuarterWaveLength = GetQuarterWaveLength();
	}

	void Update(const float _timeInterval)
	{
		Position += _timeInterval * Speed;

		DirectionReverse(_timeInterval);
	}

	void DirectionReverse(const float _timeInterval)
	{
		if (Position > 1.f)
		{
			Speed *= -1.0f;
			Position = 1.0f + _timeInterval * Speed;
		}
		else if (Position < 0.f)
		{
			Speed *= -1.0f;
			Position = _timeInterval * Speed;
		}
	}

	float GetQuarterWaveLength()
	{
		return 0.35f * WaveLength;
	}

	int Start(int _BufferSize)
	{
		return static_cast<int>((Position - QuarterWaveLength) * _BufferSize);
	}

	int End(int _BufferSize)
	{
		return static_cast<int>((Position + QuarterWaveLength) * _BufferSize);
	}

	float Position = 0.f;
	float Speed = 0.f;
	float WaveLength = 0.f;
	float MaxHeight = 0.f;
	float QuarterWaveLength = 0.f;
};

struct HeightInfo
{
	HeightInfo(int _Index, float _Height)
	{
		Index = _Index;
		Height = _Height;
	}

	int Index = 0;
	float Height = 0.f;
};

#endif