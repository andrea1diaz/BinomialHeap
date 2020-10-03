#include <iostream>
#include <cstdlib>
#include <time.h>

#include "BinomialHeap.hpp"

int main () {
	BinomialHeap<int> bh;
	srand (time(NULL));
	for(int i = 0; i < 20; ++i) {
		int tmp = (rand() % 100) + 1;
		std::cout << tmp << std::endl;
		bh.insert(tmp);
		bh.print_heap();
		std::cout << "==========" << std::endl;
	}
	// bh.insert(1);
	// bh.insert(2);
	// bh.insert(3);
	// bh.insert(5);

	// bh.print_heap();
	// bh.delete_min();
	// bh.print_heap();
	// bh.delete_key(5);
	// bh.print_heap();
	// std::cout << bh.get_min() << std::endl;
	

	return 0;
}
