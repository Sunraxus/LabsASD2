#include<LinkedList.cpp>
#include<iostream>

using namespace Linkedlist;
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	LinkedList<int> list1;
	cout << "Список 1 созданный конструктором по умолчанию : " << list1 << endl << endl;

	LinkedList<int> list2(5, 100); 
	cout << "Список 2 созданный конструктором с рандомными целыми значениями: " << list2 << endl << endl;

	LinkedList<float> list3(5, 100.5f);
	cout << "Список 3 созданный конструктором с рандомными дробными значениями: " << list3 << endl << endl;

	LinkedList<int> list4(list2);
	cout << "Список 4 созданный конструктором копирования из списка 2: " << list4 << endl << endl;

	list1.push_tail(15);
	list1.push_tail(-15);
	cout << "Список 1 с push_tail(15), а затем push_tail(-15): " << list1 << endl << endl;

	cout << "Список 2: " << list2 << endl;
	list2.push_tail(list1);
	cout << "Список 2 с push_tail(list 1): " << list2 << endl << endl;

	cout << "Список 1: " << list1 << endl;
	list1.push_head(100);
	cout << "Список 1 с push_head(100): " << list1 << endl << endl;

	cout << "Список 1: " << list1 << endl;
	cout << "Список 2: " << list2 << endl;
	list2.push_head(list1);
	cout << "Список 2 с push_head(list1): " << list2 << endl << endl;

	cout << "Список 2: " << list2 << endl;
	list2.pop_head();
	cout << "Список 2 после pop_head: " << list2 << endl << endl;

	cout << "Список 2: " << list2 << endl;
	list2.pop_tail();
	cout << "Список 2 после pop_tail: " << list2 << endl << endl;

	LinkedList<int> list5;
	list5.push_tail(15);
	list5.push_tail(-15);
	list5.push_tail(15);
	list5.push_tail(-15);
	cout << "Список 5: " << list5 << endl;
	list5.delete_node(15);
	cout << "Список 5 после delete_node(15): " << list5 << endl << endl;

	cout << "Список 1: " << list1 << endl;
	cout << "[1] в списке 1: " << list1[1] << endl << endl;

	cout << "Список 1: " << list1 << endl;
	list1[1] = 322;
	cout << "Список 1 после list1[1] = 322: " << list1 << endl << endl;

	cout << "-----------------------------------------------------------------" << endl << endl;

	LinkedList<float> list6;

	LinkedList<float> list7(5, 100.15f);

	cout << "Список 6: " << list6 << endl;
	list6.push_tail(15.532f);
	list6.push_tail(-10.32f);
	cout << "Список 6 с push_tail(15.532f), а затем push_tail(-10.32f): " << list6 << endl << endl;

	cout << "Список 6: " << list6 << endl;
	cout << "Список 7: " << list7 << endl;
	list6.push_tail(list7);
	cout << "Список 6 с push_tail(list 7): " << list6 << endl << endl;

	cout << "Список 7: " << list7 << endl;
	list7.push_head(104.14f);
	cout << "Список 7 с push_head(1045.1045f): " << list7 << endl << endl;

	cout << "Список 6: " << list6 << endl;
	cout << "Список 7: " << list7 << endl;
	list7.push_head(list6);
	cout << "Список 7 с push_head(list6): " << list7 << endl << endl;

	cout << "Список 6: " << list6 << endl;
	list6.pop_head();
	cout << "Список 6 после pop_head: " << list6 << endl << endl;

	cout << "Список 6: " << list6 << endl;
	list6.pop_tail();
	cout << "Список 6 после pop_tail: " << list6 << endl << endl;

	LinkedList<float> list8;
	list8.push_tail(10.48f);
	list8.push_tail(-15.0f);
	list8.push_tail(15.0f);
	list8.push_tail(10.48f);
	cout << "Список 8: " << list8 << endl;
	list8.delete_node(10.48f);
	cout << "Список 8 после delete_node(10.48f): " << list8 << endl << endl;

	cout << "Список 7: " << list7 << endl;
	cout << "[3] в списке 7: " << list7[3] << endl << endl;

	cout << "Список 7: " << list7 << endl;
	list7[3] = 322.322f;
	cout << "Список 7 после list7[3] = 322.322f: " << list7 << endl << endl;
}