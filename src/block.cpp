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

namespace Fasta {

Block::Block(std::string header, std::string sequence, std::string comment) {
    this->Header = header;
    this->Comment = comment;
    this->Sequence = sequence;
}

std::string Block::getHeader() const { return this->Header; }

std::string Block::getComment() const { return this->Comment; }

std::string Block::getSequence() const { return this->Sequence; }

} // namespace Fasta
