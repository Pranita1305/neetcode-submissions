class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> Indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(int neigh:adj[i]) Indegree[neigh]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0)q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(int neigh:adj[node]){
                Indegree[neigh]--;

                if(Indegree[neigh]==0)q.push(neigh);
            }

        }

        if(topo.size()!=numCourses) topo.erase(topo.begin(),topo.end());
        return topo;
    }
};
