class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);

        if(dfs(visited,adj,0, -1)) return false;

        for(bool v : visited) if(!v) return false;

        return true;
    }

    bool dfs(vector<bool>& visited, vector<vector<int>>& adj, int source, int parent){
	    visited[source]=true;
	
	    for(int neigh:adj[source]){
		    if(!visited[neigh]){
			    if(dfs(visited,adj,neigh,source)){
				    return true;
			    }
		    }
		    else if(neigh != parent) return true;
	    }
	
	    return false;
    }
};