// painters partition problem
#include<iostream>
using namespace std;
#include <vector>


bool ispossible(vector<int> &boards,int mid,int k){
    int painter=1;
    int sum=0;
    for(int i=0;i<boards.size();i++){
        if(sum+boards[i]<=mid){
            sum=sum+boards[i];
        }
        else{
            painter++;
            if(painter>k ||boards[i]>mid){
                return false;
            }
            sum=boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int e=0;
    for (int i=0;i<boards.size();i++){
        e=e+boards[i];
    }
    int mid=s+((e-s)/2);
    int ans;
    while(s<=e){
        if(ispossible(boards,mid,k)){
            ans=mid;
            e=mid-1;
            
        }
        else{
            s=mid+1;
        }
        mid=s+((e-s)/2);
    }
    return ans;
}

// aggressive cows

bool ispossible(vector<int>stalls,int mid,int k){
    int cowcount=1;
    int pos1=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-pos1>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            pos1=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0;
    int min=stalls[0];
    for (int i=1;i<stalls.size();i++){
        if (stalls[i]<min){
            min=stalls[i];
        }
    }
    int max=stalls[0];
     for (int i=1;i<stalls.size();i++){
        if (stalls[i]>min){
            max=stalls[i];
        }
    }
    int e=max-min;
    int mid=s+((e-s)/2);
    int ans;

    while(s<=e){
        if(ispossible(stalls,mid,k)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+((e-s)/2);
    }
    return ans;
}

// duplicate in a array

int findDuplicate(vector<int> &arr) 
{
     int ans=0;
     for (int i=0;i<arr.size();i++){
         ans=ans^arr[i];
     }
     for (int i=0;i<arr.size();i++){
         ans =ans^i;
     }
	return ans;
}

// intersection of arrays
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
	int i=0;
	int j=0;
	while(i<n && j<m){
		if (arr1[i]<arr2[j]){
			i++;
		}else if (arr1[i]>arr2[j]){
			j++;
		}else{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return ans;
}

// Duplicate in an array
//coding ninjas
int duplicate(int arr[],int size){
    int ans=0;
    for (int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    for (int j=1;j<size;j++){
        ans=ans^j;
    }
    return ans;
}

// PROBLEM 1:Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                 if(nums[i]+nums[j]==target){
                     ans.push_back(i);
                     ans.push_back(j);
                     break;
                 }
            }
        }
        return ans;
    }
};

// triplet sum

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;
	
    sort(arr.begin(),arr.end());
    for (int i=0;i<n;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            vector<int> temp;
            if (arr[i]+arr[l]+arr[r]==K){  
                temp.push_back(arr[i]);
                temp.push_back(arr[l]);
                temp.push_back(arr[r]);
                ans.push_back(temp);
                l++;
                r--;
            }else if(arr[i]+arr[l]+arr[r]<K){
                l++;
            }else{
                r--;
            }
        }
    }
    return ans;
}

// sort 0s 1s 2s

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low=0;
   int mid=0;
   int hi=n-1;
   while(mid<=hi){
      if (arr[mid]==0){
         swap(arr[low++],arr[mid++]);
      }else if (arr[mid]==1){
         mid++;
      }else{
         swap(arr[hi--],arr[mid]);
      }
   }
}

// first and last postion in an array

