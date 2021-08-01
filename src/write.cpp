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

#include "bio/fasta.hpp"
#include <fstream>

#define EOL '\n'

namespace fasta {

std::stringstream write(fasta_t __obj) {
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

} // namespace fasta
