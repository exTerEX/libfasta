/**
 * \file read.cpp
 *
 * \brief A simple example of how to use the "Fasta::read" method.
 */

#include "bio/fasta.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int, char **) {
    fasta::fasta_t data = fasta::read("data/normal.fasta");

    //
    // ! DO WHAT YOU WANT WITH THE FASTA OBJECT
    //
    for (const auto &block : data) {
        std::cout << "Header: " << block.header << std::endl;
        std::cout << "Comment:" << block.comment << std::endl;
        std::cout << "Sequence: " << block.sequence << std::endl;
    }
}