#include <bits/stdc++.h> 
int first_occurence(vector<int>& arr, int n, int k){
     int start=0;
    int end=n-1;
    int mid=start+((end-start)/2);
    int left=-1;
    while(start<=end){
        if (arr[mid]==k){
            left=mid;
            end=mid-1;
        }else if(arr[mid]>k){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return left;
}
int last_occurence(vector<int>& arr, int n, int k){
     int start=0;
    int end=n-1;
    int mid=start+((end-start)/2);
    int right=-1;
    while(start<=end){
        if (arr[mid]==k){
            right=mid;
            start=mid+1;
        }else if(arr[mid]>k){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return right;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int left=first_occurence(arr,n,k);
    int right=last_occurence(arr,n,k);
    pair<int,int> p;
    p.first=left;
    p.second=right;
    return p;

}

// Search in a rotated sorted array

int binary_search(vector<int>& arr, int start, int end, int k){
    int mid=start+((end-start)/2);
    while(start<=end){
        if (arr[mid]==k){
            return mid;
        }else if (arr[mid]>k){
            end=mid-1;
        }else(start=mid+1);
        mid=start+((end-start)/2);
    }
    return -1;
}
int pivot(vector<int>& arr, int n){
     int start=0;
    int end=n-1;
    int mid=start+((end-start)/2);
    while(start<end){
        if (arr[mid]>arr[0]){
            start=mid+1;
        }else{
            end=mid;
        }
        mid=start+((end-start)/2);
    }
    return mid;
}
int search(vector<int>& arr, int n, int k)
{
    int ans;
    int pi=pivot(arr,n);
   if(k>arr[0]&& k<=arr[pi-1]){
       ans=binary_search(arr,0,pi-1,k);
   }else{
       ans=binary_search(arr,pi,n-1,k);
   }
   return ans;
}


// sqrt(n)

int floorSqrt(int n)
{
    int s=0;
        int e=n;
        long long int m=s+((e-s)/2);
        int ans;
        while(s<=e){
            long long int sqr=m*m;
            if (sqr>n){
                e=m-1;
            }
            else if(sqr==n){
                return m;
            }
            else{
               ans=m;
               s=m+1;
            }
            m=s+((e-s)/2);
        }
        return ans;
}

// more precission

double more_precisiion(int n,int precision , int tempsol){
    int factor=1;
    int ans=tempsol;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for (double j=ans;j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;
}

// Reverse the array from given index

void reverseArray(vector<int> &arr , int m)
{
	int s=m+1;
	int e=arr.size()-1;
	while(s<=e){
		swap(arr[s],arr[e]);
		s++;
		e--;
	}
}

// sum of two arrays

#include <bits/stdc++.h> 
vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
    int i=n-1;
    int j=m-1;
    int carry=0;
    vector<int> ans;
    while(i>=0 && j>=0){
        int sum=a[i]+b[j]+carry;
        carry=sum/10;
        int value=sum%10;
        ans.push_back(value);
        i--;
        j--;
    }
    while(i>=0){
        int sum=a[i]+carry;
        carry=sum/10;
        int value=sum%10;
        ans.push_back(value);
        i--;
    }
    while(j>=0){
        int sum=b[j]+carry;
        carry=sum/10;
        int value=sum%10;
        ans.push_back(value);
        j--;
    }
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        int value=sum%10;
        ans.push_back(value);
    }
    
    return reverse(ans);
}

// other method

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
    int num1=0;
    int num2=0;
    for (int i=0;i<n;i++){
        num1=(num1*10)+a[i];
    }
    for (int i=0;i<m;i++){
        num2=(num2*10)+a[i];
    }

    int ans=num1+num2;
    vector<int> sol;
    while(ans){
        int digit=ans%10;
        sol.push_back(digit);
        ans=ans/10;
    }

    return reverse(sol);

}

// Check If The String Is A Palindrome


#include <bits/stdc++.h> 
char to_lower_case(char ch){
    if((ch>='a' && ch<='z') ||(ch>='0' && ch<='9') ){
        return ch;
    }else{
        char b= ch-'A'+'a';
        return b;
    }
   
    
}
bool isValid(char a){
    if ((a>='a' && a<='z') ||(a>='A' && a<='Z')||(a>='0' && a<='9')){
        return 1;
    }
    return 0;
}
bool check(string ab){
    int st=0;
    int e=ab.length()-1;
    while(st<e){
        if(ab[st]!=ab[e]){
            return false;
        }else{
            st++;
            e--;
        }
    }
    return true;
}
bool checkPalindrome(string s)
{
   
    string temp="";
        for (int i=0; i<s.length();i++){
            if(isValid(s[i])){
                temp.push_back(s[i]);
            }
        }
        for (int j=0; j<temp.length();j++){
            temp[j]=to_lower_case(temp[j]);
        }

       return check(temp);

}

------------------------------------------------------------------------------------
// replace spaces with @40
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	string temp="";
	for (int i=0;i<str.length();i++){
		if(str[i]==' '){
           temp.push_back('@');
		   temp.push_back('4');
		   temp.push_back('0');
		}
		else{
			temp.push_back(str[i]);
		}
	}
	return temp;
}

-------------------------------------------------------------------------------------------
// print like a wave

#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    int i=0;
    vector<int> ans;
    while(i<mCols){
        int j;
        if (!(i&1)){
           j=0;
        }else{
           j=nRows-1;
        }
       while(j<nRows && j>=0){
         ans.push_back(arr[j][i]);
          if (!(i&1)){
             j++;
          }else{
            j--;
          }
       }
       i++;
   }
   return ans;
}


