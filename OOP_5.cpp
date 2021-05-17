//============================================================================
// Name        : OOP_5.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Write a function template for
//selection sort that inputs, sorts and outputs
//an integer array and a float array.
//============================================================================

//#include <iostream>
//using namespace std;
//
//int n;
//#define size 25
//template<class T>
//
//void selectionSort(T arr[size]) {
//
//	int i, j, min;
//	T temp;
//
//	for (i = 0; i < n - 1; i++) {
//		min = i;
//
//		for (j = i + 1; j < n; j++) {
//			if (arr[j] < arr[min])
//				min = j;
//		}
//
//		temp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = temp;
//	}
//
//	cout << "\nSorted Array:";
//	for (i = 0; i < n; i++) {
//		cout << " " << arr[i];
//	}
//	cout << endl;
//}
//
//int main() {
//
//	int integer_arr[size];
//	float float_arr[size];
//	bool start = true;
//	int option;
//
//	cout << "Menu"
//			"\n1.Sort integer array."
//			"\n2.Sort float array."
//			"\n0.Exit." << endl;
//
//	while (start) {
//		cout << "\nEnter choice: ";
//		cin >> option;
//		switch (option) {
//		case 1:
//			cout << "\nEnter number of elements: ";
//			cin >> n;
//			for (int i = 0; i < n; i++) {
//				cout << "Enter element " << i + 1 << ": ";
//				cin >> integer_arr[i];
//			}
//			cout << "\nUnsorted Array:";
//			for (int j = 0; j < n; j++) {
//				cout << " " << integer_arr[j];
//			}
//			cout << endl;
//
//			selectionSort(integer_arr);
//			break;
//
//		case 2:
//			cout << "Enter number of elements: ";
//			cin >> n;
//			for (int i = 0; i < n; i++) {
//				cout << "Enter element " << i + 1 << ": ";
//				cin >> float_arr[i];
//			}
//			cout << "\nUnsorted Array:";
//			for (int j = 0; j < n; j++) {
//				cout << " " << float_arr[j];
//			}
//			cout << endl;
//
//			selectionSort(float_arr);
//			break;
//
//		case 0:
//			start = false;
//			break;
//		}
//	}
//
//	return 0;
//}

#include <bits/stdc++.h>

using namespace std;

const int D = 100;

template <class T>
class SelectionSort
{
private:
	int n;
	T arr[D];
public:
	SelectionSort()
	{
		n = 0;
	}
	void setArray()
	{
		cout << "Enter size: "; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Enter element number - " << i + 1 << ": ";
			cin >> arr[i];
		}
	}
	void PrintArray()
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	void Sort()
	{  // sort using selection sort algorithm
		int i, j, min_idx;
		for (i = 0; i < n - 1; i++) {
			min_idx = i;
			for (j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;
			swap(arr[min_idx], arr[i]);
		}
	}
};

int main()
{
	while (true)
	{
		cout << "1.Sort integer array\n2.Sort float array\n0.Exit\nEnter choice:";
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			SelectionSort<int> int_sort;
			int_sort.setArray();
			cout << "Before Sorting: ";
			int_sort.PrintArray();
			int_sort.Sort();
			cout << "After Sorting: ";
			int_sort.PrintArray();
		}
		else if (choice == 2)
		{
			SelectionSort<float> float_sort;
			float_sort.setArray();
			cout << "Before Sorting: ";
			float_sort.PrintArray();
			float_sort.Sort();
			cout << "After Sorting: ";
			float_sort.PrintArray();
		}
		else if (choice == 0)
			break;
		else
			cout << "INVALID CHOICE. Try Again.\n";
	}
	return 0;
}
