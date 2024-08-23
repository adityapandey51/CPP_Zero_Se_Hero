class Solution {
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' ||ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int count_left=0;
        int count_right=0;
        int n=s.length();
        int i=0,j=n/2;
        while(i<n/2 && j<n){
            if(isVowel(s[i]))
                count_left++;
            if(isVowel(s[j]))
                count_right++;
            i++;
            j++;
        }
        return count_left==count_right;
    }
};