----------------------------------------------------------------------------------
//count ways to reach n-stairs-recursion
//better done with DP

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    if (nStairs<0) return 0;
    if (nStairs==0) return 1;

    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}

------------------------------------------------------------------------------------
// reverse a string
#include <bits/stdc++.h> 
void reverse(string& str,int s,int e){
	if(s>e) return;
	swap(str[s],str[e]);
	s++;
	e--;
	reverse(str,s,e);
}
string reverseString(string str)
{
	
	reverse(str,0,str.length()-1);
	return str;
}

--------------------------------------------------------------------------------------
// check palindrome of binary representation of a number
#include <bits/stdc++.h> 
bool check(vector<int> str , int s,int e){
    if(s>e) return true;
    if (str[s]==str[e]){
        s++;
        e--;
        return check(str,s,e);
    } else{
        return false;
    }   
}
bool checkPalindrome(long long N)
{
	vector<int> ch;
	int i=0;
	while(N!=0){
		ch[i++]=N&1;
		N>>1;
	}
	reverse(ch.begin(),ch.end());
	return check(ch,0,ch.size()-1);
}

------------------------------------------------------------------------------------
// Subsequences of String

#include <bits/stdc++.h> 
void solve(string str,string output,int index,vector<string>& ans){
	if (index>=str.length()){
		if (output.length()>0){
			ans.push_back(output);
		}
		return;
	}
	solve(str,output,index+1,ans);

	char element=str[index];
	output.push_back(element);
	solve(str,output,index+1,ans);
}
vector<string> subsequences(string str){
	
	vector<string> ans;
	string output;
	int index=0;
	solve(str,output,index,ans);
	return ans;
	
}

-----------------------------------------------------------------------------------------------
//REVERSE LL USING RECURSION

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void reverse(LinkedListNode<int>* &head,LinkedListNode<int>* curr,LinkedListNode<int>* prev){
    if(curr==NULL){
        head=prev;
        return;
    }

    LinkedListNode<int>* forward=curr->next;
    curr->next=prev;
    reverse(head,forward,curr);
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   LinkedListNode<int>* curr=head;
   LinkedListNode<int>* prev=NULL;
   reverse(head,curr,prev);
   return head;
}

//REMOVE DUPLICATES FROM SORTED LINKED LIST

Node * removeDuplicates(Node *head)
{
  Node* curr=head;
  while(curr){
      while(curr->next && curr->data==curr->next->data)
        curr->next=curr->next->next;
    curr=curr->next;
  }
  return head;
}

-----------------------------------------------------------------------------------------
//REMOVE FROM UNSORTED LIST
#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    if (head==NULL || head->next==NULL) return head;

    map<int,bool> mp;
    Node* curr=head;
    Node* prev=curr;
    mp[curr->data]=true;
    Node* net=curr->next;
    while(net!=NULL){
        if (mp[net->data]){
            prev->next=prev->next->next;    
        }else{   
            mp[net->data]=true;
            prev=prev->next;
        }
        net=net->next;
           
    }
   
    return head;
}

//SORT LINKED LIST 0S,1S,2S

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    int zerocount=0;
    int onecount=0;
    int twocount=0;
    Node* temp=head;
    while(temp!=NULL){
        if (temp->data==0){
             zerocount++;
        }else if (temp->data==1){
            onecount++;
        }else{
            twocount++;
        } 
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if (zerocount){
            temp->data=0;
            zerocount--;
        }else if(onecount){
            temp->data=1;
            onecount--;
        }else{
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }
    return head;
}

