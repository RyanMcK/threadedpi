// Copyright (C) 2013  Ryan McKinnon
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <cmath>

#include "pisimulation.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestThreadedPi
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSimulationPi)

PiSimulation p1(1);
PiSimulation p2(100000);

BOOST_AUTO_TEST_CASE(ExpectedPiApproximationOneSample)
{
    p1();

    double pi = p1.get_pi();
    double epsilon = 0.01;

    BOOST_CHECK((std::abs(pi) < epsilon) || (std::abs(pi - 4.0) < epsilon));
}

BOOST_AUTO_TEST_CASE(ExpectedPiApproximationManySamples)
{
    p2();

    double pi = p2.get_pi();
    double epsilon = 0.05;

    BOOST_CHECK(std::abs(pi - 3.1415) < epsilon);
}

BOOST_AUTO_TEST_SUITE_END()
