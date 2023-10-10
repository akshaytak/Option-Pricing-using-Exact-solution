// EuropeanOption.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only.
//
// (C) Datasim Component Technology BV 2003-2011
//

// Conditional Compilation(Includes the code block between #ifndef and #endif)
// This is done to make sure that the definitions in the header file are declared
// only once.
#ifndef EuropeanOption_hpp					// checks if the constant EUROPEANOPTION_HPP is defined or not, if not then the code is compiled.
#define EuropeanOption_hpp					// We define a constant EUROPEANOPTION_HPP, this tells us that this code has been compiled.


#include <vector>							// includes the header file that contains the vector class.
#include <string>							// includes the header file for input and output streams
using namespace std;						// key word std written here, to avoid writing it everytime you use cin or cout. 

// Class definition starts here...
// Class name - EuropeanOption
// It has private members, which are the different Option Parameters.
// It also has Public member functions which are categorized as constructors, 
// destructors, Price, and greeks Calculator.
class EuropeanOption						
{
	// Private members, cannot be accessed directly, should use public functions to manipulate or access them.
	private:	

		double r;			// Interest rate
		double sig;			// Volatility
		double K;			// Strike price
		double T;			// Expiry date
		double b;			// Cost of carry

		void init();							// Initialise all default values

		void copy(const EuropeanOption& o2);	// To Copy Option Parameters

		// 'Kernel' functions for option calculations
		double CallPrice(double U) const;		// Function to Calculate the call price

		double PutPrice(double U) const;		// Function to Calculate the put price

		double CallDelta(double U) const;		// Function to Calculate the Call Delta.

		double PutDelta(double U) const;		// Function to Calculate the Put Delta.

	// Public member Functions, these are the methods that are used with the objects to get access to the Object members.
	public:

		EuropeanOption();												// Default Constructor Declaration.

		EuropeanOption(const EuropeanOption& option2);					// Copy constructor Declaration.
			
		EuropeanOption(double T, double K, double sig, double r, double b);		// Declaration of constructor that Option Parameters as arguments.

		virtual ~EuropeanOption();										// Destructor Declaration.

		EuropeanOption& operator = (const EuropeanOption& option2);		// Assignment Operator Declaration.


		// Put Call Parity Functionalitites.
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		bool check_put_call_parity(double U) const;						// Declaration of function to Check the Put-Call Parity.

		double comp_opt_price(double U, string optType) const;			// Declaration of the function that finds the complementary price of the given option.


		// Pricer Functions
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		double Price(double U, string optType) const;					// Declaration of function that calculates the Price of an Option.

		vector<double> Price(const vector<double>& U_prices, string optType) const;	// Declaration of the function that finds Option price for a vector of underlying prices.

		// Declaration of the function that finds the Option price for the given Option parameters
		double Price(double g_T, double g_K, double g_sig, double g_r, double g_b, double S, string optType);

		// Declaration of the function that finds the Option prices for a matrix of Option Parameters.
		vector<double> Matrix_Pricer(const vector<vector<double>>& mat, string optType);


		// Delta Calculator
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		double Delta(double U, string optType) const;								// Declaration of the function that calculates the delta of an option

		vector<double> Delta(const vector<double>& U_prices, string optType) const;	// Declaration of the function that finds Delta for a vector of underlying prices.

		// Declaration of the function that finds the Delta for the given Option parameters
		double Delta(double g_T, double g_K, double g_sig, double g_r, double g_b, double S, string optType);

		// Declaration of the function that finds the Delta for a matrix of Option Parameters.
		vector<double> Matrix_Delta(const vector<vector<double>>& mat, string optType);


		// Gamma Calculators
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		double CallPut_Gamma(double U) const;										// Declaration of function that calculates the gamma of an option 

		vector<double> CallPut_Gamma(const vector<double>& U_prices, string optType) const;	// Declaration of the function that finds gamma for a vector of underlying prices.

		// Declaration of the function that finds the gamma for the given Option parameters
		double CallPut_Gamma(double g_T, double g_K, double g_sig, double g_r, double g_b, double S, string optType);

		// Declaration of the function that finds the gamma for a matrix of Option parameters.
		vector<double> Matrix_Gamma(const vector<vector<double>>& mat, string optType);


		// Delta and Gamma Calculator using Divided difference
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Declaration of the function that finds the Delta of an Option using divided difference method.
		double Div_diff_Delta(double U, string optType, double h) const;

		// Declaration of the function that finds the Gamma of an Option using divided difference method.
		double Div_diff_Gamma(double U, string optType, double h) const;

		// Declaration of the function that finds the Delta for a vector of underlying prices using divided difference method.
		vector<double> Div_diff_Delta(const vector<double>& U_prices, string optType, double h) const;

		// Declaration of the function that finds the Gamma for a vector of underlying prices using divided difference method.
		vector<double> Div_diff_Gamma(const vector<double>& U_prices, string optType, double h) const;
};

#endif
// Conditional Compilation ends here.