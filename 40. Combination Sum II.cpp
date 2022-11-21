class Solution {
public:
    vector<vector<int>> ans;
    unordered_map <string, int> dup;
    string vector_to_string(vector<int> &v) {
        string ret;
        for(int i = 0; i < v.size(); i++) {
            char c = v[i];
            ret += c;
        }
        return ret;
    }
    void dp(vector<int>& candidates, int target, int idx, vector<int>& temp) {
        if(idx == candidates.size()) {
            if(target == 0) {
                string ex = vector_to_string(temp);
                if(dup[ex] == 0) {
                    ans.push_back(temp);
                    dup[ex] = 1;
                }

            }
            return;
        }
        if(candidates[idx] == target) {
            temp.push_back(candidates[idx]);
            string ex = vector_to_string(temp);
                if(dup[ex] == 0) {
                    ans.push_back(temp);
                    dup[ex] = 1;
                }

            temp.pop_back();
            return;
        }
        if(candidates[idx] < target) {
            temp.push_back(candidates[idx]);
            dp(candidates, target - candidates[idx], idx+1, temp);
            temp.pop_back();
            //decide not to take idx, and all the same idx too
            int next = idx+1;
            for(next; next < candidates.size(); next++)
                if(candidates[idx] != candidates[next])
                    break;
            dp(candidates, target, next, temp);
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dp(candidates, target, 0, temp);
        return ans;
    }
};