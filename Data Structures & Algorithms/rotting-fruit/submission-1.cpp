class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        int fresh=0;
        int time=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }

        while(fresh>0 && !q.empty()){
            int length=q.size();
            for(int i=0;i<length;i++){
                auto[r,c]=q.front();
                q.pop();

                for(auto[nr,nc]:dir){
                    int new_r=r+nr;
                    int new_c=c+nc;

                    if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && grid[new_r][new_c]==1){
                        grid[new_r][new_c]=2;
                        q.push({new_r,new_c});
                        fresh--;
                    }
                }
            }
            time++;
        }

        if(fresh!=0) return -1;
        return time;        
    }
};
