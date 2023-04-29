#pragma once
#include <iomanip>
#include <random>
#include <windows.h>

class RandomGenerator
{
private:
    std::mt19937 generator;
public:
    RandomGenerator();
    ~RandomGenerator();


    /// <summary>
    /// Function return random number within min, max - inclusive.
    /// </summary>
    /// <param name="min"></param>
    /// <param name="max"></param>
    /// <returns></returns>
    int getRandomNumber(int min, int max);
};