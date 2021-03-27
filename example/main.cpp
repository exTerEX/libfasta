#include "fasta/fasta.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Fasta::Fasta T("data/test.fasta");

    for (auto &elem : T[0].header) {
        std::cout << elem << std::endl;
    }

    return EXIT_SUCCESS;
}
