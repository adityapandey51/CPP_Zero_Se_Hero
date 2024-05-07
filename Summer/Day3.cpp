#include <iostream>
#include <unordered_map>
#include<list>
using namespace std;
class graph{

    public:
    unordered_map<int,list<int>> adj;


    void insert(int node1, int node2,bool directional){
        adj[node1].push_back(node2);

        if(directional==1){
            adj[node2].push_back(node1);
        }
    }

    void printAdj(unordered_map<int,list<int>> adj){
        for(auto i:adj){
            cout<< i.first << " -> "<<;
            for(auto j:i.second){
                cout<< j<<" ,"<<;
            }
            cout<< endl;
        }
    }
};

// print adjancy list --coding studio
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){

            adj[i].push_back(i);
        }


        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        };

        return adj;

}

//2816
//Double the number represented as a linked list
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head->val>=5){
            head=new ListNode(0,head);
        }

        for(ListNode* curr=head;curr!=NULL;curr=curr->next){
            curr->val=curr->val*2;
            curr->val=curr->val%10;

            if(curr->next && curr->next->val>=5){
                curr->val++;
            }
        }
        return head;
    }
};
// ............................................................................................................

//BFS-Breadth first search--O(N+E)

#include <queue>
#include<unordered_map>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans(n);


    queue<int> q;
    unordered_map<int,bool> mp;

    for(int i=0;i<n;i++){
        mp[i]=false;
    }

    q.push(0);
    mp[0]=true;

    while(!q.empty()){
        int top=q.front();
        ans.push_back(top);
        q.pop();
        for(int i=0;i<adj[top].size();i++){
           
                if(!mp[adj[top][i]]){
                    q.push(adj[top][i]);
                    mp[adj[top][i]]=true;
                }
        }
    }

    return ans;
}

//DEPTH FIRST SEARCH 

void solve(int i,vector<vector<int>> &adj,unordered_map<int,bool> &mp,  vector<int> &ans){
    mp[i]=true;
    ans.push_back(i);

    for(auto j:adj[i]){
        if(!mp[j]){
            solve(j,adj,mp,ans);
        }
    }
}

vector<int> dfs(int n, vector<vector<int>> &adj){
    vector<int> ans(n);
    unordered_map<int,bool> mp;

     for(int i=0;i<n;i++){
        mp[i]=false;
    }

    for (int i=0;i<n;i++){
        if(!mp[i]){
            solve(i,adj,mp,ans);
        }
    }
    return ans;
}


/// cycle detection using bfs
 
bool isCyclicBFS(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, int Node) {
    unordered_map<int, int> parent;
    parent[Node] = -1;
    visited[Node] = true;

    queue<int> Q;
    Q.push(Node);

    while(!Q.empty()) {
        int FrontVal = Q.front();
        Q.pop();

        for(int i : adjList[FrontVal]) {
            if(visited[i] == true && parent[FrontVal] != i) {
                return true;
            }

            if(visited[i] == false) {
                visited[i] = true;
                parent[i] = FrontVal;
                Q.push(i);
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int> > &edges, int n, int m) {
    unordered_map<int, list<int> > adjList;
    unordered_map<int, bool> visited;

    // Creating Adjacency List
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            bool ans = isCyclicBFS(adjList, visited, i);
            
            if(ans) {
                return "YES";
            }
        }
    }

    return "NO";
}

//cycle detection using dfs

bool isCyclicDFS(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, int Node, int parent) {
    visited[Node] = true;

    for(auto i : adjList[Node]) {
        if(visited[i] == false) {
            bool isCycle = isCyclicDFS(adjList, visited, i, Node);

            if(isCycle) {
                return true;
            }
        } else if(i != parent) {
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int> > &edges, int n, int m) {
    unordered_map<int, list<int> > adjList;
    unordered_map<int, bool> visited;

    // Creating Adjacency List
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            bool ans = isCyclicDFS(adjList, visited, i, -1);
            
            if(ans) {
                return "YES";
            }
        }
    }

    return "NO";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Directed cyclic using DFS

bool isCyclicDFS(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, int Node, unordered_map<int,bool> &dfsVisited) {
    visited[Node] = true;
    dfsVisited[Node]=true;

    for(auto i : adjList[Node]) {
        if(visited[i] == false) {
            bool isCycle = isCyclicDFS(adjList, visited, i, dfsVisited);

            if(isCycle) {
                return true;
            }
        } else if(dfsVisited[i]) {
            return true;
        }
    }
    dfsVisited[Node]=false;
    return false;
}



string cycleDetection(vector<vector<int> > &edges, int n, int m) {
    unordered_map<int, list<int> > adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;


    // Creating Adjacency List
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            bool ans = isCyclicDFS(adjList, visited, i, dfsVisited);
            
            if(ans) {
                return "YES";
            }
        }
    }

    return "NO";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TOPOLOGICAL SORT
//only on directed acyclic graph

#include <bits/stdc++.h> 

void dfs(int src,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){
    visited[src]=true;

    for(auto i:adj[src]){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }
    s.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   unordered_map<int,list<int>> adj;
   for(auto i:edges){
       int x=i[0];
       int y=i[1];

       adj[x].push_back(y);
   };

   vector<bool> visited(v,0);
   stack<int> s;
   vector<int> ans;

   for(int i=0;i<v;i++){
       if(!visited[i]){
           dfs(i,visited,s,adj);
       }
   }

   while(!s.empty()){
       ans.push_back(s.top());
       s.pop();
   }
   return ans;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//KAHN'S ALGORITHM

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,list<int>> adj;
   for(auto i:edges){
       int x=i[0];
       int y=i[1];

       adj[x].push_back(y);
   };
   vector<int> inDeg(v);
    queue<int> q;
   for(int i=0;i<v;i++){
    int cnt=0;
    for(int j=0;j<e;j++){
        if(edges[j][1]==i){
            cnt++;
        }
    }
    if(cnt==0){
        q.push(i);
    }
    inDeg[i]=cnt;
   }

   vector<int> ans;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            inDeg[i]--;
            if(inDeg[i]==0){
                q.push(i);
            }
        }
    }

   return ans;

}