//Theres another approach to the question,if no data replacement is required; the simply create three linked list with head 
//and tail pointers;
//and add the 0s 1s and 2s as u get them in the given linked list and at alast merge these three lists together.

--------------------------------------------------------------------------------------------------
//MERGE SORTED LINKED LISTS
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
  if(first==NULL || second==NULL){
      return ((first==NULL)?second:first);
  }
  Node<int>* ans=new Node<int>(0);
  Node<int>* curr=ans;
  while(first!=NULL && second!=NULL){
      if(first->data<second->data){
          curr->next=first;
          first=first->next;
      }else{
          curr->next=second;
          second=second->next;
      }
      curr=curr->next;
  }
  if(first!=NULL || second!=NULL){
      curr->next=((first!=NULL)?first:second);
  }
  Node<int>* head=ans->next;
  free(ans);
  return head;

} 

//ANOTHER APPROACH
// if (!first || !second)
//     return first ? first : second;
//  if (first->data > second->data)
//     swap(first, second);
//  first->next = sortTwoLists(first->next, second);
//  return first;

/////////////////////////////////////////////////////////////////////

//Mergesort linked list

/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* Mid(node*  head){
    if (head==NULL || head->next==NULL) return head;
    node* slow=head;
    node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node* left,node* right){
    if (left==NULL || right==NULL){
        return ((left==NULL)?right:left);
    }

    node* ans=new node(0);
    node* curr=ans;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            curr->next=left;
            left=left->next;
        }else{
            curr->next=right;
            right=right->next;
        }
        curr=curr->next;
    }
    if(left!=NULL || right!=NULL){
        curr->next=((left!=NULL)?left:right);
    }
    return ans->next; 
}
node *mergeSort(node *head) {
    if (head==NULL || head->next==NULL) return head;
    node* mid=Mid(head);
    node* newHead=mid->next;
    mid->next=NULL;

    node* left_head=mergeSort(head);
    node* right_head=mergeSort(newHead);
    return merge(left_head,right_head);
}

----------------------------------------------------------------------------------------
//.2 Stacks in one array

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

--------------------------------------------------------------------------------------
//DELETE MIDDLE ELEMENT OF STACK USING RECURRSION
#include <bits/stdc++.h> 

void solve(stack<int>&inputStack,int count,int size){
   if(count==size/2){
      inputStack.pop();
      return;
   }
   int num=inputStack.top();
   inputStack.pop();
   solve(inputStack,count+1,size);
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;
   solve(inputStack,count,N);
   
}

-------------------------------------------------------------------------------------
//valid paranthesis
bool isValidParenthesis(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if (ch=='{' || ch=='[' || ch=='('){
            st.push(ch);
        } else {
            if (!st.empty()) {
              char top = st.top();
              if (ch == '}' && top == '{') {
                st.pop();
              } else if (ch == ']' && top == '[') {
                st.pop();
              } else if (ch == ')' && top == '(') {
                st.pop();
              } else {
                return false;
              }
            } else {
              return false;
            }
        }
    }
    return st.empty();
}

-------------------------------------------------------------------------------------

//Insert An Element At Its Bottom In A Given Stack

#include <bits/stdc++.h> 
void solve(stack<int>& myStack,int x){
    if (myStack.empty()){
        myStack.push(x);
        return;
    }
    int num=myStack.top();
    myStack.pop();
    solve(myStack,x);
    myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}

-----------------------------------------------------------------------------------------
//SOrt a stack
#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stack,int x){
	if(stack.empty()){
		stack.push(x);
		return;
	}
	if (stack.top()>x){
		int y=stack.top();
		stack.pop();
		sortedInsert(stack,x);
		stack.push(y);
	}else{
		stack.push(x);
	}
}
void solve(stack<int> &stack){
	if (stack.empty()){
		return;
	}
	int x=stack.top();
	stack.pop();
	solve(stack);
	sortedInsert(stack,x);
}
void sortStack(stack<int> &stack)
{
	solve(stack);
}

