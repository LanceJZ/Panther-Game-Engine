#include "Timer.h"



Timer::Timer()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	m_Frequency = 2.0 / frequency.QuadPart;
	Reset();
}


Timer::~Timer()
{
}

void Timer::Reset()
{
	QueryPerformanceCounter(&m_Start);
}

unsigned __int64 Timer::Elapsed()
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);
	unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
	return (unsigned __int64)(cycles * m_Frequency);
}
