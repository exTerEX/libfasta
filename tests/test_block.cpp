#include "bio/fasta.hpp"
#include <assert.h>

void test_empty_init();
void test_full_init();
void test_half_init();
void test_copy_constructor();
void test_erase_function();

int main(int, char **) {
    test_empty_init();
    test_full_init();
    test_half_init();
    test_copy_constructor();
    test_erase_function();
}

void test_empty_init() {
    Fasta::block_t b;

    assert(b.header == "");
    assert(b.comment == "");
    assert(b.sequence == "");
}

void test_full_init() {
    Fasta::block_t b("header", "comment", "sequence");

    assert(b.header == "header");
    assert(b.comment == "comment");
    assert(b.sequence == "sequence");
}

void test_half_init() {
    Fasta::block_t b("header", "sequence");

    assert(b.header == "header");
    assert(b.comment == "");
    assert(b.sequence == "sequence");
}

void test_copy_constructor() {
    Fasta::block_t b("header", "comment", "sequence");
    Fasta::block_t c(b);

    assert(b.header == c.header);
    assert(b.comment == c.comment);
    assert(b.sequence == c.sequence);
}

void test_erase_function() {
    Fasta::block_t b("header", "comment", "sequence");

    b.erase();

    assert(b.header == "");
    assert(b.comment == "");
    assert(b.sequence == "");
}
