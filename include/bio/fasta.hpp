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
    std::vector<block_t> Blocks;

  protected:
    std::vector<block_t> getBlocks() const;

  public:
    Fasta() = default;
    Fasta(block_t __x);
    Fasta(std::vector<block_t> __x);
    ~Fasta() = default;

    block_t operator[](unsigned index) const;
    block_t at(unsigned index) const;

    Fasta &operator+(const Fasta &rhs);
    Fasta &operator+=(const Fasta &rhs);

    bool operator==(Fasta *rhs) const;
    bool operator!=(Fasta *rhs) const;

    bool empty() const;

    void push_back(const block_t &__x);

    std::size_t size() const;

    std::vector<block_t>::iterator begin();
    std::vector<block_t>::iterator end();
};

Fasta read(std::stringstream &);
std::stringstream write(Fasta);

} // namespace Fasta

#endif // BIO_FASTA_HPP
