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

Fasta::Fasta(block_t block) { this->Blocks.push_back(block); }

Fasta::Fasta(std::vector<block_t> block) { this->Blocks = block; }

std::vector<block_t> Fasta::getBlocks() const { return this->Blocks; }

block_t Fasta::operator[](unsigned __n) const { return this->at(__n); }

block_t Fasta::at(unsigned __n) const { return this->Blocks[__n]; }

Fasta &Fasta::operator+(const Fasta &__rhs) {
    for (auto &element : __rhs.getBlocks()) {
        this->Blocks.push_back(element);
    }

    return *this;
}

Fasta &Fasta::operator+=(const Fasta &__rhs) { return *this + __rhs; }

bool Fasta::operator==(Fasta *__rhs) const {
    if (this->Blocks.size() != __rhs->Blocks.size()) {
        return false;
    }

    for (size_t index = 0; index < this->Blocks.size(); index++) {
        if (this->Blocks[index].header != __rhs->Blocks[index].header) {
            return false;
        }

        if (this->Blocks[index].comment != __rhs->Blocks[index].comment) {
            return false;
        }

        if (this->Blocks[index].sequence != __rhs->Blocks[index].sequence) {
            return false;
        }
    }
    return true;
}

bool Fasta::operator!=(Fasta *__rhs) const {
    if (this->Blocks.size() != __rhs->Blocks.size()) {
        return true;
    }

    for (size_t index = 0; index < this->Blocks.size(); index++) {
        if (this->Blocks[index].header != __rhs->Blocks[index].header) {
            return true;
        }

        if (this->Blocks[index].comment != __rhs->Blocks[index].comment) {
            return true;
        }

        if (this->Blocks[index].sequence != __rhs->Blocks[index].sequence) {
            return true;
        }
    }
    return false;
}

bool Fasta::empty() const { return this->Blocks.empty(); }

void Fasta::push_back(const block_t &block) { this->Blocks.push_back(block); }

std::size_t Fasta::size() const { return this->Blocks.size(); }

std::vector<block_t>::iterator Fasta::begin() { return this->Blocks.begin(); }

std::vector<block_t>::iterator Fasta::end() { return this->Blocks.end(); }

} // namespace Fasta
