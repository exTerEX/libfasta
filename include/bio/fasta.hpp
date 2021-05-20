/**
 * \file fasta.hpp
 *
 * \brief Public header file to interact with FASTA files.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#ifndef BIO_FASTA_HPP
#define BIO_FASTA_HPP

#include <sstream>
#include <string>
#include <vector>

namespace Fasta {

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

class Fasta {
  private:
    std::vector<block_t> blocks;

  protected:
  public:
    // --- default constructor
    explicit Fasta() = default;

    // --- fill
    Fasta(block_t __x);
    Fasta(std::vector<block_t> __x);
    Fasta &operator=(std::vector<block_t> &__rhs);

    // --- copy
    Fasta(const Fasta &__x) = default;
    Fasta &operator=(const Fasta &__rhs) = default;

    // --- move
    Fasta(Fasta &&__x) = default;
    Fasta &operator=(Fasta &&__rhs) = default;

    // --- destructor
    ~Fasta() = default;

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
    void assign(size_t __n, const Fasta &__x);
    void push_back(const block_t &__x);
    void push_back(const Fasta &__x);
    void clear() noexcept;

    // --- FASTA operations
    bool operator==(Fasta *__rhs) const;
    bool operator!=(Fasta *__rhs) const;
};

Fasta read(std::stringstream &__ss);
std::stringstream write(Fasta __x);

} // namespace Fasta

#endif // BIO_FASTA_HPP
