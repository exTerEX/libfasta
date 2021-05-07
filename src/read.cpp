/**
 * \file read.cpp
 *
 * \brief Source code for file/stream read methods for FASTA files and objects.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#include "bio/fasta.hpp"
#include <iostream>
#include <sstream>

namespace Fasta {

Fasta read(std::stringstream &__ss) {
    // Fasta object
    Fasta fastaOutputObject;

    // current block
    block_t current;

    // Switch value to ensure comment treated as comment
    bool sequenceReached = true;

    // Read lines in stringstream
    for (std::string line; std::getline(__ss, line);) {
        // TODO: remove trailing whitespace on line
        if ((line[0] == '>' || line[0] == ';') && sequenceReached) {
            // Flush previous block
            if (!current.header.empty()) {
                fastaOutputObject.push_back(current);
                current.erase();
            }

            // Remove '>' in header line
            line.erase(0, 1);

            // Add current line to current header
            current.header = line;
            sequenceReached = false;
        } else if (line[0] == ';' && !sequenceReached) {
            // Remove '>' in header line
            line.erase(0, 1);
            current.comment = line; // TODO: remove whitespace before comment
        } else if (!line.empty()) {
            current.sequence = line;
            sequenceReached = true;
        } else {
            continue;
        }
    }

    // Flush before exiting
    fastaOutputObject.push_back(current);
    current.erase();

    return fastaOutputObject;
}

} // namespace Fasta
