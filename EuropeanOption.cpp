// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003-2011
//

#define _USE_MATH_DEFINES				// For using the pre-defined constants.
#include <cmath>						// Includes the header file that has the mathematical functionalities defined in it.
#include "EuropeanOption.hpp"			// Includes the header file that contains the declaration of the EuropeanOption Class.
#include <iostream>						// Includes the header file for input and output streams.
#include "NormalFuncton.hpp"			// Includes the header file that has the pdf and cdf of Normal distribution.
#include <vector>						// Includes the header file which contains the vector class.

using namespace std;						// key word std written here, to avoid writing it everytime you use cin or cout. 


// Kernel Functions (Haug)
double EuropeanOption::CallPrice(double U) const		// Function definiton for the CallPrice function.
{

	double tmp = sig * sqrt(T);							// Defining a variable to store a constant which is used in pricing formulae.

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;	// Defining d1.

	double d2 = d1 - tmp;								// Defining d2.

	return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));		// Returning the call price.

}

double EuropeanOption::PutPrice(double U) const			// Function definiton for the PutPrice function.
{

	double tmp = sig * sqrt(T);							// Defining a variable to store a constant which is used in pricing formulae.

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;		// Defining d1.

	double d2 = d1 - tmp;								// Defining d2.

	return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));		// Returning the put price.

}

double EuropeanOption::CallDelta(double U) const		// Function definiton for the CallDelta function.
{
	double tmp = sig * sqrt(T);							// Defining a variable to store a constant which is used in delta formulae.

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;	// Defining d1.


	return exp((b-r)*T) * N(d1);						// Returning the call delta.
}

double EuropeanOption::PutDelta(double U) const			// Function definiton for the PutDelta function.
{
	double tmp = sig * sqrt(T);							// Defining a variable to store a constant which is used in delta formulae.

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;	// Defining d1.

	return exp((b-r)*T) * (N(d1) - 1.0);				// Returning the Put delta.
}


double EuropeanOption::CallPut_Gamma(double U) const	// Function definiton for the CallPut_Gamma function.
{
	double tmp = sig * sqrt(T);							// Defining a variable to store a constant which is used in gamma formulae.

	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;	// Defining d1.

	return (n(d1) * exp((b - r) * T)) / (U * tmp);		// Returning the Gamma for call and put options.
}



/////////////////////////////////////////////////////////////////////////////////////

void EuropeanOption::init()					// Function definiton for the init function.
{											// to Initialise all default values

	// Default values for Option parameters.
	// Initializing every variable.
	r = 0.05;
	sig= 0.2;

	K = 110.0;
	T = 0.5;

	b = r;									// Black and Scholes stock option model (1973)
}

void EuropeanOption::copy( const EuropeanOption& o2)		// Function definiton for the Copy function.
{
															// For copying the Option parameters.
	// Copying all the variables one by one.
	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
}

EuropeanOption::EuropeanOption()				// Function definiton for the Default Constructor.
{ 
	init();										// initialize all the parameters to default values.
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)	// Function definiton for the Copy Constructor.
{ // Copy constructor

	copy(o2);												// Copies parameters of passed object to current object.
}


// Function definiton of the constructor that takes Option parameters.
EuropeanOption::EuropeanOption(double n_T, double n_K, double n_sig, double n_r, double n_b): T(n_T), K(n_K), sig(n_sig), r(n_r), b(n_b)
{
	// Using semicolon syntax to initialize all the parameters by the passed parameters.
}


// Function definiton of destructor.
EuropeanOption::~EuropeanOption()
{
	// Object Destroyed.
}

// Function definiton of Assignment Operator.
EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{
	if (this == &option2) return *this;			// Self assignment check.

	copy (option2);								// Copy the parameters from Option2 to current object.

	return *this;								// Return the current object.
}


// Functions that calculate option price and sensitivities
////////////////////////////////////////////////////////////

// Function definiton of the Price function
double EuropeanOption::Price(double U, string optType) const
{
	// If - else condition to check if we want to calculate price for a Call option or a Put option.
	if (optType == "C")
	{	
		return CallPrice(U);		// If call then return CallPrice at underlying.
	}
	else if(optType == "P")
	{
		return PutPrice(U);			// If put then return PutPrice at underlying.
	}
	else
	{
		cout << "Enter valid Option type\n";	// Output text about invalid option type.

		return -1;					// Returns -1.
	}
}	

