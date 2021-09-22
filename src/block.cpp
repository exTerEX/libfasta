#include "bio/fasta.hpp"

namespace fasta {

block::block(std::string header, std::string sequence) {
    this->header = header;
    this->comment = "";
    this->sequence = sequence;
}

block::block(std::string header, std::string comment, std::string sequence) {
    this->header = header;
    this->comment = comment;
    this->sequence = sequence;
}

void block::erase() {
    this->header.erase();
    this->comment.erase();
    this->sequence.erase();
}

} // namespace fasta
