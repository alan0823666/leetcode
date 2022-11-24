class Solution {
public:
    int binary_search_first(vector<vector<int>>& intervals, int l, int r, int val) {
        int idx = (l+r)/2;
        cout << "a_idx : " << idx << endl;
        if(l >= r)
            return -1;
        else if(intervals[idx][0] <= val && (idx+1 >= intervals.size() || intervals[idx+1][0] > val))        {
            return idx;
        }
        else if(intervals[idx][0] > val) {
            return binary_search_first(intervals, l, idx, val);
        }
        else
            return binary_search_first(intervals, idx+1, r, val);
    }

    int binary_search_second(vector<vector<int>>& intervals, int l, int r, int val) {
        int idx = (l+r)/2;
        cout << "b_idx : " << idx << endl;
        if(l >= r)
            return -1;
        else if(intervals[idx][1] >= val && (idx-1 < 0 || intervals[idx-1][1] < val))
            return idx;
        else if(intervals[idx][1] < val) {
            return binary_search_second(intervals, idx+1, r, val);
        }
        else
            return binary_search_second(intervals, l, idx, val);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int a = binary_search_first(intervals, 0, n, newInterval[0]);
        int b = binary_search_second(intervals, 0, n, newInterval[1]);
        cout << a << " " << b;
        if(a == -1 && b == -1) {
            vector<vector<int>> ret;
            ret.push_back(newInterval);
            return ret;
        }
        if(newInterval[0] > intervals[n-1][1]) {
            intervals.insert(intervals.begin() + intervals.size(), newInterval);
            return intervals;
        }
        if(newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if(b == -1) {
            bool flag_in_a_interval = (newInterval[0] <= intervals[a][1]);
            int delete_start_idx = a;
            int delete_end_idx = n-1;
            if(flag_in_a_interval == false)
                a = a+1;
            vector<int> insert_vec(2);
            insert_vec[0] = (flag_in_a_interval)? intervals[a][0] : newInterval[0];
            insert_vec[1] = newInterval[1];
            intervals.erase(intervals.begin() + a, intervals.begin() + n);
            intervals.insert(intervals.begin() + a, insert_vec);
            return intervals;
        }
        if(a == -1) {
            bool flag_in_b_interval = (newInterval[1] >= intervals[b][0]);
            int delete_start_idx = 0;
            int delete_end_idx = b;
            if(flag_in_b_interval == false)
                b = b-1;
            vector<int> insert_vec(2);
            insert_vec[0] = newInterval[0];
            insert_vec[1] = (flag_in_b_interval)? intervals[b][1] : newInterval[1];
            intervals.erase(intervals.begin(), intervals.begin() + b + 1);
            intervals.insert(intervals.begin(), insert_vec);
            return intervals;
        }
        bool flag_in_a_interval = (newInterval[0] <= intervals[a][1]);
        bool flag_in_b_interval = (newInterval[1] >= intervals[b][0]);
        
        int delete_start_idx = a;
        int delete_end_idx = b;
        if(flag_in_a_interval == false)
            a = a+1;
        if(flag_in_b_interval == false)
            b = b-1;
        vector<int> insert_vec(2);
        insert_vec[0] = (flag_in_a_interval)? intervals[a][0] : newInterval[0];
        insert_vec[1] = (flag_in_b_interval)? intervals[b][1] : newInterval[1];
        intervals.erase(intervals.begin() + a, intervals.begin() + b + 1);
        intervals.insert(intervals.begin()+a, insert_vec);
        return intervals;
    }
};