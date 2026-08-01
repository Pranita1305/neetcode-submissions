class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,0));

        // memo[m-1][n-1]=1;

        // for(int i=0;i<m;i++){
        //     memo[i][n-1]=1;
        // }
        // for(int i=0;i<n;i++){
        //     memo[m-1][i]=1;
        // }

        // for(int i=m-2;i>=0;i--){
        //     for(int j=n-2;j>=0;j--){
        //         memo[i][j]=memo[i][j+1]+memo[i+1][j];
        //     }
        // }

        // return memo[0][0];

        memo[0][0]=1;

        for(int i=0;i<n;i++){
            memo[0][i]=1;
        }
        for(int i=0;i<m;i++){
            memo[i][0]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                memo[i][j]=memo[i-1][j]+memo[i][j-1];
            }
        }

        return memo[m-1][n-1];
    }
};
