class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_array=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(sum<0) sum=0;
            sum+=nums[i];
            if(sum>=max_array){
                max_array=sum;
            }
        }
        return max_array;
    }
};
