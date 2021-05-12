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
    std::fstream file("data/normal.fasta", std::ios::in);

    // Move data to stringstream
    std::stringstream ss;
    ss << file.rdbuf();

    // Close file
    file.close();

    // Read stringstream data into a FASTA object.
    Fasta::Fasta data = Fasta::read(ss);

    //
    // ! DO WHAT YOU WANT WITH THE FASTA OBJECT
    //
    for (const auto &block : data) {
        std::cout << "Header: " << block.header << std::endl;
        std::cout << "Comment:" << block.comment << std::endl;
        std::cout << "Sequence: " << block.sequence << std::endl;
    }
}
