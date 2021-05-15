/**
 * \file block.cpp
 *
 * \brief Source code for FASTA elements, i.e. a complete selection of related header,
 * comment and sequence. This is contained as one "Block" element within the "Fasta"
 * object.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

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

} // namespace Fasta
