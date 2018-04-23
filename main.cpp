/**
 * Started by Najib 3/21/18
 **/

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

#define LEN 17576

int main(int argc, char *argv[]) {
    ///////////////////////////////////////////////////////////////////
    // MAKE YOUR OWN MAIN.
    ///////////////////////////////////////////////////////////////////

    // (void) argc;
    // (void) argv;

    // Gets test
    std::ifstream infile;
    int frequency[LEN];
    infile.open(argv[argc - 1]);
    std::string text = readFile(infile);
    std::vector<int> trigrams = freq(text);

    for (int j = 0; j < LEN; j++){
        frequency[j] = 0;
    }

    for (size_t k = 0; k < trigrams.size(); k++){
        int index = trigrams[k];
        frequency[index] += 1;
    }

    for (int l = 0; l < LEN; l++){
        std::cout << frequency[l] << " ";
    }

    return 0;
}
