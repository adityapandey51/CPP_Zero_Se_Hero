class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l=s.length();

        for(int i=0;i<l/2;i++){
            bool ans=true;
            string sub=s.substr(0,i+1);
            for(int j=i+1;j<l;j+=sub.length()){
                string sub2=s.substr(j,sub.length());
                if(sub2!=sub){
                    ans=false;
                }
            }
            if(ans==true)
                return true;
        }
        return false;
    }
};