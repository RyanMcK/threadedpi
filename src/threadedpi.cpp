/*
Copyright (C) 2013  Ryan McKinnon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
