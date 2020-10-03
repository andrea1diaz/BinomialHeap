#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include <iostream>
#include <list>
#include <vector>
#include <limits>

#include "Node.hpp"

template <class T>
class BinomialHeap {
private:
	int size;
	std::vector<Node<T> *> grados;
	void decrease_key(Node<T> *node, T new_key) {
		node->key = new_key;
		Node<T> *current = node;
		T tmp;
		while(current->parent && current->parent->key > current->key) {
			tmp = current->parent->key;
			current->parent->key = current->key;
			current->key = tmp;
			current = current->parent;
		}
	}

public:
	BinomialHeap() {
		size = 0;
	}

	void insert (T key) {
		Node<T> *new_node = new Node<T> (key);

		size ++;

		compact_tree(new_node);
	}
	
	void  compact_tree (Node<T> *node) {
		if (grados.size() > node->grado && grados[node->grado]) {
			unite (grados[node->grado], node);
		}
		
		else if (grados.size() <= node->grado) {
			grados.push_back(node);
		}

		else {
			grados[node->grado] = node;
		}
	}

	void unite (Node<T> *first_node, Node<T> *second_node) {
		if (first_node->key <= second_node->key) {
			second_node->parent = first_node;
			first_node->children.push_back(second_node);

			grados[first_node->grado ++] = nullptr;
			
			compact_tree(first_node);
		}

		else {
			first_node->parent = second_node;
			second_node->children.push_back(first_node);

			grados[second_node->grado ++] = nullptr;
			
			compact_tree(second_node);
		}
	}

	Node<T>* get_min () {
		// asumimos que size > 0
		Node<T> *min_node = new Node<T>(std::numeric_limits<T>::max());
		for (auto x : grados)
			if(x)
				min_node = min_node->key < x->key ? min_node : x;
		return min_node;
	}

	void delete_min() {
		Node<T>* min_node = get_min();
		size--;
		grados[min_node->grado] = nullptr;
		for(auto x : min_node->children)
			compact_tree(x);
		delete min_node;
	}

	void delete_key(T k) {
		Node<T>* node = grados[1]->children[0];
		decrease_key(node, std::numeric_limits<T>::min());
		delete_min();
	}

	void print_heap () {
		for (auto i : grados) {
			if (i) {
				std::cout << i->key << "\n";
				i->print_children();
			}
		}
	}
};

#endif /* BINOMIALHEAP_H */
