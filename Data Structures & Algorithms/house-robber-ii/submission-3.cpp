class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> nums1(nums.begin() + 1, nums.end()); //take 0
        vector<int> nums2(nums.begin(), nums.end() - 1); //exclude 0

        return max(helper(nums1),helper(nums2));
        
    }

private:
    int helper(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n);

        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);

        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }

        return dp.back();
    }
};