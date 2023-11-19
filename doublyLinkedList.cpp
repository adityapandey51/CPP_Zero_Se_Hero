#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

//gives length of Linked List
int getLength(Node* head) {
    int len = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}

void insertAtBegin(int data,Node* &head,Node* &tail){
    Node* node=new Node(data);
    if(head==NULL){
        head=node;
        tail=node;
    }else{
        head->prev=node;
        node->next=head;
        head=node;
    }
}

void insertAtEnd(int data,Node* &tail,Node* &head){
    Node* node=new Node(data);
   if(tail==NULL){
        tail=node;
        head=node;
   }else{
        tail->next=node;
        node->prev=tail;
        tail=node;
   }
}

void insertAtMiddle(int data,Node* &head,Node* & tail,int position){
    Node* node=new Node(data);
    Node* temp=head;
    if(position==1){
        insertAtBegin(data,head,tail);
        return;
    }
    for(int i=0;i<position-2;i++){
        temp=temp->next;
    }

    if(temp->next==NULL){
        insertAtEnd(data,tail,head);
        return;
    }

    
    Node*  ne=temp->next;
    temp->next=node;
    node->prev=temp;
    ne->prev=node;
    node->next=ne;
}
void deleteNode(int position,Node* &head,Node* &tail){
    Node* temp=head;
    if(position==1){
       temp->next->prev=NULL;
       head=temp->next;
       free(temp);
       return;
    }
    if(position==getLength(head)){
        Node* tem=tail;
        tem->prev->next=NULL;
        free(tem);
        return;
    }
    for(int i=0;i<position-2;i++){
        temp=temp->next;
    }
    Node* del=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    free(del);

}

void printLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl<<endl;
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtBegin(10,head,tail);
    insertAtBegin(20,head,tail);
    insertAtEnd(5,tail,head);
    insertAtMiddle(30,head,tail,1);
    insertAtMiddle(4,head,tail,5);
    // deleteNode(1,head,tail);
    // deleteNode(4,head,tail);
    deleteNode(3,head,tail);
    printLL(head);
}