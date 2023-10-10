// TestMain2.cpp
//
// A C++ Source file to test the functionality of the EuropeanOption class.

#include "EuropeanOption.hpp"			 // The header file that includes the EuropeanOption class.
#include <iostream>						 // Header file for input and output stream.
#include <string>						 // Header file that contains the string class.
#include <vector>						 // Header file that contains the vector class.
#include "MeshArray.hpp"				 // Header file that contains the Mesh functionalities.

using namespace std;					 // key word std written here, to avoid writing it everytime you use cin or cout. 

// Main Program Starts here.
int main()
{
	//
	// Part 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 

	///////////////////////////////////////   Q.) C.)     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	cout << "***************** OPTION PRICE FOR A VECTOR OF UNDERLYING ****************" << endl;

	EuropeanOption Opt1(0.25, 65, 0.3, 0.08, 0.08);					// EuropeanOption Object created
	EuropeanOption Opt2(1, 100.0, 0.2, 0.0, 0.0);					// EuropeanOption Object created

	vector<double> Underlying_vec = MeshArray(60, 100, 10);				// Creating a Mesh of underlying prices.

	// Outputting the Mesh of underlying prices on screen.
	cout << "The Underlying Vector input is ";
	PrintArray(Underlying_vec);

	vector<double> opt1_prices = Opt1.Price(Underlying_vec, "C");		// Option prices for vector of underlying.

	// Printing the Option Prices.
	cout << "The Option Price Vector is ";
	PrintArray(opt1_prices);

	//////////////////////////////////////  Q.) d.)  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	cout << "********************* OPTION PRICE FOR A MATRIX OF OPTION PARAMETERS ***************" << endl;

	// Matrix 1: T varying
	// Creating vectors to insert into the matrix.
	vector<double> E_times = MeshArray(0.25, 0.45, 0.05);
	vector<double> S_prices = MeshArray(65, 5);
	vector<double> sigmas = MeshArray(0.3, 5);
	vector<double> I_rates = MeshArray(0.08, 5);
	vector<double> b_vector(I_rates);							// b = r for stock Option model
	vector<double> U_prices = MeshArray(60, 5);

	// To store the Option Parameter.
	vector<vector<double>> matrix;

	// Creating the matrix by pushing the vectors into another vector.
	matrix.push_back(E_times);
	matrix.push_back(S_prices);
	matrix.push_back(sigmas);
	matrix.push_back(I_rates);
	matrix.push_back(b_vector);
	matrix.push_back(U_prices);

	// Printing the Option parameter matrix 
	cout << "Matrix of Option Parameter is " << endl;

	PrintMatrix(matrix);

	// Vector of option prices for the matrix of Option Parameters.
	vector<double> matrix_prices = Opt1.Matrix_Pricer(matrix, "C");

	// Printing the Option prices.
	cout << "Vector of Call Option Prices for the Matrix input is ";

	PrintArray(matrix_prices);

	cout << endl;

	// Matrix 2: sig varying.
	// Creating vectors to insert into the matrix.
	vector<double> E_times2 = MeshArray(1, 5);
	vector<double> S_prices2 = MeshArray(100, 5);
	vector<double> sigmas2 = MeshArray(0.2, 0.4, 0.05);
	vector<double> I_rates2 = MeshArray(0, 5);
	vector<double> b_vector2(I_rates2);							// b = r for stock Option model.
	vector<double> U_prices2 = MeshArray(100, 5);

	// To store the Option Parameter.
	vector<vector<double>> matrix2;

	// Creating the matrix by pushing the vectors into another vector.
	matrix2.push_back(E_times2);
	matrix2.push_back(S_prices2);
	matrix2.push_back(sigmas2);
	matrix2.push_back(I_rates2);
	matrix2.push_back(b_vector2);
	matrix2.push_back(U_prices2);

	// Printing the Option parameter matrix 
	cout << "Matrix of Option Parameter is " << endl;

	PrintMatrix(matrix2);

	// Vector of option prices for the matrix of Option Parameters.
	vector<double> matrix_prices2 = Opt2.Matrix_Pricer(matrix2, "P");

	// Printing the Option prices.
	cout << "Vector of Put Option Prices for the Matrix input is ";

	PrintArray(matrix_prices2);

	// 
	// Part 2	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 

	///////////////////////////////////////////////////    Q.) a.)       \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	cout << "********************************  DELTA AND GAMMA FOR FUTURE OPTION **************************" << endl;

	EuropeanOption Future_Opt1(0.5, 100, 0.36, 0.1, 0);						// EuropeanOption object created with given parameters.

	cout << "Delta of Call for the future Option is " << Future_Opt1.Delta(105, "C") << endl;		// delta for call

	cout << "Delta of Put for the future Option is " << Future_Opt1.Delta(105, "P") << endl;		// delta for put

	cout << "Gamma of Call for the future Option is " << Future_Opt1.CallPut_Gamma(105) << endl;	// gamma for call

	cout << "Gamma of Put for the future Option is " << Future_Opt1.CallPut_Gamma(105) << endl;		// gamma for put.

	cout << endl;				// Line change.

	return 0;							// Main function ends here.
}
// Main Program ends here.