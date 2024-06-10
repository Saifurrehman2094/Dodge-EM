#include<iostream>
using namespace std;
class List
{
private:
	int* arr;
	int size;
	int capacity;
public:
	List()
	{ //constructor
		cout << "Enter the size of the array." << endl;
		cin >> size;
		arr = new int[size];
		capacity = size;
		cout << "Enter the elements of the array." << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
	void insertAtEnd(int element) {
		if (size == capacity) {
			int new_capacity = capacity * 2;
			int* new_arr = new int[new_capacity];
			for (int i = 0; i < size; ++i) {
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			capacity = new_capacity;
		}
		arr[size] = element;
		size++;
	}
	void insertAtStart(int element) {
		if (size == capacity) {
			int new_capacity = capacity * 2;
			int* new_arr = new int[new_capacity];
			for (int i = 0; i < size; ++i) {
				new_arr[i + 1] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			capacity = new_capacity;
		}
		else {
			for (int i = size - 1; i >= 0; --i) {
				arr[i + 1] = arr[i];
			}
		}
		arr[0] = element;
		size++;
	}
	void insertAtPos(int element, int pos) {
		if (pos < 0 || pos > size) {
			cout << "Invalid position." << std::endl;
			return;
		}
		if (size == capacity) {
			int new_capacity = capacity * 2;
			int* new_arr = new int[new_capacity];
			for (int i = 0; i < pos; ++i) {
				new_arr[i] = arr[i];
			}
			for (int i = size - 1; i >= pos; --i) {
				new_arr[i + 1] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			capacity = new_capacity;
		}
		else {
			for (int i = size - 1; i >= pos; --i) {
				arr[i + 1] = arr[i];
			}
		}
		arr[pos] = element;
		size++;
	}
	
	void RemovefromStart() {
		if (size == 0) {
			std::cout << "List is empty. Cannot remove from start." << std::endl;
			return;
		}
		for (int i = 0; i < size - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
	void RemovefromEnd() {
		if (size == 0) {
			std::cout << "List is empty. Cannot remove from end." << std::endl;
			return;
		}
		size--; //  to remove the last element
		
	}
	void RemovefromPos(int pos) {
		if (pos < 0 || pos >= size) {
			std::cout << "Invalid position. Cannot remove element." << std::endl;
			return;
		}
		for (int i = pos; i < size - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
	bool isEmpty() {
		if (size == 0) {
			return 1;
		}
		return 0;
	}
	void printList() {
		if (size == 0) {
			cout << "List is empty." << std::endl;
			return;
		}
		cout << "List elements:";
		for (int i = 0; i < size; ++i) {
			std::cout << " " << arr[i];
		}
		cout << std::endl;
	}
	void clearList() {
		delete[] arr;
		size = 0;
		capacity = 0;
		arr = nullptr;
	}
	bool hasDuplicates() {
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				if (arr[i] == arr[j]) {
					return true;
				}
			}
		}
		return false;
	}
	int next(int p) {
		if (p >= 0 && p < size - 1) {
			return p + 1; // Return the next position
		}
		else {
			std::cout << "Invalid position." << std::endl;
			return -1; 
		}
	}
	int previous(int p) {
		if (p > 0 && p < size) {
			return p - 1; 
		}
		else {
			std::cout << "Invalid position." << std::endl;
			return -1;
		}
	}
	void replace(int index, int newValue) {
		if (index >= 0 && index < size) {
			arr[index] = newValue; 
		}
		else {
			cout << "Invalid index." << std::endl;
		}
	}
};
