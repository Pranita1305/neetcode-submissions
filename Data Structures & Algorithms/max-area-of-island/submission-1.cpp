class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>> q;
        int max_area = 0;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                    int current_area = 1;
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (auto [dr, dc] : dirs) {
                            int nr = r + dr, nc = c + dc;

                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                                q.push({nr,nc});
                                grid[nr][nc]=0;
                                current_area++;
                            }
                        }
                    }
                    max_area = max(max_area, current_area);
                }
                
            }
        }
        

        return max_area;
    }
};