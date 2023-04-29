#pragma once
#include <windows.h>
#include <iostream>
#include <iomanip>
class Timer
{
private:
    /// <summary>
    /// remembers starts time
    /// </summary>
    long long int timerStartTime;

    /// this function reads counter (ticks)
    /// ticks amount in given moment
    long long int ReadQPC();
public:
    
    Timer();
    ~Timer();

    /// this function starts timer
    void StartTimer();

    /// this function stops timer
    /// return time elapsed science timer started in us
    double TimerStop();
};

Timer::Timer()
{
    Timer::timerStartTime = 0;
}

Timer::~Timer()
{

}

/// <summary>
/// 
/// </summary>
/// <returns></returns> ticks amounts
long long int Timer::ReadQPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int)count.QuadPart);
}


void Timer::StartTimer()
{
    Timer::timerStartTime = 0;
    Timer::timerStartTime = Timer::ReadQPC();
}

double Timer::TimerStop()
{
    long long int elapsed = Timer::ReadQPC() - Timer::timerStartTime;

    LARGE_INTEGER count;
   
    //returns  how long is tick
    QueryPerformanceFrequency(&count);

    return  (1000000.0 * elapsed) / ((long long int)count.QuadPart);
}
