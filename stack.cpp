//two stacks in one array

#include <bits/stdc++.h> 
class TwoStack {

    int size;
    int top1;
    int top2;
    int* arr;


public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
        this->top1=-1;
        this->top2=s;
        this->arr=new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(this->top2-this->top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
       if(this->top2-this->top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(this->top1>-1){
            int ans=arr[this->top1];
            this->top1--;
            return ans;
        }else{
            return -1;
        }

    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(this->top2<this->size){
            int ans=arr[this->top2];
            this->top2++;
            return ans;
        }else{
            return -1;
        }
    }
};

//stack implementation using linked list
// C++ program to Implement a stack
// using singly linked list
#include <bits/stdc++.h>
using namespace std;

// creating a linked list;
class Node {
public:
	int data;
	Node* link;

	// Constructor
	Node(int n)
	{
		this->data = n;
		this->link = NULL;
	}
};

class Stack {
	Node* top;

public:
	Stack() { top = NULL; }

	void push(int data)
	{

		// Create new node temp and allocate memory in heap
		Node* temp = new Node(data);

		// Check if stack (heap) is full.
		// Then inserting an element would
		// lead to stack overflow
		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}

		// Initialize data into temp data field
		temp->data = data;

		// Put top pointer reference into temp link
		temp->link = top;

		// Make temp as top of Stack
		top = temp;
	}

	// Utility function to check if
	// the stack is empty or not
	bool isEmpty()
	{
		// If top is NULL it means that
		// there are no elements are in stack
		return top == NULL;
	}

	// Utility function to return top element in a stack
	int peek()
	{
		// If stack is not empty , return the top element
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}

	// Function to remove
	// a key from given queue q
	void pop()
	{
		Node* temp;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {

			// Assign top to temp
			temp = top;

			// Assign second node to top
			top = top->link;

			// This will automatically destroy
			// the link between first node and second node

			// Release memory of top node
			// i.e delete the node
			free(temp);
		}
	}

	// Function to print all the
	// elements of the stack
	void display()
	{
		Node* temp;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {

				// Print node data
				cout << temp->data;

				// Assign temp link to temp
				temp = temp->link;
				if (temp != NULL)
					cout << " -> ";
			}
		}
	}
};

// Driven Program
int main()
{
	// Creating a stack
	Stack s;

	// Push the elements of stack
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);

	// Display stack elements
	s.display();

	// Print top element of stack
	cout << "\nTop element is " << s.peek() << endl;

	// Delete top elements of stack
	s.pop();
	s.pop();

	// Display stack elements
	s.display();

	// Print top element of stack
	cout << "\nTop element is " << s.peek() << endl;

	return 0;
}

