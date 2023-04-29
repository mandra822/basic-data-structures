#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    LARGE_INTEGER seedByTicks;
    QueryPerformanceCounter(&seedByTicks);

    RandomGenerator::generator = std::mt19937(seedByTicks.QuadPart);
}


RandomGenerator::~RandomGenerator()
{

}

int RandomGenerator::getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> dist(min, max);
    return dist(RandomGenerator::generator);
}
