/**
 * \file fasta.cpp
 *
 * \brief Source code for FASTA elements wrapped around the concept of blocks. For a
 * description of the block concept see block.cpp.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#include "bio/fasta.hpp"
#include <utility>

namespace Fasta {

// --- fill
Fasta::Fasta(block_t __x) { this->blocks.push_back(__x); }
Fasta::Fasta(std::vector<block_t> __x) { this->blocks = __x; }
Fasta &Fasta::operator=(std::vector<block_t> &__rhs) {
    this->blocks = __rhs;
    return *this;
}

// --- iterator
std::vector<block_t>::iterator Fasta::begin() noexcept { return this->blocks.begin(); }
std::vector<block_t>::iterator Fasta::end() noexcept { return this->blocks.end(); }

// --- capacity
std::size_t Fasta::size() const noexcept { return this->blocks.size(); }
bool Fasta::empty() const noexcept { return this->blocks.empty(); }
void Fasta::shrink_to_fit() { this->blocks.shrink_to_fit(); }

// --- element access
block_t Fasta::operator[](size_t __n) { return this->at(__n); }
block_t Fasta::at(size_t __n) { return this->blocks[__n]; }
std::vector<block_t> Fasta::data() noexcept { return this->blocks; }

// --- modifiers
void Fasta::assign(size_t __n, const block_t &__x) { this->blocks.assign(__n, __x); }
void Fasta::assign(size_t __n, const Fasta &__x) {
    for (const auto &element : __x.blocks) {
        this->blocks.assign(__n, element);
        __n++;
    }
}
void Fasta::push_back(const block_t &__x) { this->blocks.push_back(__x); }
void Fasta::push_back(const Fasta &__x) {
    for (const auto &element : __x.blocks) {
        this->blocks.push_back(element);
    }
}
void Fasta::clear() noexcept { this->blocks.clear(); }

// --- FASTA operations
bool Fasta::operator==(Fasta *__rhs) const {
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
bool Fasta::operator!=(Fasta *__rhs) const { return !(this == __rhs); }

} // namespace Fasta
