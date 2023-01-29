#pragma once
#pragma once
#include <iostream>
using namespace std;

template <class T> class MyQueue {
public:
	//variables for queue management
	T* dynamicArray;
	int size;
	int top;

	//constructor
	MyQueue()
	{
		size = 1;
		top = -1;
		dynamicArray = new T[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = NULL; //Initializes all queue contents to NULL
		}

	};

	//copy constructor
	MyQueue(const MyQueue& other) {

		size = other.size;
		top = other.top;

		dynamicArray = new T[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = other.dynamicArray[i];
		}
	}
	MyQueue& operator=(const MyQueue& other) {

		if (this == &other) {
			return *this;
		}

		if (dynamicArray != nullptr) {
			delete[] dynamicArray;
			dynamicArray = nullptr;
		}

		size = other.size;
		top = other.top;
		dynamicArray = new T[size];
		copy(other.dynamicArray,
			other.dynamicArray + other.size,
			dynamicArray);

		return *this;
	}

	//destructor 
	~MyQueue()
	{
		size = 0;
		top = 0;
		delete[] dynamicArray;
		dynamicArray = nullptr;

	};

	//takes data and puts it on top of the queue
	void Push(T newNode) {
		//adds one to the top's index
		top++;
		//if the top index is less than the size, we don't need to make a new array
		if (top < size) {
			dynamicArray[top] = newNode; //If queue is Vacant store Value in Array
		}
		//otherwise, double the size and re-point the current array to the larger one
		else {
			size = size * 2;
			T* largerArray = new T[size];
			for (int i = 0; i < top; i++) {
				largerArray[i] = dynamicArray[i];
			}
			largerArray[top] = newNode;
			delete[] dynamicArray;
			dynamicArray = largerArray;
		}

		//sorts as items are pushed via flags and a basic bubble sort
		bool swaps;
		do {
			swaps = false; // assume the queue is sorted
			for (int i = 0; i < top; i++) {
				//if any element is larger than the following element, store element 1 in a temp, set element one to the smaller following, then set the first element to follow the second
				if (dynamicArray[i] > dynamicArray[i + 1]) {
					T temp = dynamicArray[i];
					dynamicArray[i] = dynamicArray[i + 1];
					dynamicArray[i + 1] = temp;
					swaps = true; // after any swap, check again
				}
			}
		} while (swaps);
		cout << "Pushed" << endl;
	}

	//returns and "removes" the bottom item from the queue
	T Pop() {
		if (IsEmpty()) {
			cout << "Queue empty." << endl;
			return NULL;
		}
		else {
			//Set bottom Value in data
			T data = dynamicArray[0];
			//Set Original Location to NULL
			dynamicArray[0] = NULL;
			for (int i = 0; i < top; i++) {
				dynamicArray[i] = dynamicArray[i + 1];
			}
			dynamicArray[top] = NULL;
			top--;
			cout << "Popped" << endl;
		}
	}
	//prints the queue
	void Print() {
		for (int i = 0; i < (top + 1); i++) {
			cout << dynamicArray[i] << endl;
		}
	}

	//returns the size of the array
	int GetSize() {
		int returnedSize = 0;
		for (int i = 0; i < top + 1; i++) {
				returnedSize++;
			}
		return returnedSize;
	}

	//checks if the queue is empty
	bool IsEmpty() {
		if (top == -1) {
			return true;
		}
		return false;
	}
};

