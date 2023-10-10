// TestMain1.cpp
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

	////////////////////////////////////////////////  Q.) a.) & b.)  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	cout << "*********************** PRICE FOR PUT AND CALL OPTIONS & PUT CALL PARITY CHECK *********************" << endl;

	cout << "************ BATCH 1 *****************" << endl;

	EuropeanOption Opt1(0.25, 65, 0.3, 0.08, 0.08);					// EuropeanOption Object created for Batch 1

	cout << "Price of Call Option is " << Opt1.Price(60.0, "C") << endl;		// Call price for Batch 1
	cout << "Price of Put Option is " << Opt1.Price(60.0, "P") << endl;			// Put Price for Batch 1

	cout << "Put Call Parity check gives : " << Opt1.check_put_call_parity(60.0) << endl;		// Check for PCP

	cout << "Put Price using PCP of the Call Option is " << Opt1.comp_opt_price(60.0, "C") << endl;	// Using PCP to compute Option Price
	cout << "Call Price using PCP of the Put Option is " << Opt1.comp_opt_price(60.0, "P") << endl;	// Using PCP to compute Option Price


	cout << "************ BATCH 2 *****************" << endl;

	EuropeanOption Opt2(1, 100.0, 0.2, 0.0, 0.0);					// EuropeanOption Object created for Batch 2

	cout << "Price of Call Option is " << Opt2.Price(100.0, "C") << endl;		// Call price for Batch 2
	cout << "Price of Put Option is " << Opt2.Price(100.0, "P") << endl;		// Put Price for Batch 2

	cout << "Put Call Parity check gives : " << Opt2.check_put_call_parity(100.0) << endl;		// Check for PCP

	cout << "Put Price using PCP of the Call Option is " << Opt2.comp_opt_price(100.0, "C") << endl;	// Using PCP to compute Option Price
	cout << "Call Price using PCP of the Put Option is " << Opt2.comp_opt_price(100.0, "P") << endl;	// Using PCP to compute Option Price


	cout << "************ BATCH 3 *****************" << endl;

	EuropeanOption Opt3(1, 10.0, 0.5, 0.12, 0.12);					// EuropeanOption Object created for Batch 3

	cout << "Price of Call Option is " << Opt3.Price(5, "C") << endl;		// Call price for Batch 3
	cout << "Price of Put Option is " << Opt3.Price(5, "P") << endl;		// Put Price for Batch 3

	cout << "Put Call Parity check gives : " << Opt3.check_put_call_parity(5.0) << endl;		// Check for PCP

	cout << "Put Price using PCP of the Call Option is " << Opt3.comp_opt_price(5.0, "C") << endl;	// Using PCP to compute Option Price
	cout << "Call Price using PCP of the Put Option is " << Opt3.comp_opt_price(5.0, "P") << endl;	// Using PCP to compute Option Price


	cout << "************ BATCH 4 *************" << endl;

	EuropeanOption Opt4(30, 100.0, 0.3, 0.08, 0.08);					// EuropeanOption Object created for Batch 4

	cout << "Price of Call Option is " << Opt4.Price(100.0, "C") << endl;		// Call price for Batch 4
	cout << "Price of Put Option is " << Opt4.Price(100.0, "P") << endl;		// Put Price for Batch 4

	cout << "Put Call Parity check gives  : " << Opt4.check_put_call_parity(100.0) << endl;		// Check for PCP

	cout << "Put Price using PCP of the Call Option is " << Opt4.comp_opt_price(100.0, "C") << endl;	// Using PCP to compute Option Price
	cout << "Call Price using PCP of the Put Option is " << Opt4.comp_opt_price(100.0, "P") << endl;	// Using PCP to compute Option Price
	
	return 0;							// Main function ends here.
}
// Main Program ends here.