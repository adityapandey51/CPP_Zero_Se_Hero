//0-1 Knapsack

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1,vector<int>(w+1));

	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
		}
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(weights[i-1]<=j){
				dp[i][j]=max((values[i-1]+dp[i-1][j-weights[i-1]]),dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][w];
}


104:Maximum depth of binary tree 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return max(left,right)+1;
    }
};

86:Partition List 

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         ListNode beforeHead(0);
    ListNode afterHead(0);
    ListNode* before = &beforeHead;
    ListNode* after = &afterHead;

    for (; head; head = head->next)
      if (head->val < x) {
        before->next = head;
        before = head;
      } else {
        after->next = head;
        after = head;
      }

    after->next = nullptr;
    before->next = afterHead.next;

    return beforeHead.next;
    }
};

111:Minimum depth of a binarytree 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }else if(root->left!=NULL && root->right==NULL){
            return minDepth(root->left)+1;
        }else if(root->left==NULL && root->right!=NULL){
            return minDepth(root->right)+1;
        }else{
            return min(minDepth(root->left),minDepth(root->right))+1;
        }

    }
};

506:Relative ranks

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        set<pair<int,int>> s;
        for(int i=0;i<score.size();i++){
            s.insert(make_pair(score[i],i));
        }
        
        int n=score.size();
        vector<string> ans(n);
        while(!s.empty()){
            auto top=*(s.begin());
            s.erase(top);
            string pos=to_string(n);
            if(n==3){
                pos="Bronze Medal";
            }else if(n==2){
                pos="Silver Medal";
            }else if(n==1){
                pos="Gold Medal";
            }
            ans[top.second]=pos;
            n--;
        }
        return ans;
    }
};

203:Remove Linked List elements

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode ans(0);
        ListNode* after=&ans;

        for(;head;head=head->next){
            if(head->val!=val){
                after->next=head;
                after=after->next;    
            }else if(head->val==val){
                after->next=head->next;
            }
        }
        return ans.next;
    }
};

215:Kth largest element in an array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;

        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }

        for(int i=0;i<k-1;i++){
            q.pop();
        }
        

        return (q.top());
    }
};

81:Search in a rotated sorted array 2

class Solution {

private: 
    int pivot(vector<int> nums){
        int i=0;
        while(i+1<=nums.size()-1 && nums[i]<=nums[i+1]){
            i++;
        }
        return i;
    }

    bool BinarySearch(vector<int>& nums,int s, int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]>target){
                e=mid-1;
            }else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                return true;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int p=pivot(nums);

        if(p+1<=nums.size()-1 && target>= nums[p+1] && target<=nums[nums.size()-1]){
            return BinarySearch(nums,p+1,nums.size()-1,target);
        }else{
            return BinarySearch(nums,0,p,target);
        }

    }
};

303:RangeSum query-immutable

class NumArray {
        vector<int> p;
public:
    NumArray(vector<int>& nums) {
        p.resize(nums.size()+1);
        p[0]=0;
        for(int i=0;i<nums.size();i++){
            p[i+1]=p[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return (p[right+1]-p[left]);
    }
};


169.Majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans;
         for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>nums.size()/2){
                ans=nums[i];
            }
        }
    return ans;
    }
};

229:Majority element 2

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int> mp;
         int n=int(nums.size()/3)+1;

        vector<int> ans;
         for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==n){
                ans.push_back(nums[i]);
            }
        }
    return ans;
    }
};

31:Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int index=-1;
       for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index=i;
            break;
        }
       }

       if(index==-1){
        reverse(nums.begin(),nums.end());
        return;
       }

       for(int i=nums.size()-1;i>index;i--){
        if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
       }

       reverse(nums.begin()+index+1,nums.end());
    }
};

1838:Frequency of the most frequent element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        sort(nums.begin(),nums.end());

        long sum=0;
        int ans=0;

        while(l<nums.size() && r<nums.size()){
            sum=sum+nums[r];

            while(static_cast<long>(nums[r])*(r-l+1) > sum+k){
                sum=sum-nums[l];
                l++;
            }

            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

56:Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(int i=0;i<intervals.size();i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};

287:Find the duplicate number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                ans=nums[i];
                break;
            }
        }
        return ans;
        
    }
};

118:PasCal triangle

class Solution {
private:
    vector<int> getRow(int row){
        vector<int> ans;
        long long temp=1;

        ans.push_back(temp);
        for(int i=1;i<row;i++){
            temp=temp*(row-i);
            temp=temp/i;
            ans.push_back(temp);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1;i<=numRows;i++){
            ans.push_back(getRow(i));
        }
        return ans;
    }
};

62:Unique paths

class Solution {
    private:
     int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
};