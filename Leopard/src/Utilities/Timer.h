#pragma once

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <time.h>

#if _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

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

