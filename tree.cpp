#include<iostream>
#include<queue>
using namespace std;

//creation of binary tree;

class node{
    
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data=data;
            this->right=NULL;
            this->left=NULL;
        }
};

node* buildTree(node* root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if (data==-1){
        return NULL;
    }

    cout<<"enter data for left child"<<endl;
    root->left=buildTree(root->left);

    cout<<"enter data for right child"<< endl;
    root->right=buildTree(root->right);

    return root;
};

-------------------------------------------------------------------------------------------------
// level order traversal==breadth first search

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
        }else{
             cout<<temp->data;
        }      
        q.pop();
        if(temp==NULL){
            q.push(NULL);
        }else{
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }      
    }
}

------------------------------------------------------------------------------------------------
Inorder Traversal
===LNR

void inorder(node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

--------------------------------------------------------------------------------------------------
PreOrder Traversal
===NLR

void preOrder(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

-----------------------------------------------------------------------------------------------------
PosrOrder Traversal
===LRN
void postOrder(node* root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;

}

---------------------------------------------------------------------------------------------------------

build from levelOrderTraversal

node* buildFromLevelOrderTraversal(node* root){
    cout<<"enter the root data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"enter the leftdata of "<<temp->data<<endl;
        int leftdata
        cin<<leftdata;
        if(leftdata!=-1){
            temp->left=new node(data);
            q.push(temp->left);
        }
        cout<<"enter the rightdata of "<<temp->data<<endl;
        int rightdata;
        cin<<rightdata;
        if(rightdata!=-1){
            temp->right=new node(data);
            q.push(temp->right);
        }
    }
}

--------------------------------------------------------------------------------------------------
COUNT LEAF NODES

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

int countleaf(BinaryTreeNode<int> *root,int count){
    if(root==NULL){
        return count;
    }
    if(root->left==NULL && root->right==NULL){
        count++;
        return count;
    };

    int leftleaf=countleaf(root->left,count);
    int rightleaf=countleaf(root->right,count);
    count+=leftleaf+rightleaf;
    return count;
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    return countleaf(root,count);
}

------------------------------------------------------------------------------------------------------
HEIGHT OF TREE:

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    private:
    int hello(struct Node* node,int count){
        if(node==NULL){
            return count;
        }
       int leftcount=hello(node->left,count);
       int rightcount=hello(node->right,count);
       return max(leftcount,rightcount)+1;
    }
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
       int count=0;
       return hello(node,count);
    }
};

----------------------------------------------------------------------------------------------------
CHECK BALANCED TREE OR NOT 

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    private:
    pair<bool,int> isBalancedFast(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left=isBalancedFast(root->left);
        pair<bool,int> right=isBalancedFast(root->right);
        
        bool left_bal=left.first;
        bool right_bal=right.first;
        bool curr_bal=abs(left.second-right.second)<=1;
        pair<bool,int> p;
        p.second=max(left.second,right.second)+1;
        if(left_bal && right_bal && curr_bal){
            p.first=true;
        }else{
            p.first=false;
        }
        return p;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};
-----------------------------------------------------------------------------------------------
DIAMETER OF BINARY TREE

class Solution {
    private:
    pair<int,int> diameterFast(Node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> right=diameterFast(root->right);
        int leftc=left.first;
        int rightc=right.first;
        int height=left.second+right.second+1;
        
        
        pair<int,int> p;
        p.first=max(leftc,max(rightc,height));
        p.second=max(left.second,right.second)+1;
        return p;
        
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       return diameterFast(root).first;
    }
};

-------------------------------------------------------------------------------------------------

DETERMINE IF TWO TREES ARE EQUAL

/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1!=NULL ^ r2!=NULL){
            return false;
        }
        
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        bool curr=(r1->data==r2->data);
        if(left && right && curr){
            return true;
        }else{
            return false;
        }
    }
};

--------------------------------------------------------------------------------------------------
IS GIVEN TREE A SUM TREE

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool,int> sum(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left=sum(root->left);
        pair<bool,int> right=sum(root->right);
        
        int leftSum=left.second;
        int rightSum=right.second;
        bool leftTree=left.first;
        bool rightTree=right.first;
        bool currTree=root->data==leftSum+rightSum;
        pair<bool,int> ans;
        if(leftTree && rightTree && currTree){
            ans.first=true;
            ans.second=2*root->data;
        }else{
            ans.first=false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        return sum(root).first;
    }
};

