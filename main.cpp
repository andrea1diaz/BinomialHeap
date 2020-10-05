#include <iostream>
#include <cstdlib>
#include <time.h>

#include "BinomialHeap.hpp"

int main () {
    BinomialHeap<int> bh;
    srand (time(NULL));
    for(int i = 0; i < 20; ++i) {
    	int tmp = (rand() % 1000) + 1;
    	bh.insert(tmp);
    }

    bh.print_heap();

    return 0;
}
