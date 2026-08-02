class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > sum)
            return 0;

        if((sum + target) % 2)
            return 0;

        int S = (sum + target) / 2;

        vector<vector<int>> dp(nums.size()+1,
                               vector<int>(S+1,0));

        dp[0][0] = 1;

        for(int i=1;i<=nums.size();i++){

            dp[i][0]=1;

            for(int j=0;j<=S;j++){

                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[nums.size()][S];
    }
};