class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            for(int j=sq;j<=n;j++){
                dp[j]=min(dp[j],1+dp[j-sq]);   
            }
        }

        return dp[n];
    }
};