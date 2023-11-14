#include<LinkedList.cpp>
#include<iostream>

using namespace Linkedlist;
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	LinkedList<int> list1;
	list1.push_tail(2);
	list1.push_tail(3);
	list1.push_tail(5);
	cout << list1 <<endl;

	LinkedList<int> list2;
	list2.push_tail(2);
	list2.push_tail(3);

	cout << list2 << endl;
	list1.push_tail(list2);
	cout << list1 << endl;
}