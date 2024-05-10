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


8:String to integer

class Solution {
    private:
    void trim(string& s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
  }
public:
    int myAtoi(string s) {
       trim(s);
        if (s.empty())
            return 0;

        const int sign = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        long num = 0;

        for (const char c : s) {
            if (!isdigit(c))
                break;
            num = num * 10 + (c - '0');
             if (sign * num < INT_MIN)
                return INT_MIN;
            if (sign * num > INT_MAX)
                return INT_MAX;
        }

    return sign * num;
  }

};

67: ADD BINARY 

class Solution {
public:
    string addBinary(string a, string b) {
          string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
             if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//103:Zig zag traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        
        while(!q.empty()){
            
            int size=q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                
                int index=leftToRight?i:size-i-1;
                ans[index]=frontNode->val;
                
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                
            }
            
            leftToRight=!leftToRight;
            
            
            result.push_back(ans);
        }
        return result;
    }
};

136:SINGLE NUMBER

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};

105: Build from inorder and preorder

class Solution {
    private:
    void createMapping(vector<int> in, int n, map<int,int> &nodeToIndex){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    TreeNode* constructTree(vector<int> in, vector<int> pre, int inOrderStart, int inOrderEnd, int &index, map<int,int> &nodeToIndex, int size){
        if(index >= size || inOrderStart > inOrderEnd){
            return NULL;
        }
        int temp = pre[index++];
        TreeNode* root = new TreeNode(temp);
        int pos = nodeToIndex[temp];
        
        root->left = constructTree(in, pre, inOrderStart, pos-1, index, nodeToIndex, size);
        root->right = constructTree(in, pre, pos+1, inOrderEnd, index, nodeToIndex, size);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> nodeToIndex;
        createMapping(inorder, inorder.size(), nodeToIndex);
        
        int index = 0;
       
        TreeNode* ans = constructTree(inorder, preorder, 0, inorder.size()-1, index, nodeToIndex, inorder.size());
        return ans;
    }
};

110:Balanced binary tree 

class Solution {

private:
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }

        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);

        pair<int,bool> ans;
        ans.first=max(left.first,right.first)+1;
        ans.second=(abs(left.first-right.first)<=1) && left.second && right.second;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
       pair<int,bool> ans;

       ans=solve(root);

       return ans.second;


    }
};

108:Convert sorted array into BST 
class Solution {

private:
TreeNode* build(const vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    const int m = (l + r) / 2;
    return new TreeNode(nums[m], build(nums, l, m - 1), build(nums, m + 1, r));
  }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return build(nums, 0, nums.size() - 1);
    }
};
