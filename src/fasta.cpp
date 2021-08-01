/*
 * Copyright 2021 Andreas Sagen

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "bio/fasta.hpp"
#include <utility>

namespace fasta {

// --- fill
fasta::fasta(block_t __x) { this->blocks.push_back(__x); }
fasta::fasta(std::vector<block_t> __x) { this->blocks = __x; }
fasta &fasta::operator=(std::vector<block_t> &__rhs) {
    this->blocks = __rhs;
    return *this;
}

// --- iterator
std::vector<block_t>::iterator fasta::begin() noexcept { return this->blocks.begin(); }
std::vector<block_t>::iterator fasta::end() noexcept { return this->blocks.end(); }

// --- capacity
std::size_t fasta::size() const noexcept { return this->blocks.size(); }
bool fasta::empty() const noexcept { return this->blocks.empty(); }
void fasta::shrink_to_fit() { this->blocks.shrink_to_fit(); }

// --- element access
block_t fasta::operator[](size_t __n) { return this->at(__n); }
block_t fasta::at(size_t __n) { return this->blocks[__n]; }
std::vector<block_t> fasta::data() noexcept { return this->blocks; }

// --- modifiers
void fasta::assign(size_t __n, const block_t &__x) { this->blocks.assign(__n, __x); }
void fasta::assign(size_t __n, const fasta &__x) {
    for (const auto &element : __x.blocks) {
        this->blocks.assign(__n, element);
        __n++;
    }
}
void fasta::push_back(const block_t &__x) { this->blocks.push_back(__x); }
void fasta::push_back(const fasta &__x) {
    for (const auto &element : __x.blocks) {
        this->blocks.push_back(element);
    }
}
void fasta::clear() noexcept { this->blocks.clear(); }

// --- FASTA operations
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
bool fasta::operator!=(fasta *__rhs) const { return !(this == __rhs); }

} // namespace fasta
