class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();

        if(n==0 || m==0) return 0;

        vector<vector<int>> dp(n,vector<int>(m,0));

        if (t1[0]==t2[0]) dp[0][0]=1;

        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],(int)(t1[i]==t2[0])); 
        }

        for(int j=1;j<m;j++){
            dp[0][j] = max(dp[0][j-1], (int)(t1[0] == t2[j]));
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(t1[i]==t2[j]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n-1][m-1];

    }
};
