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

namespace fasta {

block::block(std::string header, std::string sequence) {
    this->header = header;
    this->comment = "";
    this->sequence = sequence;
}

block::block(std::string header, std::string comment, std::string sequence) {
    this->header = header;
    this->comment = comment;
    this->sequence = sequence;
}

void block::erase() {
    this->header.erase();
    this->comment.erase();
    this->sequence.erase();
}

} // namespace fasta
