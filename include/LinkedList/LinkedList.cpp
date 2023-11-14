#ifndef INCLUDE_LinkedList_LinkedList_H_
#define INCLUDE_LinkedList_LinkedList_H_

#include <iostream>
#include <cstdlib> 
#include <stdexcept> 
#include <random>


namespace Linkedlist {

	template<typename T>
	class Node {
	public:
		T value;
		Node<T>* next;
		Node<T>* prev;
		Node<T>(const T& value) :value(value), next(nullptr), prev(nullptr) {};
	};

	template<typename T>
	class LinkedList {
	private:
		Node<T>* head;
	public:
		LinkedList();
		LinkedList(const LinkedList<T>& other);
		LinkedList(const int size, const int random_capacity);
		LinkedList(const int size, const float random_capacity);
		~LinkedList();
		LinkedList& operator=(const LinkedList<T>& other);
		void push_tail(const T& value);
		void push_tail(const LinkedList<T>& other);
		void push_head(const T& value);
		void push_head(const LinkedList<T>& other);
		void pop_head();
		void pop_tail();
		void delete_node(const T& value);
		T& operator[](const int index);
		const T operator[](int index) const;
		Node<T>* get_head() const;
	};
}
#endif