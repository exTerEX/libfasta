#ifndef FASTA_HPP
#define FASTA_HPP

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

    bool operator==(Fasta) const; // x
    bool operator!=(Fasta) const; // x

    bool empty() const; // x

    void push_back(Block);

    // TODO: Implement begin() / end()
};

Fasta read(std::stringstream &);
std::stringstream write(Fasta);

} // namespace Fasta

#endif // FASTA_HPP
