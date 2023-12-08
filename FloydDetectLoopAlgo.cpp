#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
};

bool FloydCycleDetection(Node* head){
    if (head==NULL) return false;

    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if (fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if (slow==fast){
            return true;
        }
    }
    return false;
}
