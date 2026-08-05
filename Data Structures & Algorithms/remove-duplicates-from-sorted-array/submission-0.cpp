class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> arr;

        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])) continue;
            else{
                s.insert(nums[i]);
            }
        }

        int i=0;
        for(int num:s){
            nums[i++]=num;
        }

        return s.size();
    }
};

