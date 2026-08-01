class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<m+1;i++){ //w2=0 delete
            dp[0][i]=i;
        }

        for(int i=0;i<n+1;i++){ //w1 insert
            dp[i][0]=i;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(w1[i-1]!=w2[j-1]){
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
                else dp[i][j]=dp[i-1][j-1];
            }
        }

        return dp[n][m];
    }
};
