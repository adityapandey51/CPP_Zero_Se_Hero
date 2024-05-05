#include<iostream>
using namespace std;


//Question1:
//1373. Maximum Sum BST in Binary Tree
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};
class Solution {
private:
    info solve(TreeNode* root, int &maxSum){
        if(root==NULL){
            return {INT_MIN,INT_MAX,true,0};
        };
        info left=solve(root->left,maxSum);
        info right=solve(root->right,maxSum);
        info currNode;
        currNode.sum=left.sum+right.sum+root->val;
        currNode.maxi=max(root->val,right.maxi);
        currNode.mini=min(root->val,left.mini);

        if((root->val<right.mini && root->val>left.maxi) && left.isBST && right.isBST){
            currNode.isBST=true;
        }else{
            currNode.isBST=false;
        }

        if (currNode.isBST){
            maxSum=max(maxSum, currNode.sum);
        }
        return currNode;

    }
public:
    int maxSumBST(TreeNode* root) {
        int maxSum=0;
        info temp=solve(root,maxSum);
        return maxSum;
    }
};

//230.kth smallest element in bst
class Solution {
private:
    void solve(TreeNode* root,int k, int &cnt,int &ans){
        if (root==NULL){
            return;
        }
        solve(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
        }
        solve(root->right,k,cnt,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
        solve(root,k,cnt,ans);
        return ans;
    }
};

//958:Check completeness of a binary tree

class Solution {
private:
    int countNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return left+right+1;
    }
    bool solve(TreeNode* root,int h,int i){
        if(root==NULL){
            return true;
        }

        if(i>=h){
            return false;
        }
        else{
            bool left=solve(root->left,h,2*i+1);
            bool right=solve(root->right,h,2*i+2);
            return left && right;
        }
    };
public:
    bool isCompleteTree(TreeNode* root) {
        int h=countNodes(root);
        int i=0;
        bool ans=solve(root,h,i);
        return ans;
    }
};

//617: Merge Two binary trees
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
      return nullptr;
    const int val = (root1 == nullptr ? 0 : root1->val) +
                    (root2 == nullptr ? 0 : root2->val);
    TreeNode* root = new TreeNode(val);
    root->left = mergeTrees(root1 == nullptr ? nullptr : root1->left,
                            root2 == nullptr ? nullptr : root2->left);
    root->right = mergeTrees(root1 == nullptr ? nullptr : root1->right,
                             root2 == nullptr ? nullptr : root2->right);
    return root;
  }
};

//23: Merge K sorted arrays

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


 class Compare{
    public:

    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,Compare> minHeap;

        for(int i=0;i<lists.size();i++){
            if (lists[i] != nullptr)
            minHeap.push(lists[i]);
        }
        ListNode ans(0);
        ListNode* curr=&ans;
        while(!minHeap.empty()){         
          ListNode* minNode=minHeap.top();
          minHeap.pop();
          if(minNode && minNode->next){
            minHeap.push(minNode->next);
          }

          curr->next=minNode;
          curr=curr->next;
          
        }
        return ans.next;
    }
};
//------------------------------------------------------------------------------------------------

class Heap{
public: 
    int arr[100];
    int size;

    Heap(){
        arr[0]=-1;
        size=0;
    };

    // time complexity=O(logn)
    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=arr[index/2];
            if (parent<arr[index]){
                swap(arr[index],arr[index/2]);
                index=index/2;
            }else{
                return;
            }
        }

    };

    void deleteFromHeap(){
        if(size==0){
            cout<< "nothing to delete"<< endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        while(i<size){
            if(2*i<size && arr[i]<arr[2*i]){
                swap(arr[i],arr[2*i]);
                i=2*i;
            }else if(2*i+1<size && arr[i]<arr[2*i+1]){
                swap(arr[i],arr[2*i+1]);
                i=2*i+1;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i];
        }
    }
};

void heapify(int arr[],int n, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right <=n && arr[largest] < arr[right]){
        largest=right;
    }

    if(largest !=i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }

}

//O(nlogn)
void heapSort(int arr[],int n){
    if (n==0){
        cout<< "nothing to sort"<< endl;
        return;
    }

    for (int i=n;i>1;i--){
        swap(arr[1],arr[i]);
        heapify(arr,i-1,1);
    }

}

int main(){
    int arr[6]={-1, 54,53,55,52,50};
    int n=5;

    for(int i=n/2;i>0;i--){
        heapify(arr,n,i); 
    }

    heapSort(arr,n);
    for(int i=1;i<=n;i++){
            cout<<arr[i];
    }
}

