#include<LinkedList.cpp>
#include<iostream>

using namespace Linkedlist;
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	LinkedList<int> list1;
	cout << "������ 1 ��������� ������������� �� ��������� : " << list1 << endl << endl;

	LinkedList<int> list2(5, 100); 
	cout << "������ 2 ��������� ������������� � ���������� ������ ����������: " << list2 << endl << endl;

	LinkedList<float> list3(5, 100.5f);
	cout << "������ 3 ��������� ������������� � ���������� �������� ����������: " << list3 << endl << endl;

	LinkedList<int> list4(list2);
	cout << "������ 4 ��������� ������������� ����������� �� ������ 2: " << list4 << endl << endl;

	list1.push_tail(15);
	list1.push_tail(-15);
	cout << "������ 1 � push_tail(15), � ����� push_tail(-15): " << list1 << endl << endl;

	cout << "������ 2: " << list2 << endl;
	list2.push_tail(list1);
	cout << "������ 2 � push_tail(list 1): " << list2 << endl << endl;

	cout << "������ 1: " << list1 << endl;
	list1.push_head(100);
	cout << "������ 1 � push_head(100): " << list1 << endl << endl;

	cout << "������ 1: " << list1 << endl;
	cout << "������ 2: " << list2 << endl;
	list2.push_head(list1);
	cout << "������ 2 � push_head(list1): " << list2 << endl << endl;

	cout << "������ 2: " << list2 << endl;
	list2.pop_head();
	cout << "������ 2 ����� pop_head: " << list2 << endl << endl;

	cout << "������ 2: " << list2 << endl;
	list2.pop_tail();
	cout << "������ 2 ����� pop_tail: " << list2 << endl << endl;

	LinkedList<int> list5;
	list5.push_tail(15);
	list5.push_tail(-15);
	list5.push_tail(15);
	list5.push_tail(-15);
	cout << "������ 5: " << list5 << endl;
	list5.delete_node(15);
	cout << "������ 5 ����� delete_node(15): " << list5 << endl << endl;

	cout << "������ 1: " << list1 << endl;
	cout << "[1] � ������ 1: " << list1[1] << endl << endl;

	cout << "������ 1: " << list1 << endl;
	list1[1] = 322;
	cout << "������ 1 ����� list1[1] = 322: " << list1 << endl << endl;

	cout << "-----------------------------------------------------------------" << endl << endl;

	LinkedList<float> list6;

	LinkedList<float> list7(5, 100.15f);

	cout << "������ 6: " << list6 << endl;
	list6.push_tail(15.532f);
	list6.push_tail(-10.32f);
	cout << "������ 6 � push_tail(15.532f), � ����� push_tail(-10.32f): " << list6 << endl << endl;

	cout << "������ 6: " << list6 << endl;
	cout << "������ 7: " << list7 << endl;
	list6.push_tail(list7);
	cout << "������ 6 � push_tail(list 7): " << list6 << endl << endl;

	cout << "������ 7: " << list7 << endl;
	list7.push_head(104.14f);
	cout << "������ 7 � push_head(1045.1045f): " << list7 << endl << endl;

	cout << "������ 6: " << list6 << endl;
	cout << "������ 7: " << list7 << endl;
	list7.push_head(list6);
	cout << "������ 7 � push_head(list6): " << list7 << endl << endl;

	cout << "������ 6: " << list6 << endl;
	list6.pop_head();
	cout << "������ 6 ����� pop_head: " << list6 << endl << endl;

	cout << "������ 6: " << list6 << endl;
	list6.pop_tail();
	cout << "������ 6 ����� pop_tail: " << list6 << endl << endl;

	LinkedList<float> list8;
	list8.push_tail(10.48f);
	list8.push_tail(-15.0f);
	list8.push_tail(15.0f);
	list8.push_tail(10.48f);
	cout << "������ 8: " << list8 << endl;
	list8.delete_node(10.48f);
	cout << "������ 8 ����� delete_node(10.48f): " << list8 << endl << endl;

	cout << "������ 7: " << list7 << endl;
	cout << "[3] � ������ 7: " << list7[3] << endl << endl;

	cout << "������ 7: " << list7 << endl;
	list7[3] = 322.322f;
	cout << "������ 7 ����� list7[3] = 322.322f: " << list7 << endl << endl;
}