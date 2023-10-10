//////////////////////////////////////////////////////  GROUP A  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




// NOTE - I have divided the Output results into 3 test main files because I was facing a glitch when I put all the code in one test main file(some of the lines
// were getting skipped while some where getting repeated randomly), I figured out that this was because of the length of the console output, so I divided the 
// code into three main files each checking a certain functionality, now my code works absolutely fine.



/*
                                                        

//////////////////////////////////////////////////////  Basic Software Design  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> we have an EuropeanOption class that has the Option parameters as the Private members. We have implemented this class in such a way that option type is not
   a class member and user can specify the option type themselves making it easier to calculate calls and puts for the same Option parameter.

-> We have some private functionalities like init(to initialize the parameters), copy, CallPrice, PutPrice, CallDelta, PutDelta. Appropriate functions will be 
   called out of the last four functions based on the option type passed by the user.

-> the init function is used in the constructor for initialization purpose while the copy function is used in the copy constructor and = Operator.

-> We have three constructors(default, copy, and the one that takes parameters), A Destructor, an Assignment Operator.

-> We also have some Option specific functionalties like two functions for Put call parity: one checks whether the Option Prices hold PCP, while the other find
   outs the price of calls given puts using PCP(and viceversa)

-> four Pricer functions, one that takes an underlying as input, one that takes a vector of underlying as input, one that takes all the Option Parameters as input
   while the last that takes matrix of Option parameters input. these functions take an additional argument for the option type and depending on it they call
   the corresponding call price or put price functins.

->  We also have four functions for Delta and Gamma calculations each. the different inputs for these functions are same as in the case of Pricer functions.
    they also take the Option type as an argument and call the corresponding private functionality.

-> For gamma we only made a single function(CallPut_Gamma) for call and put gammas since gamma for call and put are the same.

-> We have also used the divided difference method to calculate the delta and gamma given an underlying price or a vector of underlying prices.


-> Other than this class we use the utility functions defined in the MeshArray.hpp. These functions inlude: A mesh generator function. A function that generates
   a mesh with jump size 0 i.e h = 0, A function for printing the mesh created and a function for printing a matrix.

-> We have also created a header file(NormalFunction.hpp) for the standard normal cumulative and probability distribution functions which are used for Option
   price calculations.

                                                     PART 1
                                                   /////|\\\\\

//////////// ********************* RESULTS FOR a.) and b.) ARE IN TESTMAIN1.CPP FILE ******************* \\\\\\\\\\\\\\\\

////////////////////////////////////////////////////// a.) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> The answers calculated by our option pricers for all the batches matches with that given in the HW file.


/////////////////////////////////////////////////////  b.) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> All the four batches returns 1 for the Put Call parity test which means that the exact solution for the One factor plain Option model satisfy put call
   parity. We also calculate the Complementary Option prices for each Batch(call for a given put and vice versa), The prices match with that of listed in the 
   HW file.

/////////////////// ********** RESULTS FOR c.), d.) and a.) of PART 2 ARE IN TESTMAIN2.CPP FILE ************ \\\\\\\\\\\\\\\\\\\\

///////////////////////////////////////////////////  c.)  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> So we have created a mesh of underlying starting from 60 all the way upto 100 with h(increment) = 10, We found out the 
   vector of Option prices for these underlying prices.

////////////////////////////////////////////////////  d.)  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> We create two matrices(vector of vectors) one which shows the variation of option prices with time while the other shows 
   the variation with respect to sigma(volatility). As can be seen from the results from console output option prices increases
   with increase in the time to expiration and Option prices Option prices also increases with increase in volatility.

                                                    PART 2
                                                //////|\\\\\\\

THROUGHOUT PART 2 WE HAVE USED THE FOLLOWING DATA  T = 0.5, K = 100, sig = 0.36, r = 0.1, and b = 0  

/////////////////////////////////////////////////////  a.)   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> We implement the formuale for Delta and Gamma for Options as functions in our class and find out the call and put Deltas
   and gammas for the given data, as seen from the results on output console the results match exactly with value of call
   and put delta given in HW. We also find the gamma for call and put Options and they turn out to be same.
 
 ////////////// ************* RESULTS OF b.) c.) and d.) of PART 2 ARE IN TESTMAIN3.CPP FILE *************** \\\\\\\\\\\\\

 //////////////////////////////////////////////////////  b.)  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

 -> we again use the mesh utility function to create a mesh starting from 55 to all the way upto 105 with h = 10, we then 
    find vector of Delta and gamma for a call option, for underlying prices in the created mesh. the results are shown in 
    the console output file of TestMain3

///////////////////////////////////////////////////////  c.)   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> We create a matrix(vectors of vectors) of different option parameters where each column is a set of Option parameter.
   we then find vectors for delta and gamma for this matrix of Option parameter for Call Option. Results are shown in the 
   console output of TestMain3

///////////////////////////////////////////////////////  d.)   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-> So here we calculate delta and gamma for Options but by using the divided difference method, we use an additional parameter
   h that controls the accuracy of the Option greeks. we have found out the delta of a call option at h = 0.01 and h = 0.5.
   we have also found out gamma for a put Option at h = 0.01 and 0.5. Results are in the console output of TestMain3. We see that 
   we have 100% accuracy when h <= 0.01 for both delta and gamma(i.e there values match with that of the exact solution). where as 
   even with a higher value of h = 0.5 we have accuracy of upto 4 decimal places after the point. Infact when h taken to be 1 
   which is very large we still get a accuracy of 3 decimal places after point.

-> We also use these delta and gamma calculator based on divided difference to find vector of delta and gamma for a vector of 
   underlying prices, we have used h = 0.01 and the results are exactly same as that of exact deltas and gammas for 
   vector of underlying.
*/