// Function definiton of the Delta function
double EuropeanOption::Delta(double U, string optType) const 
{
	// If - else condition to check if we want to calculate delta for a Call option or a Put option.
	if (optType == "C")
	{
		return CallDelta(U);	// If call then return CallDelta at underlying.
	}	
	else if (optType == "P")
	{
		return PutDelta(U);		// If put then return PutDelta at underlying.
	}
	else
	{
		cout << "Enter valid Option type\n";		// Output text about invalid option type.

		return -1;				// Returns -1.
	}
}


// Function definiton of the check_put_call_parity function.
bool EuropeanOption::check_put_call_parity(double U) const
{
	return ( CallPrice(U) + (K * exp(-1 * r * T)) ) - ( PutPrice(U) + U ) < 1e-8;    // Checks how close are the LHS and RHS term of PHP equation to eachother
																					 // at exact solutions.
																					 // If less than 10^-8 returns 1 else 0.
}

// Function definiton of the comp_opt_price function.
// Returns the complementary option price using the Put Call Parity.
double EuropeanOption::comp_opt_price(double U, string optType) const
{
	// If-else condition on the type of Option.
	if (optType == "C")					// The given Option is a Call Option, so We gotta find the corresponding Put price.
	{
		return CallPrice(U) + (K * exp(-1 * r * T)) - U;		// Returns the Put price.
	}
	else if (optType == "P")			// The given Option is a Put Option, so We gotta find the corresponding Call price.		
	{
		return PutPrice(U) + U - (K * exp(-1 * r * T));		// Returns the Call price.
	}
	else
	{
		return -1;						// Else return -1.
	}
}

// Function definiton of the overloaded Price function.
vector<double> EuropeanOption::Price(const vector<double>& U_prices, string optType) const
{
	vector<double> prices;							// Create a vector to store the Option prices.

	// For Loop starts here.
	for (int i = 0; i < U_prices.size(); i++)		// Iterating over the vector of underlying that is given as input.
	{
		prices.push_back(Price(U_prices[i], optType));		// at each underlying we find the Price of the option and push it into the prices vector.
	}
	
	return prices;									// Return the vector of Option prices.
}

// Function definiton of the overloaded Delta function.
vector<double> EuropeanOption::Delta(const vector<double>& U_prices, string optType) const
{
	vector<double> deltas;							// Create a vector to store the deltas.

	// For Loop starts here.
	for (int i = 0; i < U_prices.size(); i++)		// Iterating over the vector of underlying that is given as input.
	{
		deltas.push_back(Delta(U_prices[i], optType));		// at each underlying we find the Delta of the option and push it into the deltas vector.
	}

	return deltas;									// Return the vector of Option deltas.
}

// Function definition of the overloaded CallPut_Gamma function.
vector<double> EuropeanOption::CallPut_Gamma(const vector<double>& U_prices, string optType) const
{
	vector<double> gammas;							// Create a vector of gammas 

	// For loop starts here.
	for (int i = 0; i < U_prices.size(); i++)		// Iterating over the vector of underlying prices that is given as input.
	{
		gammas.push_back(CallPut_Gamma(U_prices[i]));		// at each iteration we find gamma of the Option and push it into the gammas vector.
	}

	return gammas;									// Return the vector of Option gammas.
}

// Function definiton of the Price function that takes input as Option parameters.
double EuropeanOption::Price(double g_T, double g_K, double g_sig, double g_r, double g_b, double S, string optType)
{
	// Changing the value of Option parameters of the current object to the passed parameters.
	T = g_T; K = g_K; sig = g_sig; r = g_r; b = g_b;

	// If - else condition to check if we want to calculate price for a Call option or a Put option.
	if (optType == "C")
	{
		return CallPrice(S);		// If call then return CallPrice at underlying.
	}
	else if (optType == "P")
	{
		return PutPrice(S);			// If put then return PutPrice at underlying.
	}
	else
	{
		return -1;					// Else return -1.
	}

}

// Function definiton of the Delta function that takes input as Option parameters.
double EuropeanOption::Delta(double given_T, double given_K, double given_sig, double given_r, double given_b, double S, string optType)
{
	// Changing the value of Option parameters of the current object to the passed parameters.
	T = given_T; K = given_K; sig = given_sig; r = given_r; b = given_b;

	// If - else condition to check if we want to calculate delta for a Call option or a Put option.
	if (optType == "C")
	{
		return CallDelta(S);	// If call then return CallDelta at underlying.
	}
	else if (optType == "P")
	{
		return PutDelta(S);		// If put then return PutDelta at underlying.
	}
	else
	{
		return -1;				// else return -1.
	}
}


