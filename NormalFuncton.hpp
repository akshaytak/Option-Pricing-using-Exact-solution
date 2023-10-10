// NormalFunction.cpp
//
// Some exact formulae.
//
// (C) Datasim Education BV 2011
//

// Conditional Compilation(Includes the code block between #ifndef and #endif)
// This is done to make sure that the definitions in the header file are declared
// only once.
#ifndef NORMALFUNCTION_HPP						// checks if the constant NORMALFUNCTION_HPP is defined or not, if not then the code is compiled.
#define NORMAL_FUNCTION_HPP						// We define a constant NORMALFUNCTION_HPP, this tells us that this code has been compiled.


#include <cmath>								// Includes the header file that has the mathematical functionalities defined in it.
#include <iostream>								// Includes the header file for input and output streams.
#include <boost/math/distributions/normal.hpp>	// Includes the header file that has the Normal Class defined in it.
#include <boost/math/distributions.hpp>			// Includes the non-member functions of distributions

using namespace std;							// key word std written here, to avoid writing it everytime you use cin or cout. 
using namespace boost::math;					// Using the functionality in the math namespace present in the boost namespace.


// Function definition for the Normal cumulative distribution function.
double N(double x)
{

	normal_distribution<> myNormal(0.0, 1.0);	// Defining a Standard Normal distribution object.

	return cdf(myNormal, x);					// Returning the cdf of the distribution.

}

// Function definiton for the Normal probability distribution function.
double n(double x)
{

	normal_distribution<> myNormal(0.0, 1.0);	// Defining a Standard Normal distribution object.

	return pdf(myNormal, x);					// Returning the pdf of the distribution.			

}

#endif // Conditional Compilation ends here.



