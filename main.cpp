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

    // Gets test
    std::ifstream infile;
    std::vector<int> frequency;
    char* max_lang;
    float max_sin = 0.0;
    infile.open(argv[argc - 1]);
    std::string text = readFile(infile);
    std::vector<int> trigrams = freq(text);

    for (int j = 0; j < LEN; j++){
        frequency.push_back(0);
    }

    for (size_t k = 0; k < trigrams.size(); k++){
        int index = trigrams[k];
        frequency[index] += 1;
    }

    for (int l = 1; l < argc - 1; l++){
        std::vector<int> tmp;
        infile.open(argv[l]);
        std::string text = readFile(infile);
        std::vector<int> tmp_trigrams = freq(text);
        for (int m = 0; m < LEN; m++){
            tmp.push_back(0);
        }
        for (size_t k = 0; k < tmp_trigrams.size(); k++){
            int index = tmp_trigrams[k];
            tmp[index] += 1;
        }
        float sin_compare = compare(frequency, tmp);
        if (max_sin < sin_compare){
            max_lang = argv[l];
            max_sin = sin_compare;
        }
    }

    std::cout << max_lang << std::endl;

    return 0;
}
