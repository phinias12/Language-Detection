/**
 * Started by Najib 3/21/18
 **/

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "bigint/bigint.h"


///////////////////////////////////////////////////////////////////
// FUNCTION HEADERS GO HERE
///////////////////////////////////////////////////////////////////

//Opens the file and returns only the letters in a string. Header for readFile.
std::string readFile(std::ifstream &infile);

//Convert the three letters into base26 trigram. Header for base26.
int base26(std::string trigram);

//Returns a vector of the trigrams. Header for freq.
std::vector<int> freq(std::string text);

//Calculates the summation of two vectors multiplied to each other.
bigint summation(std::vector<int> freq1, std::vector<int> freq2);

#endif
