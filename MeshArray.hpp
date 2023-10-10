// MeshArray.hpp
//
// A C++ Header file for declaration and definition of the Mesh Creating Functions and other utilities.


// Conditional Compilation(Includes the code block between #ifndef and #endif)
// This is done to make sure that the definitions in the header file are declared
// only once.
#ifndef MESHARRAY_HPP							// checks if the constant MESHARRAY_HPP is defined or not, if not then the code is compiled.
#define MESHARRAY_HPP							// We define a constant MESHARRAY_HPP, this tells us that this code has been compiled.


#include <vector>								// includes the header file that contains the vector class.
#include <iostream>								// includes the header file for input and output streams

using namespace std;							// key word std written here, to avoid writing it everytime you use cin or cout. 

 vector<double> MeshArray(double start, double end, double h)			// Definition of the MeshArray overloaded function.
{
	vector<double> vec;							// Create an empty vector

	// For Loop starts here.
	for (double i = start; i <= end; i = i + h)	// We iterate from start to end with jumps of h. (h is the mesh size)
	{
		vec.push_back(i);						// Push the element into the vector
												// Mesh would be [start, start + h, start+ 2h, . . . , end]
	}

	return vec;									// Return the Mesh Vector.
}

 vector<double> MeshArray(double value, int times)				// Definition of the MeshArray overloaded function. the case when mesh size is 0.
{
	vector<double> vec;							// Create an empty vector

	// For Loop starts here.
	for (int i = 0; i < times; i++)				// This loop iterates for 'times' no. of times				
	{
		vec.push_back(value);					// In each iteration it pushes the value in the mesh.
												// Mesh would be [value, value, ... , 'times' times]
	}

	return vec;									// Return the Mesh Vector.
}

 void PrintArray(vector<double>& a)		// Definition of the PrintArray Function.
{
	// For Loop starts here.
	for (int i = 0; i < a.size(); i++)			// Iterates over the whole vector.
	{
		cout << a[i] << " ";					// In each Iteration prints the current element.
	}
	cout << endl;								// Line change.
}

 void PrintMatrix(vector<vector<double>> mat)		// Definition of the PrintMatrix Function.
{
	// For Loop starts here.
	for (int i = 0; i < mat.size(); i++)		// Iterates over all the rows.
	{
		PrintArray(mat[i]);						// Prints out each row using the PrintArray().
	}
	// For loop ends.
}

#endif // Conditional Compilation ends here.






