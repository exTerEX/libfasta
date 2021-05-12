#include "bio/fasta.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    std::ifstream file("example/fasta.fasta", std::ios_base::in);

    std::stringstream ss;
    ss << file.rdbuf();

    Fasta::Fasta test = Fasta::read(ss);

    for (auto &element : test) {
        std::cout << element.sequence << std::endl;
    }
}
