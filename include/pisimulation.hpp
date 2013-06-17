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

#include <random>

class PiSimulation
{
public:
    PiSimulation(int samples);

    void sample();
    void operator()();
    double get_pi();

private:
    int samples_;
    std::mt19937 mt_;
    std::uniform_real_distribution<> unif_;
    int inside_;
    int total_;
};
