#include <iostream>
#include <unordered_map>
using namespace std;
//3005: Count elements with maximum frequency
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
        }
        int ans=0;
        for(auto i:mp){
            if(maxi==i.second)
                ans+=i.second;
        }

        return ans;
    }
};

//208. Implement Trie (Prefix Tree)

class TrieNode{
    public:
    int data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(int data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';

        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }

     bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    
    bool search(string word) {
        return searchUtil(root,word);
    }

    bool starts(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }

        return starts(child,word.substr(1));
    }

    
    bool startsWith(string prefix) {
        return starts(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


//14 longest common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs[0].length()==0) return "";
        string ans="";
        bool matched=true;

        for (int i=0;i<strs[0].length();i++){
            char ch=strs[0][i];
            for (int j=1;j<strs.size();j++){
                if(i>=strs[j].length()||strs[j][i]!=strs[0][i]){
                    matched=false;
                    break;
                }
            }
            if (matched==false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

// BacKtracking
//Rat in a maze problem
class Solution{
    bool isSafe(int newX,int newY, int n,vector<vector<int>> m,vector<vector<bool>> &visited){
        if((newX < n && newX>=0) && (newY < n && newY>=0) && visited[newX][newY]!=1 && m[newX][newY]==1){
            return true;
        }else{
            return false;
        }
    }
    void solve(int x,int y,vector<vector<int>> m,int n,vector<vector<bool>> &visited,vector<string> &ans, string path){
        if (x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y]=1;
        
        if(isSafe(x+1,y,n,m,visited)){
            
            solve(x+1,y,m,n,visited,ans,path+'D');
        }
        if(isSafe(x,y-1,n,m,visited)){
            
            solve(x,y-1,m,n,visited,ans,path+'L');
        }
        if(isSafe(x,y+1,n,m,visited)){
            
            solve(x,y+1,m,n,visited,ans,path+'R');
        }
        if(isSafe(x-1,y,n,m,visited)){
           
            solve(x-1,y,m,n,visited,ans,path+'U');
        }
        
        visited[x][y]=0;
        
        
        
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string path="";
        vector<vector<bool>> visited(n,vector<bool> (n,0));
        
        if(m[0][0]!=1){
            return ans;
        }
        
        solve(0,0,m,n,visited,ans,path);
        return ans;
    }
};

//51:N Queens
class Solution {
private:
    void addSolution(vector<vector<int>> &board,vector<vector<string>> &ans,int n){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    tmp+='Q';
                }else{
                    tmp+='.';
                }
            }
            temp.push_back(tmp);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row,int col,vector<vector<int>> &board,int n){
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
            x--;
        }

        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
            x++;
        }

        return true;

    }
    void solve(int col,vector<vector<int>> &board,vector<vector<string>> &ans, int n){
        if (col==n){
            addSolution(board,ans,n);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]=1;
                solve(col+1,board,ans,n);
                board[i][col]=0;
            }

        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int> (n,0));
        vector<vector<string>> ans;
        int col = 0;

        solve(col,board,ans,n);

        return ans;
    }
};
//-------------------------------------------------------------------------------------------------------

//TRIE

class TrieNode{
    public:
    int data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(int data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
    public: 
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'A';

        TrieNode* child;

        if(root -> children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }

    void insertString(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }


    bool searchString(string word){
        return searchUtil(root,word);
    }

    void deleteUtil(TrieNode* root, string word){
        if (word.length()==0){
            if(root->isTerminal){
                root->isTerminal=false;
            }
            else{
                cout<<"word does'nt exist"<< endl;
            }
            return;
        }

        int index=word[0]-'A';

        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            cout<<"word does'nt exist"<< endl;
            return ;
        }
        deleteUtil(child,word.substr(1));
        delete child;
        return;
    }

    void deleteString(string word){
        deleteUtil(root,word);
    }

};