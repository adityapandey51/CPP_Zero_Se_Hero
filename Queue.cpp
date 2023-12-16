#include<iostream>
using namespace std;
#include<queue>

// queue<int> q;
// q.push(number);
// q.pop();
// q.empty();
// q.size();
// q.front();
// q.back();

// doubly ended queue;
// deque<int> d;
// d.size();
// d.push_front(number);
// d.push_back(number);
// d.pop_front();
// d.pop_back();
// d.empty();
// d.front();
// d.back();

// queue using array;

#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        this->size=100001;
        this->arr=new int[size];
        this->rear=this->qfront=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int data) {
        if (this->rear==this->size){
            return;
        }else{
            arr[rear]=data;
            this->rear++;
        }
    }

    int dequeue() {
        int ans;
        if(qfront==rear){
            return -1;
        }else{
            ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront==rear){
            return -1;
        }else{
            return arr[qfront];
        }
    }
};

--------------------------------------------------------------------------------------------

//circular queue
#include <bits/stdc++.h> 
class CircularQueue{
    int* arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
       this->size=n;
       this->arr=new int[size];
       this->front=this->rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front==0 && rear==size-1)||(rear==(front-1)%(size-1))){
            return false;
        }else if(front==-1){
            front=0;
            rear=0;
        }else if(rear==size-1 && front!=0){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        } 
        else if (front == size - 1) {
            front=0;
        }
        else {
            front++;
        }
        return ans;
    }
};

-----------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full or not
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
         if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};