#include<LinkedList.cpp>
#include<iostream>

using namespace Linkedlist;
using namespace std;

template <typename T>
LinkedList<T> summ(LinkedList<T> list1, LinkedList<T> list2) {
	LinkedList<int> result;
	int carry = 0;
	int i = list1.get_size() - 1;
	int j = list2.get_size() - 1;
	while (i >= 0 || j >= 0  || carry)
	{
		int digit1 = i >= 0 ? list1[i] : 0;
		int digit2 = j >= 0 ? list2[j] : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result.push_head(sum % 10);
		if (i >= 0) --i;
		if (j >= 0) --j;
	}
	return result;
}

template <typename T>
LinkedList<T> multiply(const LinkedList<T>& list1, const LinkedList<T>& list2) {
	LinkedList<int> result;
	if (list1[0] == 0 || list2[0] == 0)
	{
		result.push_head(0);
		return result;
	}
	for (int i = list1.get_size() - 1; i >= 0; --i) {
		int carry = 0;
		LinkedList<T> temp_result;
		for (int k = 0; k < list1.get_size() - 1 - i; ++k) {
			temp_result.push_tail(0);
		}

		for (int j = list2.get_size() - 1; j >= 0; --j) {
			T digit1 = list1[i];
			T digit2 = list2[j];
			T product = digit1 * digit2 + carry;
			carry = product / 10;
			temp_result.push_head(product % 10);
		}

		if (carry > 0) {
			temp_result.push_head(carry);
		}

		result = summ(result, temp_result);
	}

	return result;
}

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

	cout << "-----------------------------------------------------------------" << endl << endl;
	
	LinkedList<int> list10(5, 10);
	LinkedList<int> list11(5, 10);
	LinkedList<int> list12;
	list12 = summ(list10, list11);
	cout << "Список 10: " <<  list10 << endl;
	cout << "Список 11: " <<  list11 << endl;
	cout << "Список 12, сумма 10 и 11 списка: " <<  list12 << endl;
	LinkedList<int> list13(5, 10);
	LinkedList<int> list14;
	LinkedList<int> list15;
	list14.push_head(4);
	list15 = multiply(list13, list14);
	cout << "Список 13: " <<  list13 << endl;
	cout << "Список 14: " <<  list14 << endl;
	cout << "Список 15, умножение списка 13 на 14: " << list15 << endl;
}