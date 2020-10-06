#include <iostream>
#include <cstdlib>
#include <time.h>

#include "BinomialHeap.hpp"

int main () {
    BinomialHeap<int> bh;
    bh.buildFromInput();
    bh.print_heap();

    return 0;
}
