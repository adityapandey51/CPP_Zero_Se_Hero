class Solution {
    bool checkFreq(string s){
        vector<int> freq(26,0);

        for(auto &ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a']>1)
                return true;
        }
        return false;
    }
public:
    bool buddyStrings(string s, string goal) {
        int m=s.length();
        int n=goal.length();

        if(m!=n) return false;

        if(s==goal){
            if(checkFreq(s))
                return true;
        }

        vector<int> pos_diffs;
        for(int i=0;i<m;i++){
            if(s[i]!=goal[i])
                pos_diffs.push_back(i);
        }

        if(pos_diffs.size()!=2)
            return false;
        
        swap(s[pos_diffs[0]],s[pos_diffs[1]]);

        return s==goal;
    }
};