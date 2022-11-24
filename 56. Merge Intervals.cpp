class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        vector<int> tmp(2);
        sort(intervals.begin(), intervals.end());
        tmp = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= tmp[1] && intervals[i][1] > tmp[1])
                tmp[1] = intervals[i][1];
            else if((intervals[i][0] <= tmp[1] && intervals[i][1] <= tmp[1]))
                continue;
            else {
                ret.push_back(tmp);
                tmp[0] = intervals[i][0];
                tmp[1] = intervals[i][1];
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};