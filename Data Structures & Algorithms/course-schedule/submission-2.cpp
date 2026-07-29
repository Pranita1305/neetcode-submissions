class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);

        vector<vector<int>> adj(numCourses);

        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfs(i,adj,visited)) return false;
            }
        }

        return true;
    }

    bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=1;

        for(int neigh:adj[node]){
            if(visited[neigh]==1) return true;

            if(visited[neigh]==0){
                if(dfs(neigh,adj,visited)) return true;
            }
        }

        visited[node]=2;

        return false;

    }
};
