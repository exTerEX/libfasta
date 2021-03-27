#include "fasta/fasta.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Fasta {

Fasta::Fasta(std::string FileName) {
    std::fstream FileStream(FileName, std::ios::in);
    std::string Sequence;
    for (std::string line; std::getline(FileStream, line);) {
        if (line[0] == '>') {
            this->AppendSequence(Sequence);

            line.erase(0, 1);
            std::stringstream line_ss(line);

            std::vector<std::string> tokens;

            for (std::string token; std::getline(line_ss, token, ' ');) {
                tokens.emplace_back(token);
            }

            Headers.emplace_back(tokens);

            nSequences++;
        } else {
            Sequence += line;
        }
    }

    this->AppendSequence(Sequence);
}

Data Fasta::operator[](unsigned index) const {
    if (index > this->nSequences) {
        throw std::out_of_range("Index is bigger then amount of objects.");
    }

    Data data;

    data.sequence = this->vSequences[index];
    data.header = this->Headers[index];

    return data;
}

std::string Fasta::GetSequence(unsigned index) const {
    if (index > this->nSequences) {
        throw std::out_of_range("Index is bigger then amount of objects.");
    }

    return this->vSequences[index];
}

std::vector<std::string> Fasta::GetHeader(unsigned index) const {
    if (index > this->nSequences) {
        throw std::out_of_range("Index is bigger then amount of objects.");
    }

    return this->Headers[index];
}

void Fasta::AppendSequence(std::string Sequence) {
    if (Sequence != "") {
        this->vSequences.emplace_back(Sequence);
        Sequence = "";
    }
}

} // namespace Fasta
