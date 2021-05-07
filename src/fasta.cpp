/**
 * \file fasta.cpp
 *
 * \brief Source code for FASTA elements wrapped around the concept of blocks. For a
 * description of the block concept see block.cpp.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#include "bio/fasta.hpp"

namespace Fasta {

Fasta::Fasta(block_t __x) { this->Blocks.push_back(__x); }

Fasta::Fasta(std::vector<block_t> __x) { this->Blocks = __x; }

std::vector<block_t> Fasta::getBlocks() const { return this->Blocks; }

block_t Fasta::operator[](unsigned index) const { return this->at(index); }

block_t Fasta::at(unsigned index) const { return this->Blocks[index]; }

Fasta &Fasta::operator+(const Fasta &rhs) {
    for (auto &element : rhs.getBlocks()) {
        this->Blocks.push_back(element);
    }

    return *this;
}

Fasta &Fasta::operator+=(const Fasta &rhs) { return *this + rhs; }

bool Fasta::operator==(Fasta *rhs) const {
    if (this->Blocks.size() != rhs->Blocks.size()) {
        return false;
    }

    for (size_t index = 0; index < this->Blocks.size(); index++) {
        if (this->Blocks[index].header != rhs->Blocks[index].header) {
            return false;
        }

        if (this->Blocks[index].comment != rhs->Blocks[index].comment) {
            return false;
        }

        if (this->Blocks[index].sequence != rhs->Blocks[index].sequence) {
            return false;
        }
    }
    return true;
}

bool Fasta::operator!=(Fasta *rhs) const {
    if (this->Blocks.size() != rhs->Blocks.size()) {
        return true;
    }

    for (size_t index = 0; index < this->Blocks.size(); index++) {
        if (this->Blocks[index].header != rhs->Blocks[index].header) {
            return true;
        }

        if (this->Blocks[index].comment != rhs->Blocks[index].comment) {
            return true;
        }

        if (this->Blocks[index].sequence != rhs->Blocks[index].sequence) {
            return true;
        }
    }
    return false;
}

bool Fasta::empty() const { return this->Blocks.empty(); }

void Fasta::push_back(const block_t &__x) { this->Blocks.push_back(__x); }

std::size_t Fasta::size() const { return this->Blocks.size(); }

std::vector<block_t>::iterator Fasta::begin() { return this->Blocks.begin(); }

std::vector<block_t>::iterator Fasta::end() { return this->Blocks.end(); }

} // namespace Fasta
