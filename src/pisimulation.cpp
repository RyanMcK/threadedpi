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
