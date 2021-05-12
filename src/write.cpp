/**
 * \file write.cpp
 *
 * \brief Source code for file/stream write methods for FASTA files and objects.
 *
 * \copyright Copyright (c) 2021 Andreas Sagen
 */

#include "bio/fasta.hpp"
#include <sstream>

#define EOL '\n'

namespace Fasta {

std::stringstream write(Fasta __obj) {
    // std::string file_content;
    std::stringstream file_content;

    for (const auto &block : __obj) {
        // Add header
        std::string header = "> " + block.header + EOL;
        file_content.write(header.c_str(), header.size());

        // Add comment
        if (block.comment != "") {
            std::string comment = "; ";

            for (size_t index = 0; index < block.comment.size(); index++) {
                comment += block.comment[index];

                // Newline if 80 characters long line
                if (!index % 77) {
                    comment += EOL;
                    file_content.write(comment.c_str(), comment.size());
                    comment = "; ";
                }
            }

            comment += EOL;
            file_content.write(comment.c_str(), comment.size());
        }

        // Add sequence
        std::string sequence;

        for (size_t index = 0; index < block.sequence.size(); index++) {
            sequence += block.sequence[index];

            // Newline if 80 characters long line
            if (!index % 79) {
                sequence += EOL;
                file_content.write(sequence.c_str(), sequence.size());
            }

            sequence += EOL;
            file_content.write(sequence.c_str(), sequence.size());
        }

        file_content.put(EOL);
    }

    return file_content;
}

} // namespace Fasta
