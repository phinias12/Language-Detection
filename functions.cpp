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

///////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS GO HERE
///////////////////////////////////////////////////////////////////

//Opens the file and returns only the letters in a string
std::string readFile(std::ifstream &infile)
{
    std::string text;
    if (!infile.fail())
    {
        char ch;
        while (infile.get(ch))
        {
            if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
            {
                text += ch;
            }
        }
    }

    else
    {
        std::cerr << "readFile";
    }

    return text;
}

//Convert the three letters into base26 trigram.
int base26(std::string trigram)
{
    int sum26 = 0;
    for (size_t i = 0; i < trigram.size(); i++)
    {
        int tri = trigram[i];
        if (tri > 64 && tri < 91)
        {
            tri -= 65;
        }
        else
        {
            tri -= 97;
        }
        sum26 += (tri * pow(26, (trigram.size() - 1 - i)));
    }

    return sum26;
}

//Returns a vector of the trigrams
std::vector<int> freq(std::string text)
{
    std::vector<int> trigrams;
    std::string trigram;
    for (size_t i = 2; i < text.size(); i++)
    {
        trigram = text[i - 2];
        trigram += text[i - 1];
        trigram += text[i];
        trigrams.push_back(base26(trigram));
    }

    return trigrams;
}
