//LEETCODE
128:longest consequtive sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        if (nums.size()==0){
            return 0;
        }

        int longest=1;
        int cnt;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        for(auto i:s){
            auto prev=s.find(i-1);
            if(prev!=s.end()){
                continue;
            }else{
                cnt=1;
                int x=i;
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x++;
                }
            }  
            longest =max(longest,cnt);     
        }
        return longest;
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//shortest path in an undirected graph

#include<unordered_map>
#include<list>
#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> adj;

	for(auto i:edges){
		int x=i.first;
		int y=i.second;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<int> q;
    unordered_map<int,bool> visited;
	unordered_map<int,int> parent;

	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
				parent[i]=front;
			    visited[i]=true;
			    q.push(i);
			}
		}
	}

	vector<int> ans;

	ans.push_back(t);

	while(parent[t]!=s){
		ans.push_back(parent[t]);
		t=parent[t];
	}
	ans.push_back(s);

	reverse(ans.begin(),ans.end());
	return ans;

	
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SHORTEST PATH IN A DIRECTED ACYCLIC GRAPH

#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<pair<int,int>> > AdjList;

        void addEdge(int u, int v, int weight) {
            AdjList[u].push_back(make_pair(v,weight));
        }

        void printEdge() {
            for(auto x : AdjList) {
                cout << x.first << " -> ";
                for(auto y : x.second) {
                    cout << y.first << "[" << y.second << "]  ";
                }
                cout << endl;
            }
        }

        void solveDFS(stack<int> &st, vector<int> &visited, int node) {
            visited[node] = 1;
            for(pair<int,int> neigh : AdjList[node]) {
                if(visited[neigh.first] == 0) {
                    solveDFS(st, visited, neigh.first);
                }
            }
            st.push(node);
        } 

        stack<int> topoSort() {
            stack<int> st;
            vector<int> visited(6,0);
            
            for(auto x : AdjList) {
                if(visited[x.first] == 0) {
                    solveDFS(st, visited, x.first);
                }
            }

            return st;
        }

        vector<int> shortestPath(int src) {
            vector<int> distance(6, INT_MAX);
            distance[src] = 0;
            stack<int> st = topoSort();

            while(!st.empty()) {
                int val = st.top();
                st.pop();

                if(distance[val] != INT_MAX) {
                    for(auto x : AdjList[val]) {
                        if(distance[val] + x.second < distance[x.first])
                            distance[x.first] = distance[val] + x.second;
                    }
                }
            }

            return distance;
        }
};

int main() {
    Graph G;

    G.addEdge(0, 1, 5);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 6);
    G.addEdge(0, 2, 3);
    G.addEdge(2, 3, 7);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(4, 5, -2);
    G.addEdge(2, 5, 2);

    // G.printEdge();

    vector<int> shot = G.shortestPath(1);

    for(auto x : shot) {
        if(x == INT_MAX) {
            cout << "INF" << " ";
        } else {
            cout << x << " ";
        }
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//DIJKSTRA ALGO--O(ElogV)

#include <bits/stdc++.h> 
#include<unordered_map>
#include<set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.


    unordered_map<int,list<pair<int,int>>> adj;

    for (int i=0;i<edges;i++){
        int x=vec[i][0];
        int y=vec[i][1];
        int z=vec[i][2];

        adj[x].push_back(make_pair(y,z));
        adj[y].push_back(make_pair(x,z));
    }

    set<pair<int,int>> s;
    vector<int> distance(vertices);
    for(int i=0;i<vertices;i++){
        distance[i]=INT_MAX;
    }
 

    distance[source]=0;
    s.insert(make_pair(0,source));

    while(!s.empty()){
        auto top=*(s.begin());
        s.erase(s.begin());
        for(auto i:adj[top.second]){
            if(top.first+i.second<distance[i.first]){
                auto record=s.find(make_pair(distance[i.first],i.first));
                if(record!=s.end()){
                    s.erase(record);
                }
                distance[i.first]=top.first+i.second;
                 s.insert(make_pair(distance[i.first],i.first));

            }
        }
    }

    return distance;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Prims algo: when u covert a graph into a tree with n nodes and n-1 edges 
//and each and every node is reachable by other node.

MST-minimum spanning tree: minimum weight of a spanning tree;

O(N2)-for this approach
using min heap it goes to O(NLOGN)


vector< pair<pair<int,int>, int> > calculatePrimsMST(vector< vector<int> > &edges, int n, int m) {
    // Creating adj list
    unordered_map< int, list<pair<int,int>> > adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    // Initiaising the required data structures
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    // Initialising src node
    key[0] = 0;
    
    for(int i=0; i<n; i++) {
        // Calculating minimum from key vector
        int u, mini = INT_MAX;
        for(int i=0; i<key.size(); i++) {
            if(key[i] < mini && mst[i] == false) {
                u = i;
                mini = key[i];
            }
        }

        mst[u] = true;

        for(pair<int,int> x : adjList[u]) {
            if(mst[x.first] == false && x.second < key[x.first]) {
                key[x.first] = x.second;
                parent[x.first] = u;
            }
        }
    }

    vector< pair<pair<int,int>, int> > answer;
    for(int i=1; i<n; i++) {
        answer.push_back({{parent[i], i}, key[i]});
    }

    return answer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
KRUSHKAL ALGO-O(NLOGN)

#include <bits/stdc++.h>
using namespace std;

// Writing own compare method to sort vector according to their 2nd index
bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int findParent(vector<int> &parent, int node) {
    // Reached topmost point of hierarchy
    if(parent[node] == node) {
        return node;
    }

    // Going upwards in hierarchy
    /*
        PATH COMPRESSION LOGIC :

        Assigning result to parent[node] to moving it up in
        the hierarchy to make it accessible easily from the top
    */
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int calculateKruskalsMST(vector< vector<int> > &edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n);

    // Initialising parent & rank
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sorting vector according to their weight
    sort(edges.begin(), edges.end(), compare);
    
    // Answer variable used to sum up the weights of nodes added in MST
    int minWeight = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v) {
            unionSet(u, v, parent, rank);
            minWeight += edges[i][2];
        }
    }

    return minWeight;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
BRIDGES IN Graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc,
    vector<int> &low, vector<vector<int>> &result,
    unordered_map<int, list<int>> &adjList, vector<bool> &visited) {

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neigh : adjList[node]) {
        if(neigh == parent) continue;

        if(visited[neigh] == false) {
            dfs(neigh, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[neigh]);

            // Check bridge edge
            if(low[neigh] > disc[node]) {
                result.push_back({node, neigh});
            }
        } else {
            // Back edge found
            low[node] = min(low[node], disc[neigh]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int m) {
    // Create adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int parent = -1;
    vector<bool> visited(n, false);
    vector<vector<int>> result;

    // DFS
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, parent, timer, disc, low, result, adjList, visited);
        }
    }

    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
ARTICULATION POINT

////////////////////////////////////////////////////////////////////////////////////////////////////////