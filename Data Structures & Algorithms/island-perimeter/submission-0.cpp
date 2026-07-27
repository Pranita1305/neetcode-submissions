class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>> q;
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2; 
                    found = true;
                }
            }
        }

        int perimeter = 0;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) {
                    perimeter++;
                } else if (grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }

        return perimeter;
    }
};