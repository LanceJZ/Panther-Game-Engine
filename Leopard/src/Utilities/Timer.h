#pragma once

#include <Windows.h>

class Timer
{
private:
	LARGE_INTEGER m_Start;
	double m_Frequency;
public:
	Timer();
	~Timer();

	void Reset();
	unsigned __int64 Elapsed();
};

