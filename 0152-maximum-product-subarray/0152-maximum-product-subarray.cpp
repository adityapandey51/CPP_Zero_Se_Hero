class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ans=nums[0];
    int mini=nums[0];  
    int maxi=nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      const int num = nums[i];
      const int prevMin = mini;
      const int prevMax = maxi;
      if (num < 0) {
        mini = min(prevMax * num, num);
        maxi = max(prevMin * num, num);
      } else {
        mini = min(prevMin * num, num);
        maxi = max(prevMax * num, num);
      }
      ans = max(ans, maxi);
    }

    return ans;
  }
};