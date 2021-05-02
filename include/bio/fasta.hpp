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

class Block {
  private:
    std::string Header;
    std::string Comment;
    std::string Sequence;

  protected:
    std::string getHeader() const;
    std::string getComment() const;
    std::string getSequence() const;

  public:
    Block() = default;
    Block(std::string, std::string, std::string = NULL);
    ~Block() = default;
};

class Fasta {
  private:
    std::vector<Block> Blocks;

  protected:
    std::vector<Block> getBlocks() const;

  public:
    Fasta() = default;
    Fasta(Block);
    Fasta(std::vector<Block>);
    ~Fasta() = default;

    Block operator[](unsigned) const;
    Block at(unsigned) const;

    Fasta &operator+(const Fasta &);
    Fasta &operator+=(const Fasta &);

    bool operator==(Fasta *) const;
    bool operator!=(Fasta *) const;

    bool empty() const; // x

    void push_back(Block);

    // TODO: Implement begin() / end()
};

Fasta read(std::stringstream &);
std::stringstream write(Fasta);

} // namespace Fasta

#endif // BIO_FASTA_HPP
