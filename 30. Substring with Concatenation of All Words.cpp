class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        assert(!words.empty());
        const int length = words.back().size();
        const int totalLength = length * words.size();
        unordered_map<string, int> map;
        for (const string &word : words) {
            ++map[word];
        }
        typedef unordered_map<string, int>::iterator MapIt;
        vector<MapIt> positions;
        positions.reserve(s.size());
        for (int i = 0; i + length <= s.size(); ++i) {
            positions.push_back(map.find(s.substr(i, length)));
        }
        vector<int> result;
        unordered_map<string, int> map2; //dupulicate handler
        for (int i = 0; i + totalLength <= s.size(); ++i) {
            bool valid = true;
            for (int j = 0; j < totalLength && valid; j += length) {
                const auto it = positions[i + j];
                if (it == map.end() || ++map2[it->first] > it->second) {
                    valid = false;
                }
            }
            if (valid) {
                result.push_back(i);
            }
            map2.clear();
        }
        return result;
    }
};