class Solution {
public:
    string makeGood(string s) {
        int n=s.length();

        for(int i=0;i<n-1;){
            if(s[i]-'a'==s[i+1]-'A' || s[i]-'A'==s[i+1]-'a'){
                s.erase(i,2);
                if(i>0) i--;
            }else{
                i++;
            }
        }
        return s;
    }
};