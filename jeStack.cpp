/*
Basic Stack in C++
@author: PARK JI EUN
@date: 2016.12.19
*/
#include <iostream>

using namespace std;

template <typename T>
class Stack {
	friend ostream& operator<<(ostream& os, Stack stack) {
		if (!stack.IsEmpty()) {
			for (int i = stack.top; i > -1; i--) {
				os << "\t" << stack.stack[i] << endl;
			}
		}
		return os;
	};
public:
	Stack();
	Stack(int);
	void Pop(); // Pop stack
	void Push(const T&); // Push data to stack
	T& Top(); // Get the data top of stack
	bool IsEmpty(); // Check the stack is empty or not
	bool IsFull(); // Check the stack is full or not
private:
	T* stack;
	int top = -1; // points nothing
	int capacity;
};

/* Stack Constructor */
template <typename T>
Stack<T>::Stack() {
	capacity = 10;
	stack = new T[capacity];
}

template <typename T>
Stack<T>::Stack(int _capacity) {
	capacity = _capacity;
	stack = new T[capacity];
}

template <typename T>
void Stack<T>::Pop() {
	if (IsEmpty()) {
		return;
	}
	else {
		top--;
	}
}

template <typename T>
void Stack<T>::Push(const T& data) {
	if (IsFull()) {
		return;
	}
	else {
		stack[++top] = data;
	}
}

template <typename T>
T& Stack<T>::Top() {
	T result = NULL;
	if (!IsEmpty()) {
		result = stack[top];
	}
	return result;
}

template <typename T>
bool Stack<T>::IsEmpty() {
	bool isEmpty = false;
	if (top < 0) {
		isEmpty = true;
		cout << "\tStack is Empty." << endl;
	}
	return isEmpty;
}

template <typename T>
bool Stack<T>::IsFull() {
	bool isFull = false;
	if (top == capacity - 1) {
		isFull = true;
		cout << "\tStack is Full." << endl;
	}
	return isFull;
}

Stack<char> CreateStack(int _capacity) {
	Stack<char> stack(_capacity);
	return stack;
}

bool IsValid(int value) {
	bool isValid = false;
	// Capacity should be a positive number.
	if (value > 0 && value < UINT_MAX) {
		isValid = true;
	}
	return isValid;
}

int main(void)
{
	int select = 0;
	int value;
	char data;
	bool stackExists = false;
	Stack<char> stack = NULL;
	while (true)
	{
		cout << "\n- Select Command -" << endl;
		cout << "1: Create Stack, 2: Delete Stack, 3: Push, "
			"4: Pop, 5: Top, 6:Display, 0: Quit\n\t>> ";
		cin >> select;
		switch (select)
		{
		case 1:
			do {
				cout << "\tEnter Capacity >> ";
				cin >> value;
			} while (!IsValid(value));

			stack = CreateStack(value);
			stackExists = true;
			break;
		case 2:
			stack.~Stack();
			stackExists = false;
			break;
		case 3:
			if (stackExists) {
				cout << "\tEnter Data to Push >> ";
				cin >> data;
				stack.Push(data);
			}
			else {
				cout << "\tCreate Stack first." << endl;
			}
			break;
		case 4:
			if (stackExists) {
				stack.Pop();
			}
			else {
				cout << "\tCreate Stack first." << endl;
			}
			break;
		case 5:
			if (stackExists) {
				cout << "\tTop >> " << stack.Top() << endl;
			}
			else {
				cout << "\tCreate Stack first." << endl;
			}
			break;
		case 6:
			cout << stack;
			break;
		case 0:
			cout << "BYE!" << endl;
			exit(0);
		default:
			cout << "WRONG INPUT" << endl;
			cout << "Re-Enter" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}