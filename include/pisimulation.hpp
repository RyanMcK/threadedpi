#include <random>

class PiSimulation
{
public:
    PiSimulation(int samples);

    void operator()();
    double get_pi();

private:
    int samples_;
    std::mt19937 mt_;
    std::uniform_real_distribution<> unif_;
    int inside_;
    int total_;
};
