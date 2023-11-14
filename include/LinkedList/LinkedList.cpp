#ifndef INCLUDE_LinkedList_LinkedList_H_
#define INCLUDE_LinkedList_LinkedList_H_

#include <iostream>
#include <cstdlib> 
#include <stdexcept> 
#include <random>

using namespace std;

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
		LinkedList(); //+
		LinkedList(const LinkedList<T>& other); //+
		LinkedList(const int size, const int random_capacity); //+
		LinkedList(const int size, const float random_capacity); //+
		~LinkedList();
		LinkedList& operator=(const LinkedList<T>& other); //+
		void push_tail(const T& value); //+
		void push_tail(const LinkedList<T>& other); //+
		void push_head(const T& value); //+
		void push_head(const LinkedList<T>& other); //+
		void pop_head(); //+
		void pop_tail(); //+
		void delete_node(const T& val); //+
		T& operator[](int index); //+
		const T operator[](int index) const; //+
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

	template<typename T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
		if (this == &other) {
			return *this;
		}
		while (head) {
			pop_head();
		}
		Node<T>* tmp = other.head;
		while (tmp) {
			push_tail(tmp->value);
			tmp = tmp->next;
		}
		return *this;
	}

	template<typename T>
	void LinkedList<T>::push_tail(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			newNode->prev = current;
			current->next = newNode;

		}
	}

	template<typename T>
	void LinkedList<T>::push_head(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			head = newNode;
			head->next = current;
			current->prev = head;
		}
	}

	template<typename T>
	void LinkedList<T>::pop_head() {
		if (head == nullptr) {
			throw length_error("Cannot delete element in empty list");
		}
		else {
			if (head->next == nullptr) {
				delete head;
				head = nullptr;
			}
			else {
				Node<T>* tmp = head;
				head = head->next;
				head->prev = nullptr;
				delete tmp;
				tmp = nullptr;
			}
		}
	}

	template<typename T>
	void LinkedList<T>::pop_tail() {
		if (head == nullptr) {
			throw length_error("Cannot delete element in empty list");
		}
		else {
			Node<T>* last = head;
			while (last->next != nullptr) {
				last = last->next;
			}
			Node<T>* pre_last = last->prev;
			if (pre_last != nullptr) {
				pre_last->next = nullptr;
			}
			else {
				head = nullptr;
			}
			delete last;
			last = nullptr;


		}
	}

	template<typename T>
	void LinkedList<T>::push_tail(const LinkedList<T>& other) {
		if (other.head != nullptr) {
			Node<T>* tmp_other = other.head;
			while (tmp_other) {
				this->push_tail(tmp_other->value);
				tmp_other = tmp_other->next;
			}
		}
	}

	template<typename T>
	void LinkedList<T>::push_head(const LinkedList<T>& other) {
		if (other.head != nullptr) {
			Node<T>* tmp_other = other.head;
			LinkedList<T> reversed_other; 
			while (tmp_other) {
				reversed_other.push_head(tmp_other->value);
				tmp_other = tmp_other->next;
			}
			tmp_other = reversed_other.head;
			while (tmp_other) {
				this->push_head(tmp_other->value);
				tmp_other = tmp_other->next;
			}
		}
	}

	template<typename T>
	T& LinkedList<T>::operator[](const int index) {
		Node<T>* tmp = head;
		int count = 0;
		while (tmp != nullptr) {
			if (count == index) {
				return tmp->value;
			}
			else {
				tmp = tmp->next;
				count ++;
			}
		}
		throw out_of_range("Index out of range");
	}

	template<typename T>
	const T LinkedList<T>::operator[](const int index) const{
		Node<T>* tmp = head;
		int count = 0;
		while (tmp != nullptr) {
			if (count == index) {
				return tmp->value;
			}
			else {
				tmp = tmp->next;
				count++;
			}
		}
		throw out_of_range("Index out of range");
	}

	template<typename T>
	void LinkedList<T>::delete_node(const T& val) {
		if (head != nullptr) {
			Node<T>* current = head;
			Node<T>* tmp = nullptr;
			while (current != nullptr) {
				tmp = current->next;
				if (current->value == val) {
					if (current->prev == nullptr) {
						this->pop_head();
					}
					else {
						if (current->next == nullptr) {
							this->pop_tail();
						}
						else {
							current->next->prev = current->prev;
							current->prev->next = current->next;
							delete current;
						}
					}
				}
				current = tmp;
			}
		}
		else {
			throw length_error("Empty list");
		}
	}

	template<typename T>
	ostream& operator<<(std::ostream& stream, LinkedList<T>& rhs)
	{
		Node<T>* tmp = rhs.get_head();
		if (tmp == nullptr) {
			stream << "Empty list";
			return stream;
		}
		while (tmp != nullptr) {
			stream << tmp->value << " ";
			tmp = tmp->next;
		}
		return stream;
	}
}
#endif