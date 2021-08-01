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

#ifndef BIO_FASTA_HPP
#define BIO_FASTA_HPP

#include <sstream>
#include <string>
#include <vector>

namespace fasta {

typedef struct block {
    std::string header;
    std::string comment;
    std::string sequence;

    block() = default;
    block(std::string header, std::string sequence);
    block(std::string header, std::string comment, std::string sequence);
    ~block() = default;

    void erase();
} block_t;

typedef class fasta {
  private:
    std::vector<block_t> blocks;

  protected:
  public:
    // --- default constructor
    fasta() = default;

    // --- fill
    fasta(block_t __x);
    fasta(std::vector<block_t> __x);
    fasta &operator=(std::vector<block_t> &__rhs);

    // --- copy
    fasta(const fasta &__x) = default;
    fasta &operator=(const fasta &__rhs) = default;

    // --- move
    fasta(fasta &&__x) = default;
    fasta &operator=(fasta &&__rhs) = default;

    // --- destructor
    ~fasta() = default;

    // --- iterator
    std::vector<block_t>::iterator begin() noexcept;
    std::vector<block_t>::iterator end() noexcept;

    // --- capacity
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    void shrink_to_fit();

    // --- element access
    block_t operator[](size_t __n);
    block_t at(size_t __n);
    std::vector<block_t> data() noexcept;

    // --- modifiers
    void assign(size_t __n, const block_t &__x);
    void assign(size_t __n, const fasta &__x);
    void push_back(const block_t &__x);
    void push_back(const fasta &__x);
    void clear() noexcept;

    // --- FASTA operations
    bool operator==(fasta *__rhs) const;
    bool operator!=(fasta *__rhs) const;
} fasta_t;

fasta_t read(std::stringstream &__ss);

fasta_t read(const std::string __file);

std::stringstream write(fasta_t __obj);

} // namespace fasta

#endif // BIO_FASTA_HPP
