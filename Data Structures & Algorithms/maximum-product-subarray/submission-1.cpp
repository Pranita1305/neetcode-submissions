class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int currMax=1,currMin=1;

        for(int num:nums){
            int temp=currMax*num;
            currMax=max(max(currMax*num,num*currMin),num);
            currMin=min(min(temp,num*currMin),num);
            res=max(res,currMax);
        }

        return res;
    }
};
