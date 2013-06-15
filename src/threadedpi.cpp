#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

//#include <boost/program_options.hpp>

#include "pisimulation.hpp"

int main(int argc, char* argv[])
{
    int num_samples;
    int num_threads;

    std::istringstream ss1(argv[1]);
    ss1 >> num_samples;
    std::istringstream ss2(argv[2]);
    ss2 >> num_threads;

    std::vector<PiSimulation> simulations(num_threads,
                                          PiSimulation(num_samples));
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back(std::ref(simulations[i]));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    double sum_pi = 0.0;

    for (auto& s : simulations)
    {
        sum_pi += s.get_pi();
    }

    std::cout << sum_pi / num_threads << std::endl;

    return 0;
}
