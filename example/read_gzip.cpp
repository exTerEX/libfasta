/**
 * \file read_gzip.cpp
 *
 * \brief A simple example of how to use the "Fasta::read" method on zipped files using
 * boost::iostream.
 */

#include "bio/fasta.hpp"
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <iostream>
#include <sstream>

int main(int, char **) {
    std::fstream file("data/normal.fasta.gz", std::ios::in | std::ios::binary);

    // Create a filter to decompress the gzipped file.
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(file);

    std::stringstream ss;

    // Copy data into a stringstream
    boost::iostreams::copy(in, ss);

    // Read stringstream data into a FASTA object.
    Fasta::Fasta data = Fasta::read(ss);

    //
    // ! DO WHAT YOU WANT WITH THE FASTA OBJECT
    //
    for (const auto &block : data) {
        std::cout << "Header: " << block.header << std::endl;
        std::cout << "Comment:" << block.comment << std::endl;
        std::cout << "Sequence: " << block.sequence << std::endl;
    }
}
