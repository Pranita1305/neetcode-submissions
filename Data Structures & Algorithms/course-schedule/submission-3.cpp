class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int> visited(numCourses,0);

        vector<vector<int>> adj(numCourses);

        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        // for(int i=0;i<numCourses;i++){
        //     if(visited[i]==0){
        //         if(dfs(i,adj,visited)) return false;
        //     }
        // }

        // return true;
        vector<int> topo;
        queue<int> q;

        vector<int> Indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(int neigh:adj[i]) Indegree[neigh]++;
        }

        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0) q.push(i);
        }
        

        while(!q.empty()){
            int n=q.front();
            q.pop();
            topo.push_back(n);

            for(int neigh:adj[n]){
                Indegree[neigh]--;
                if(Indegree[neigh]==0) q.push(neigh);
            }
        }

        if(topo.size()==numCourses) return true;
        return false;
    }

    // bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited){
    //     visited[node]=1;

    //     for(int neigh:adj[node]){
    //         if(visited[neigh]==1) return true;

    //         if(visited[neigh]==0){
    //             if(dfs(neigh,adj,visited)) return true;
    //         }
    //     }

    //     visited[node]=2;

    //     return false;

    // }

    vector<int> topoSort(vector<vector<int>>& adj,int numCourses){
        
    }
};
