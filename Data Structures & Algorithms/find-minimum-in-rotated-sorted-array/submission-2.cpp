class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int res=nums[0];

        while(l<=r){
            if(nums[l]<nums[r]) return min(res,nums[l]);

            int mid=l+(r-l)/2;
            res=min(res,nums[mid]);

            if(nums[mid]>=nums[l]) l=mid+1;
            else r=mid-1;
        }

        return res;
    }
};
