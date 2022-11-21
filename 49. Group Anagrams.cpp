class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map< string, int > group;
        int type_num = 1;
        vector <vector<string>> ret;
        for(int i = 0; i < strs.size(); i++) {
            string copy(strs[i]);
            //cout << copy << endl;
            sort(copy.begin(), copy.end());
            //cout << copy << endl;
            if(group[copy] != 0) {
                int type_idx = group[copy] - 1;
                ret[type_idx].push_back(strs[i]);
            }
            else {
                group[copy] = type_num;
                ret.resize(ret.size() + 1);
                ret[type_num - 1].push_back(strs[i]);
                type_num++;
            }

        }
        return ret;

    }
};