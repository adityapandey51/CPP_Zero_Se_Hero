KOSARAJU ALGO  -O(N+E)


#include<unordered_map>
#include<list>
#include<stack>

void dfs(int i,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){

	visited[i]=1;

	for(auto j:adj[i]){
		if(!visited[j]){
			dfs(j,visited,s,adj);
		}
	}

	s.push(i);
}

void dfs(int i,vector<bool> &visited,unordered_map<int,list<int>> &adj){
	visited[i]=1;

	for(auto j:adj[i]){
		if(!visited[j]){
			dfs(j,visited,adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;
	for(auto i:edges){
		adj[i[0]].push_back(i[1]);
	}

	stack<int> s;
	vector<bool> visited(v,0);

	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,visited,s,adj);
		}
	}

	unordered_map<int,list<int>> adj2;
	for(auto i:edges){
		adj2[i[1]].push_back(i[0]);
	}
	for(int i=0;i<v;i++){
		visited[i]=0;
	}

	int count=0;
	while(!s.empty()){
		int top=s.top();
		s.pop();
		if(!visited[top]){
			count++;
			dfs(top,visited,adj2);
		}
	}

	return count;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

BELLMAN FORD -O(N*M)


vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> distance(n+1, 1e8);
    distance[src] = 0;

    for(int i=1; i<=n; i++) {
        
        for(int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u]!=1e8 && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }

    }

    for(int j=0; j<m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(distance[u] + w < distance[v]) {
            return vector<int> (n, 1e8);
        }
    }

    return distance;
}