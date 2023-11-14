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
		T& operator[](int index);
		const T operator[](int index) const;
		Node<T>* get_head() const {
			return head;
		};
	};

	template<typename T>
	LinkedList<T>::LinkedList() : head(nullptr) {}

	template<typename T>
	LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr) {
		Node<T>* tmp_other = other.head;
		while (tmp_other) {
			this->push_tail(tmp_other->value);
			tmp_other = tmp_other->next;
		}
	}

	template<typename T>
	LinkedList<T>::LinkedList(const int size, const int random_capacity) : head(nullptr) {
		int count = 0;
		while (count != size) {
			this->push_tail((int)(rand()) * random_capacity / RAND_MAX + 1);
			count += 1;
		}
	}

	template<typename T>
	LinkedList<T>::LinkedList(const int size, const float random_capacity) : head(nullptr) {
		int count = 0;
		while (count != size) {
			this->push_tail((float)(rand()) * (random_capacity - 0.0001f) / RAND_MAX + 0.0001f);
			count += 1;
		}
	}

	template<typename T>
	LinkedList<T>::~LinkedList() {
		while (head) {
			Node<T>* tmp = head;
			head = head->next;
			delete tmp;
			tmp = nullptr;
		}
	}
}
#endif