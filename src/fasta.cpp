/**
 * \file fasta.cpp
 *
 * \brief Source code for FASTA elements wrapped around the concept of blocks. For a
 * description of the block concept see block.cpp.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#include "bio/fasta.hpp"

namespace fasta {

fasta::fasta(block_t __block) { this->blocks.push_back(__block); }

fasta::fasta(std::vector<block_t> __blocks) { this->blocks = __blocks; }

std::vector<block_t> fasta::getBlocks() const { return this->blocks; }

block_t fasta::operator[](unsigned __n) const { return this->at(__n); }

block_t fasta::at(unsigned __n) const { return this->blocks[__n]; }

fasta &fasta::operator+(const fasta &__rhs) {
    for (auto &element : __rhs.getBlocks()) {
        this->blocks.push_back(element);
    }

    return *this;
}

fasta &fasta::operator+=(const fasta &__rhs) { return *this + __rhs; }

bool fasta::operator==(fasta *__rhs) const {
    if (this->blocks.size() != __rhs->blocks.size()) {
        return false;
    }

    for (size_t index = 0; index < this->blocks.size(); index++) {
        if (this->blocks[index].header != __rhs->blocks[index].header) {
            return false;
        }

        if (this->blocks[index].comment != __rhs->blocks[index].comment) {
            return false;
        }

        if (this->blocks[index].sequence != __rhs->blocks[index].sequence) {
            return false;
        }
    }
    return true;
}

bool fasta::operator!=(fasta *__rhs) const {
    if (this->blocks.size() != __rhs->blocks.size()) {
        return true;
    }

    for (size_t index = 0; index < this->blocks.size(); index++) {
        if (this->blocks[index].header != __rhs->blocks[index].header) {
            return true;
        }

        if (this->blocks[index].comment != __rhs->blocks[index].comment) {
            return true;
        }

        if (this->blocks[index].sequence != __rhs->blocks[index].sequence) {
            return true;
        }
    }
    return false;
}

bool fasta::empty() const { return this->blocks.empty(); }

void fasta::push_back(const block_t &__block) { this->blocks.push_back(__block); }

std::size_t fasta::size() const { return this->blocks.size(); }

std::vector<block_t>::iterator fasta::begin() { return this->blocks.begin(); }

std::vector<block_t>::iterator fasta::end() { return this->blocks.end(); }

} // namespace fasta