// Function definiton of the CallPut_Gamma function that takes input as Option parameters.
double EuropeanOption::CallPut_Gamma(double given_T, double given_K, double given_sig, double given_r, double given_b, double S, string optType)
{
	// Changing the value of Option parameters of the current object to the passed parameters.
	T = given_T; K = given_K;  sig = given_sig; r = given_r; b = given_b;

	return CallPut_Gamma(S);	// Returns the gamma of the Option at given underlying, gamma for call and put is same so not if-else required.
}


// Function definiton of the Matrix_Pricer function that takes a matrix as input.
vector<double> EuropeanOption::Matrix_Pricer(const vector<vector<double>>& mat, string optType)
{
	vector<double> matrix_prices;				// Create a vector to store the Option prices.			

	// For loop starts here.
	for (int i = 0; i < mat[0].size(); i++)		// we iterate over all the rows at the same time.
	{
		// Each column is a set of option parameters
		// so for each column we find out the price of Option for those parameters for the given option type.
		// we then push the price into the price vector.
		matrix_prices.push_back(Price(mat[0][i], mat[1][i], mat[2][i], mat[3][i], mat[4][i], mat[5][i], optType)); // Here vector of b's is same as vector of r's since  Stock Option Model
	}

	return matrix_prices;						// return the vector of prices.					
}


// Function definiton of the Matrix_Delta function that takes a matrix as input.
vector<double> EuropeanOption::Matrix_Delta(const vector<vector<double>>& mat, string optType)
{
	vector<double> matrix_deltas;				// Create a vector to store the Option deltas.

	// For loop starts here.
	for (int i = 0; i < mat[0].size(); i++)		// we iterate over all the rows at the same time.
	{
		// Each column is a set of option parameters
		// so for each column we find out the delta of Option for those parameters for the given option type.
		// we then push the delta into the price vector.
		matrix_deltas.push_back(Delta(mat[0][i], mat[1][i], mat[2][i], mat[3][i], mat[4][i], mat[5][i], optType));
	}

	return matrix_deltas;						// return the vector of deltas.	
}

// Function definiton of the Matrix_Gamma function that takes a matrix as input.
vector<double> EuropeanOption::Matrix_Gamma(const vector<vector<double>>& mat, string optType)
{
	vector<double> matrix_gammas;				// Create a vector to store the Option gammas

	// For Loop starts here
	for (int i = 0; i < mat[0].size(); i++)		// we iterate over all the rows at the same time.
	{
		// Each column is a set of option parameters
		// so for each column we find out the gamma of Option for those parameters for the given option type.
		// we then push the gamma into the price vector.
		matrix_gammas.push_back(CallPut_Gamma(mat[0][i], mat[1][i], mat[2][i], mat[3][i], mat[4][i], mat[5][i], optType));
	}

	return matrix_gammas;						// return the vector of gammas.
}


// Function definiton of the Div_diff_Delta function.
double EuropeanOption::Div_diff_Delta(double U, string optType, double h) const
{
	return (Price(U + h, optType) - Price(U - h, optType)) / (2 * h);		// Returns the delta that is calculated using divided difference for given underlying 
																			// and Option type.
}

// Function definiton of the Div_diff_Gamma function.
double EuropeanOption::Div_diff_Gamma(double U, string optType, double h) const
{
	// Returns the Gamma that is calculated using divided difference for given underlying 
	// and Option type.
	return (Price(U + h, optType) - (2 * Price(U, optType)) + Price(U - h, optType)) / (h * h);
}

// Function definiton of the Div_diff_Delta function for a vector of input
vector<double> EuropeanOption::Div_diff_Delta(const vector<double>& U_prices, string optType, double h) const
{
	vector<double> deltas;						// Create a vector for storing deltas.

	// For Loop starts here.
	for (int i = 0; i < U_prices.size(); i++)	// We iterate over the vector of underlying prices.
	{
		deltas.push_back(Div_diff_Delta(U_prices[i], optType, h));		// at each iteration we find delta using divided difference for each underlying for 
																		// specified option type.
	}

	return deltas;								// Returns the vector of deltas.
}

// Function definiton of the Div_diff_Gamma function for a vector input
vector<double> EuropeanOption::Div_diff_Gamma(const vector<double>& U_prices, string optType, double h) const
{
	vector<double> gammas;						// Creates a vector for storing gammas.

	// For loop starts here.
	for (int i = 0; i < U_prices.size(); i++)	// We iterate over the vector of underlying prices.
	{
		gammas.push_back(Div_diff_Gamma(U_prices[i], optType, h));		// at each iteration we find gamma using divided difference for each underlying for 
																		// specified option type.
	}

	return gammas;								// Return the vector of gammas.
}