----------------------------------------------------------------------------------------------
//REDUNDANT BRACKETS
#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
     stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return true;
                st.pop();
            }
            
        } 
    }
    return false;
}

---------------------------------------------------------------------------------------------
//MINIMUM COST TO MAKE A STRING VALID
#include <bits/stdc++.h> 
int findMinimumCost(string str) {
   //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
}

----------------------------------------------------------------------------------------
//Next smaller element.

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1 ; i>(-1) ; i--){
        int curr=arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}
------------------------------------------------------------------------------------------------------
//CELEBRITY PROBLEM
#include <bits/stdc++.h> 
#include<stack>
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> s;
	for(int i=0;i<n;i++){
		s.push(i);
	}

	while(s.size()>1){
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		if(knows(a,b)){
			s.push(b);
		}else{
			s.push(a);
		}
	}

	int num=s.top();
	for (int i=0;i<n;i++){
        if (knows(num,i) && i != num) {
                return -1;
        }
    }
    for (int i = 0; i < n; i++){
		if(!knows(i,num) && i!=num){
			return -1;
		}
	}
	return num;
}

------------------------------------------------------------------------------------------------------------
//Given a binary matrix M of size n X m. 
//Find the maximum area of a rectangle formed only of 1s in the given matrix.
class Solution{
  private:
     vector<int> nextSmaller(int* heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>-1; i--){
            int num=heights[i];
            while(s.top()>-1 && heights[s.top()]>=num){
                s.pop();
            }   
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
     vector<int> beforeSmaller(int* heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0; i<n;i++){
            int num=heights[i];
            while(s.top()>-1 && heights[s.top()]>=num){
                s.pop();
            }   
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(int* heights,int n) {
        vector<int> next;
        next=nextSmaller(heights,n);
        vector<int> prev;
        prev=beforeSmaller(heights,n);
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            int length=heights[i];
            int h=next[i];
            int p=prev[i];
            if (next[i]==-1){
                h=n;
            }
            int breadth=h-p-1;
            int area=length*breadth;
            ans=max(ans,area);
        }
        return ans;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
       int area=largestRectangleArea(M[0],m);
       
       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){
               if(M[i][j]!=0){
               M[i][j]=M[i][j]+M[i-1][j];
               }else{
                   M[i][j]=0;
               }
           }
        area=max(area,largestRectangleArea(M[i],m));
       }
       return area;
    }
};


----------------------------------------------------------------------------------------
//Design a stack that supports getMin() in O(1) time and O(1) extra space

#include<stack>
class SpecialStack {
   stack<int> s;
   int mini;
    public:
        
    void push(int data) {
       if (s.empty()){
           s.push(data);
           mini=data;
       }else{
           if(data<mini){
               s.push(2*data-mini);
               mini=data;
           }else{
               s.push(data);
           }
       }
    }

    void pop() {
       if(s.empty()){
           return;
       }else{
           if(s.top()>mini){
               s.pop();
           }else{
               mini=2*mini-s.top();
               s.pop();
           }
       }
    }

    int top() {
       if(s.empty()){
           return -1;
       }else{
           if (s.top()>mini){
               return s.top();
           }else{
               return mini;
           }
       }
    }

    int getMin() {
        if(s.empty()) return -1;
      return mini;
    }  
};

--------------------------------------------------------------------------------------------
// N Stacks In An Array
#include <bits/stdc++.h> 
class NStack
{
    int* arr;
    int* top;
    int* next;
    int freespot;
    int n,s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        this->n=N;
        this->s=S;
        this->freespot=0;
        this->arr=new int[s];
        this->top=new int[n];
        this->next=new int[s];
        for (int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<s;i++){
           next[i]=i+1;
        }
        next[s-1]=-1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot==-1){
            return false;
        }
        int index=freespot;
        this->arr[index]=x;
        freespot=next[index];
        next[index]=top[m-1];
        top[m-1]=index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1){
            return -1;
        }
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};

------------------------------------------------------------------------------------------------------