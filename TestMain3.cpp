// TestMain3.cpp
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
	// Part 2	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//

	//////////////////////////////////////////////////   Q.) b.)      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	EuropeanOption Future_Opt1(0.5, 100, 0.36, 0.1, 0);						// EuropeanOption object created with given parameters.

	cout << "****************************** DELTA AND GAMMA FOR A VECTOR OF UNDERLYING *******************" << endl;

	vector<double> Underlying_vec2 = MeshArray(55, 105, 10);			// Creating a mesh for underlying prices.

	// Printing the mesh on screen.
	cout << "The Vector of underlying is ";
	PrintArray(Underlying_vec2);

	// Deltas for the mesh of underlying
	vector<double> Deltas = Future_Opt1.Delta(Underlying_vec2, "C");

	// Printing the vector of deltas on screen.
	cout << "The vector of Call Delta is ";
	PrintArray(Deltas);

	// Gammas for the mesh of underlying
	vector<double> Gammas = Future_Opt1.CallPut_Gamma(Underlying_vec2, "C");

	// Printing the vector of gammas on screen.
	cout << "The vector of Gammas is ";
	PrintArray(Gammas);

	cout << endl;				// Line change.

	/////////////////////////////////////////////////////  Q.) c.)   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	cout << "***************************  DELTA AND GAMMA FOR A MATRIX OF OPTION PARAMETERS ************************" << endl;

	

	// Creating vectors of different Option parameters.
	vector<double> vec_exp_time = MeshArray(0.5, 1.5, 0.5);
	vector<double> vec_strike_price = MeshArray(100, 200, 50);
	vector<double> vec_sig = MeshArray(0.36, 1.08, 0.36);
	vector<double> vec_r = MeshArray(0.1, 3);
	vector<double> vec_b = MeshArray(0, 3);
	vector<double> vec_under_price = MeshArray(105, 115, 5);

	// For storing these Option parameter vector.
	vector<vector<double>> matrix3;

	// Pushing the vectors into the matrix
	matrix3.push_back(vec_exp_time);
	matrix3.push_back(vec_strike_price);
	matrix3.push_back(vec_sig);
	matrix3.push_back(vec_r);
	matrix3.push_back(vec_b);
	matrix3.push_back(vec_under_price);

	// Printing the matrix on screen.
	cout << "The Matrix of Option Parameters is " << endl;
	PrintMatrix(matrix3);

	// Delta for the matrix of Option parameters.
	vector<double> matrix_delta = Future_Opt1.Matrix_Delta(matrix3, "C");

	// Printing the vector of deltas on screen.
	cout << "The Vector of Call Deltas is ";
	PrintArray(matrix_delta);

	// Gamma for the matrix of Option Parameters.
	vector<double> matrix_gamma = Future_Opt1.Matrix_Gamma(matrix3, "C");

	// Printing the vector of gamma on screen.
	cout << "The Vector of Gammas is ";
	PrintArray(matrix_gamma);

	cout << endl;					// Line change.

	////////////////////////////////////////////////     Q.) d.)     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	cout << "*************************** DELTA AND GAMMA USING DIVIDED DIFFERENCE ***************************" << endl;

	EuropeanOption Future_Opt2(0.5, 100, 0.36, 0.1, 0);					// EuropeanOption Object created with the Option parameters

	cout << "Delta of Call for the future Option when h is 0.01 is " << Future_Opt2.Div_diff_Delta(105, "C", 0.01) << endl;	// Delta for call using div-diff
	cout << "Delta of Call for the future Option when h is 0.5 is " << Future_Opt2.Div_diff_Delta(105, "C", 0.5) << endl;		// delta for call using div-diff

	cout << "Gamma of Put for the future Option when h is 0.01 is " << Future_Opt2.Div_diff_Gamma(105, "P", 0.01) << endl;	// gamma for put using div-diff
	cout << "Gamma of Put for the future Option when h is 0.5 is " << Future_Opt2.Div_diff_Gamma(105, "P", 0.5) << endl;		// gamma for put using div-diff

	cout << endl;		// Line change

	cout << "************************** DELTA AND GAMMA FOR A VECTOR OF UNDERLYING USING DIVIDED DIFFERENCE **************" << endl;

	vector<double> Underlying_vec3 = MeshArray(55, 105, 10);			// creating a mesh on underlying prices.

	// Printing the mesh of underlying on screen.
	cout << "The underlying vector is ";
	PrintArray(Underlying_vec3);

	// Deltas for the mesh of underlying using div-diff
	vector<double> Deltas2 = Future_Opt2.Div_diff_Delta(Underlying_vec3, "C", 0.01);

	// Printing the vector of deltas.
	cout << "The vector of Deltas is ";
	PrintArray(Deltas2);

	// Gammas for the mesh of underlying using div-diff
	vector<double> Gammas2 = Future_Opt2.Div_diff_Gamma(Underlying_vec3, "C", 0.01);

	// Printing the vector of gammas
	cout << "The vector of gammas is ";
	PrintArray(Gammas2);

	cout << endl;						// Line change

	return 0;							// Main function ends here.
}
// Main Program ends here.