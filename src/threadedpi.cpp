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
#include <thread>
#include <vector>

#include <boost/program_options.hpp>

#include "pisimulation.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    int num_samples;
    int num_threads;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "print help message")
        ("num_samples,s", po::value<int>(&num_samples)->required(),
            "number of samples per thread")
        ("num_threads,t", po::value<int>(&num_threads)->required(),
            "number of threads");

    po::variables_map vm;

    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("help"))
        {
            std::cout << "Threaded Pi" << std::endl << std::endl;
            std::cout << desc << std::endl;

            return 0;
        }

        po::notify(vm);
    }
    catch (po::error& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
        return 1;
    }

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
