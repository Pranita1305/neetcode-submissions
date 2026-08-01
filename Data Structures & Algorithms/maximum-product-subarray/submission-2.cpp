class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curr_max=1;
        int curr_min=1;
        int prod=nums[0];

        for(int i=0;i<n;i++){
            int temp=curr_max*nums[i];
            curr_max=max(nums[i],max(curr_min*nums[i],temp));
            curr_min=min(nums[i],min(temp,curr_min*nums[i]));
            prod=max(prod,curr_max);
        }

        return prod;
    }
};
