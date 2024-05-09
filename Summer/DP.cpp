3075 Maximize happiness of given children 

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long a=0;

        sort(happiness.begin(),happiness.end());
        int n=happiness.size();
        int decremented=0;
        for(int i=n-1;i>n-k-1;i--){
            a+=max(0,happiness[i]-decremented);
            decremented++;
        }

        return a;
    }
};

3.longest substring without repeating character 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r]];
      while (count[s[r]] > 1)
        --count[s[l++]];
      ans = max(ans, r - l + 1);
    }

    return ans;
    
    }
};

98:VALIDATE BST 
class Solution {
    private:
  bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (root == nullptr)
      return true;
    if (minNode && root->val <= minNode->val)
      return false;
    if (maxNode && root->val >= maxNode->val)
      return false;

    return isValidBST(root->left, minNode, root) &&
           isValidBST(root->right, root, maxNode);
  }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);

    }
};

61:ROTATE LIST 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0)
      return head;

    ListNode* tail;
    int length = 1;
    for (tail = head; tail->next; tail = tail->next)
      ++length;
    tail->next = head;  // Circle the list.

    const int t = length - k % length;
    for (int i = 0; i < t; ++i)
      tail = tail->next;
    ListNode* newHead = tail->next;
    tail->next = nullptr;

    return newHead;
    }
};

100:SAME TREE  
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL){
            return true;
        }
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL)){
            return false;
        }

        bool left=isSameTree(p->left,q->left);

        bool right=isSameTree(p->right,q->right);

        if(right && left && p->val==q->val){
            return true;
        }else{
            return false;
        }

    }
};

94:INORDER TRAVERSAL 

class Solution {
    private:
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

99:RECOVER BST  

class Solution {
    private:
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void in(TreeNode* root,vector<int> &ans,int &i){
        if(root==NULL){
            return;
        }

        in(root->left,ans,i);
        root->val=ans[i];
        i++;
        in(root->right,ans,i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        sort(ans.begin(),ans.end());
        int i=0;
        in(root,ans,i);
    }
};

102:LEVEL ORDER TRAVERSAL

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
    }

    return ans;
    }
};

19: Remove nth element from list 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
    ListNode* fast = head;

    while (n--)
      fast = fast->next;
    if (fast == nullptr)
      return head->next;

    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next->next;

    return head;
       
    }
};

66:PLUS ONE 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            for (int i = digits.size() - 1; i >= 0; --i) {
      if (digits[i] < 9) {
        ++digits[i];
        return digits;
      }
      digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
    }
};
