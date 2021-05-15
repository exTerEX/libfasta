/**
 * \file fasta.hpp
 *
 * \brief Public header file to interact with FASTA files.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#ifndef BIO_FASTA_HPP
#define BIO_FASTA_HPP

#include <fstream>
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
    std::vector<block_t> getBlocks() const;

  public:
    fasta() = default;
    fasta(block_t __block);
    fasta(std::vector<block_t> __blocks);
    ~fasta() = default;

    block_t operator[](unsigned __n) const;
    block_t at(unsigned __n) const;

    fasta &operator+(const fasta &__rhs);
    fasta &operator+=(const fasta &__rhs);

    bool operator==(fasta *__rhs) const;
    bool operator!=(fasta *__rhs) const;

    bool empty() const;

    void push_back(const block_t &__block);

    std::size_t size() const;

    std::vector<block_t>::iterator begin();
    std::vector<block_t>::iterator end();
} fasta_t;

fasta_t read(std::stringstream &__ss);
std::stringstream write(fasta_t __obj);

} // namespace fasta

#endif // BIO_FASTA_HPP
