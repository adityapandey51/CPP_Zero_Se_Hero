#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:
    Node(int data){
        this->data=data;
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

void insertAtBegin(Node* &Head,int data){
    //new node
    Node* temp=new Node(data);
    temp->next=Head;
    Head=temp;
}

void insertAtEnd(Node* &tail,int data){

    Node* node=new Node(data);
    tail->next=node;
    tail=node;

}

void insertAtMiddle(int position,Node* &head,Node* &tail,int data){
    Node* temp=head;
    if(position==1){
        insertAtBegin(head,data);
        return;
    };
    for (int i=0;i<position-2;i++){
        temp=temp->next;
    }

    if(temp -> next == NULL) {
        insertAtEnd(tail,data);
        return ;
    }

    Node* node=new Node(data);
    node->next=temp->next;
    temp->next=node;
}

void deleteByPos(int position,Node* &head){
    Node* temp=head;
    if (position==1){
        head=temp->next;
        free(temp);
    }
    for(int i=0;i<position-2;i++){
        temp=temp->next;
    }
    temp->next=(temp->next)->next;
    free(temp->next);
}

void printLL(Node* &head){
    Node* temp=head;

    while(temp!=NULL){{
        cout<<temp->data<<endl;
        temp=temp->next;
    }}

}



int main(){
    Node* node1=new Node(5);

    Node* head=node1;
    Node* tail = node1;

    insertAtBegin(head,6);
    insertAtBegin(head,7);
    insertAtEnd(tail,4);
    insertAtEnd(tail,3);
    insertAtMiddle(3,head,tail,51);
    insertAtMiddle(7,head,tail,63);
    insertAtMiddle(1,head,tail,1);
    deleteByPos(1,head);
    deleteByPos(7,head);
     deleteByPos(3,head);
    cout<<head->data<<endl<<endl;
    printLL(head);



    // cout<<node1->data<<endl;
}