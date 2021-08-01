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
#include "utilities/trim.hpp"
#include <fstream>

namespace fasta {

fasta_t read(std::stringstream &__ss) {
    // Fasta object
    fasta_t fastaOutputObject;

    // current block
    block_t current;

    // Switch value to ensure comment treated as comment
    bool sequenceReached = true;

    // Read lines in stringstream
    for (std::string line; std::getline(__ss, line);) {
        // Remove trailing whitespace
        line = rtrim(line);

        if ((line[0] == '>' || line[0] == ';') && sequenceReached) {
            // Flush previous block
            if (!current.header.empty()) {
                fastaOutputObject.push_back(current);
                current.erase();
            }

            // Remove '>' in header line
            line.erase(0, 1);

            // Remove leading whitespaces
            line = ltrim(line);

            // Add current line to current header
            current.header = line;
            sequenceReached = false;
        } else if (line[0] == ';' && !sequenceReached) {
            // Remove '>' in header line
            line.erase(0, 1);

            // Remove leading whitespaces
            line = ltrim(line);

            current.comment = line;
        } else if (!line.empty()) {
            current.sequence += line;
            sequenceReached = true;
        } else {
            continue;
        }
    }

    // Flush before exiting
    fastaOutputObject.push_back(current);
    current.erase();

    // Shrink output object
    fastaOutputObject.shrink_to_fit();

    return fastaOutputObject;
}

fasta_t read(const std::string __file) {
    std::fstream file(__file, std::ios::in);
    std::stringstream ss;

    // Move data to stringstream
    ss << file.rdbuf();

    // Read stringstream data into object
    file.close();

    return read(ss);
}

} // namespace fasta
