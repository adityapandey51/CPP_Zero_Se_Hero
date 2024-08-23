class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                if(strs[j][i]>strs[j+1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};