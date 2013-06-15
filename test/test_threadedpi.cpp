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

    BOOST_CHECK((pi < 3.2) && (pi > 3.1));
}

BOOST_AUTO_TEST_SUITE_END()
