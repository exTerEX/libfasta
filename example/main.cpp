/*#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <fstream>
#include <iostream>
#include <sstream>*/

#include "bio/fasta.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    std::ifstream file("example/fasta.fasta", std::ios_base::in);

    std::stringstream ss;
    ss << file.rdbuf();

    Fasta::Fasta test = Fasta::read(ss);

    /*std::ifstream file("hello.gz", std::ios_base::in | std::ios_base::binary);
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(file);

    std::stringstream test;

    boost::iostreams::copy(in, test);

    std::cout << test.str();*/
}
