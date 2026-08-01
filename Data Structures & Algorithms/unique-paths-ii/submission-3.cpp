class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        if(g[0][0] == 1 || g[m-1][n-1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        // First column
        for(int i=1;i<m;i++){
            if(g[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        }

        // First row
        for(int j=1;j<n;j++){
            if(g[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        }

        // Remaining cells
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(g[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
        