-------------------------------------------------------------------------------------------------------
                        ZIG ZAG TRAVERSAL==SPIRAL TRAVERSAL

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToRight=true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                Node* frontNode=q.front();
                q.pop();
                
                int index=leftToRight?i:size-i-1;
                ans[index]=frontNode->data;
                
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                
            }
            
            leftToRight=!leftToRight;
            
            for(auto i:ans){
                result.push_back(i);
            }
        }
        return result;
    }
};
-----------------------------------------------------------------------------------------------------
BOUNDARY TRAVERSAL OF BINARY TREE

class Solution {
private:
    void traverseLeft(Node* root,vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL))
                return;
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left,ans);
        }else{
            traverseLeft(root->right,ans);
        }
    }
    void traverseRight(Node* root , vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL))
                return;
        if(root->right){
            traverseRight(root->right,ans);
        }else{
            traverseRight(root->left,ans);
        }
        
        ans.push_back(root->data);
    }
    
    void leafTraverse(Node* root , vector<int> &ans){
        if (root==NULL) return;
        if (root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
    }
public:
    vector <int> boundary(Node *root)
    {
      vector<int> ans;
      if(root==NULL){
          return ans;
      }
      ans.push_back(root->data);
      
      traverseLeft(root->left,ans);
      leafTraverse(root->left,ans);
      leafTraverse(root->right,ans);
      traverseRight(root->right,ans);
      
      return ans;
    }
};
---------------------------------------------------------------------------------------------------
VERTICAL TRAVERSAL OF BINARY TREE

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int> > > nodes;
        queue<pair<Node*,pair<int,int> > > q;
        
         vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            nodes[hd][lvl].push_back(frontNode->data);
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
            if(frontNode->right) 
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        for(auto i: nodes) {
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
        
    }
};

----------------------------------------------------------------------------------------------------
TOP VIEW

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD, then do nothing
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode -> data;
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
    }

};

-------------------------------------------------------------------------------------------------------
BOTTOM VIEW

class Solution {
  public:
    vector <int> bottomView(Node *root) {
         vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            topNode[hd] = frontNode -> data;
                
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
--------------------------------------------------------------------------------------------------

RIGHT VIEW
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->right, ans, level+1);    
    solve(root->left, ans, level+1);
    
}
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------
LEFT VIEW

void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, level+1);    
    solve(root->right, ans, level+1);
    
}
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }

-----------------------------------------------------------------------------------------------------
DIAGONAL PRINT

void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same 
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical 
    // distance if left child
    diagonalPrintUtil(root->left, 
                      d + 1, diagonalPrint);
 
    // Vertical distance remains 
    // same for right child
    diagonalPrintUtil(root->right, 
                         d, diagonalPrint);
}

void diagonalPrint(Node* root)
{
     
    // create a map of vectors 
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
     vector<int> ans;
    if (root==NULL){
        return ans;
    }
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          ans.push_back(it);
    }
}
--------------------------------------------------------------------------------------------------------

LONGEST SUM IN THE BLOODLINE

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
private:
   pair<int,int> solve(Node* root,int sum,int count){
       if(root==NULL){
           pair<int,int> p=make_pair(0,0);
           return p;
       }
       
       pair<int,int> left=solve(root->left,sum,count);
       pair<int,int> right=solve(root->right,sum,count);
       
       pair<int,int> ans;
       ans.second=max(left.second,right.second)+1;
       if(left.second==right.second){
           ans.first=max(left.first,right.first)+root->data;
       }else if(max(left.second,right.second)==left.second && left.second!=right.second){
            ans.first=left.first+root->data;
       }else{
           ans.first=right.first+root->data;
       }
       return ans;
   }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int count = 0;
        int sum = 0;
        
        return solve(root,sum,count).first;
    }
};
-----------------------------------------------------------------------------------------------------
LOWEST COMMON ANCESTOR

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2) 
        {
            return root;
        }
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL) 
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
};

------------------------------------------------------------------------------------------------------
K sum paths

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};
------------------------------------------------------------------------------------------------------
k sum paths

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};
-----------------------------------------------------------------------------------------------------------

kth ancestor
Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}
----------------------------------------------------------------------------------------------------------
GET MAX SUM

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
-----------------------------------------------------------------------------------------------------------