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

Node* FloydCycleDetection(Node* head){
    if (head==NULL) return nullptr;

    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if (fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if (slow==fast){
            return slow;
        }
    }
    return nullptr;
}

Node* startOfLoop(Node* head){
    Node* intersection=FloydCycleDetection(head);
    if(intersection==NULL) return nullptr;
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head==NULL) return;
    if (!FloydCycleDetection) return;
    Node* start=startOfLoop(head);
    Node* temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=nullptr;
}
