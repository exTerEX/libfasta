#ifndef __FASTA_HPP__
#define __FASTA_HPP__

#include <string>
#include <vector>

struct Data {
    std::string sequence;
    std::vector<std::string> header;
};

namespace Fasta {

class Fasta {
  private:
    std::vector<std::vector<std::string>> Headers;
    std::vector<std::string> vSequences;
    unsigned nSequences = 0;
    void AppendSequence(std::string);

  protected:
  public:
    Fasta(std::string);
    ~Fasta() = default;

    Data operator[](unsigned) const;

    std::string GetSequence(unsigned) const;
    std::vector<std::string> GetHeader(unsigned) const;
};

} // namespace Fasta

#endif
