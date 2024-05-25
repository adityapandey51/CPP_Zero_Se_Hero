70.climbing stairs 
class Solution {
    
public:
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
       
    }
};

416.Partition equal subset sum 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum&1){
            return false;
        }
        vector<vector<bool>> dp(nums.size()+1,vector<bool> (sum/2+1));

        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<sum/2+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }

        for(int i=1;i<nums.size()+1;i++){
            for(int j=1;j<sum/2+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[nums.size()][sum/2];
    }
};


322:COIN CHANGE 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1));

        for(int i=0;i<coins.size()+1;i++){
            for(int j=0;j<amount+1;j++){
                if(j==0)
                dp[i][j]=0;
                if(i==0)
                dp[i][j]=INT_MAX-1;  
                if (i==1){
                    if(j%coins[0]==0){
                        dp[i][j]=j/coins[0];
                    }else{
                        dp[i][j]=INT_MAX-1;
                    }
                }           
            }
        }

        for(int i=2;i<coins.size()+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){

                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        int ans=dp[coins.size()][amount];

        return ans!=INT_MAX-1?ans:-1;
    }
};

1143:Longest common subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1));

        for(int i=0;i<text1.length()+1;i++){
            for(int j=0;j<text2.length()+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }

        for(int i=1;i<text1.length()+1;i++){
            for(int j=1;j<text2.length()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[text1.length()][text2.length()];
    }
};

53:Maximum subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=nums[0];

        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
        }

        return ranges::max(dp);
    }
};

392:isSubsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1));

        for(int i=0;i<s.length()+1;i++){
            for(int j=0;j<t.length()+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }

        for(int i=1;i<s.length()+1;i++){
            for(int j=1;j<t.length()+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        if(dp[s.length()][t.length()]==s.length()){
            return true;
        }
        return false;
    }
};

300:longest incresing subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       if (nums.empty())
      return 0;


    vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);

        return ranges::max(dp);
    }
};