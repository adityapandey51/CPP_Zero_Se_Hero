class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int count_Caps=0;
        for(int i=0;i<n;i++){
            if(word[i]<'A' || word[i]>'Z') continue;
            count_Caps++;
        }

        if(count_Caps==0 || count_Caps==n || (count_Caps==1 && isupper(word[0]))){
            return true;
        }
        
        return false;
    }
};