#include "pisimulation.hpp"

PiSimulation::PiSimulation(int samples) : samples_(samples),
                                          mt_(std::random_device()()),
                                          unif_(0.0, 1.0),
                                          inside_(0),
                                          total_(0)
{
}

void PiSimulation::sample()
{
    double x = unif_(mt_);
    double y = unif_(mt_);

    if (x*x + y*y <= 1.0)
    {
        ++inside_;
    }

    ++total_;
}

void PiSimulation::operator()()
{
    for (int i = 0; i < samples_; ++i)
    {
        sample();
    }
}


double PiSimulation::get_pi()
{
    return (4.0 * inside_) / total_;
}
