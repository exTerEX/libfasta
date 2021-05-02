/**
 * \file fasta.cpp
 *
 * \brief Source code for FASTA elements wrapped around the concept of blocks. For a
 * description of the block concept see block.cpp.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#include "bio/fasta.hpp"
#include <sstream>

namespace Fasta {

Fasta::Fasta(Block block) {}

Fasta::Fasta(std::vector<Block> blocks) { this->Blocks = blocks; }

std::vector<Block> Fasta::getBlocks() const { return this->Blocks; }

Block Fasta::operator[](unsigned index) const { return this->at(index); }

Block Fasta::at(unsigned index) const { return this->Blocks[index]; }

Fasta &Fasta::operator+(const Fasta &rhs) {
    for (auto &element : rhs.getBlocks()) {
        this->Blocks.push_back(element);
    }

    return *this;
}

Fasta &Fasta::operator+=(const Fasta &rhs) { return *this + rhs; }

bool Fasta::operator==(Fasta *rhs) const {
    if (this->Blocks.size() != rhs->Blocks.size()) {
        return false;
    }

    for (size_t index = 0; index < this->Blocks.size(); index++) {
        if (this->Blocks[index].getHeader() != rhs->Blocks[index].getHeader()) {
            return false;
        }

        if (this->Blocks[index].getComment() != rhs->Blocks[index].getComment()) {
            return false;
        }

        if (this->Blocks[index].getSequence() != rhs->Blocks[index].getSequence()) {
            return false;
        }
    }
    return true;
}

bool Fasta::operator!=(Fasta *rhs) const {
    if (this->Blocks.size() != rhs->Blocks.size()) {
        return true;
    }

    for (size_t index = 0; index < this->Blocks.size(); index++) {
        if (this->Blocks[index].getHeader() != rhs->Blocks[index].getHeader()) {
            return true;
        }

        if (this->Blocks[index].getComment() != rhs->Blocks[index].getComment()) {
            return true;
        }

        if (this->Blocks[index].getSequence() != rhs->Blocks[index].getSequence()) {
            return true;
        }
    }
    return false;
}

bool Fasta::empty() const { return this->Blocks.empty(); }

void Fasta::push_back(Block block) { this->Blocks.push_back(block); }

std::vector<Block>::iterator Fasta::begin() { return this->Blocks.begin(); }

std::vector<Block>::iterator Fasta::end() { return this->Blocks.end(); }

Fasta read(std::stringstream &ss) {
    std::string currentHeader;
    std::string currentComment;
    std::string currentSequence;

    // Output object
    Fasta Output;

    // Switch value to ensure comment treated as comment
    bool sequenceReached = true;

    // Read lines in stringstream
    for (std::string line; std::getline(ss, line);) {
        if ((line[0] == '>' || line[0] == ';') && sequenceReached) {
            // Shrink sequence size
            currentSequence.shrink_to_fit();

            // Flush previous block
            if (currentHeader.empty()) {
                Output.push_back(Block{currentHeader, currentSequence, currentComment});
            }

            // Reset temp values
            currentHeader.clear();
            currentComment.clear();
            currentSequence.clear();

            // Remove '>' in header line
            line.erase(0, 1);

            // Add current line to current header
            currentHeader = line;
            currentHeader.shrink_to_fit();

            // Set sequenceReached flag
            sequenceReached = false;
        } else if (line[0] == ';' && !sequenceReached) {
            // Remove ';' in comment line
            line.erase(0, 1);

            // Add current line to current comment
            currentComment += line;
        } else {
            // Shrink comment size
            currentComment.shrink_to_fit();

            // Add current line to current sequence
            currentSequence += line;

            // Set sequenceReached flag
            sequenceReached = true;
        }
    }

    return Output;
}

std::stringstream write(Fasta Content) { return std::stringstream(NULL); }

} // namespace Fasta
