class Solution {
public:
    int largestVariance(string s) {
        int l=s.length();
        unordered_set<char> st(s.begin(),s.end());
        int ans=INT_MIN;

        for(char ch='a';ch<='z';ch++){
            for(char cha='a';cha<='z';cha++){
                if(st.find(ch)==st.end() || st.find(cha)==st.end())
                    continue;
                int f1=0;
                int f2=0;
                bool pastseen=false;

                for(int i=0;i<l;i++){
                    if(s[i]==ch)
                        f1++;
                    if(s[i]==cha)
                        f2++;

                    if(f2>f1){
                        f1=0;
                        f2=0;
                        pastseen=true;                        
                    }
                    if(f2==0){
                        ans=max(ans,f1-1);
                    }

                    if(f2>0)
                        ans=max(ans,f1-f2);
                    
                }
            }
        }
        return ans;
    }
};