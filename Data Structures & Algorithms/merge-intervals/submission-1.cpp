class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;

        int n=intervals.size();

        int minStart=intervals[0][0];
        int maxEnd=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]>maxEnd){
                res.push_back({minStart,maxEnd});
                minStart=intervals[i][0];
                maxEnd=intervals[i][1];
            }
            else if(intervals[i][1]<minStart){
                res.push_back(intervals[i]);
            }
            else{
                minStart=min(minStart,intervals[i][0]);
                maxEnd=max(maxEnd,intervals[i][1]);
            }
        }

        res.push_back({minStart,maxEnd});
        return res;
    }
};
