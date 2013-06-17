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

#ifndef PISIMULATION_HPP
#define PISIMULATION_HPP

#include <random>

/**
@mainpage

Please use the menu above to view available classes and files.
*/

/**
Self-contained class for approximating pi in a finite number of Monte Carlo
samples.
*/
class PiSimulation
{
public:
    /**
    @param samples Number of Monte Carlo samples to perform.
    */
    PiSimulation(int samples);

    /**
    Actually perform the Monte Carlo routine using the number of samples
    provided during construction.
    @see sample()
    */
    void operator()();

    /**
    @return The approximation of pi obtained via sampling.
    */
    double get_pi();

private:
    /**
    Pick a random point in the unit square and determine whether it lies in
    the unit circle.  Store the results.
    */
    void sample();

    int samples_;
    std::mt19937 mt_;
    std::uniform_real_distribution<> unif_;
    int inside_;
    int total_;
};

#endif

