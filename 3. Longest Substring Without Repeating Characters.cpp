class Solution {
#include <map>
public:
    int lengthOfLongestSubstring(string s) {
        using namespace std;
        map<char, int> repeated_map;
        int max_length = 0;
        int end = 1;
        for(int start = 0; start < s.size(); ) {
            //cout << start << " " << end << endl;
            
            char start_char = s[start];
            
            repeated_map[start_char] = 1;
            
            int flag = 0;
            char char_recorder;
            for(end ; end <= s.size(); ) {
                if(end >= s.size()) {
                    break;
                    flag = 1;
                }
                char end_char = s[end];
                
                map<char,int>::iterator it;
                it = repeated_map.find(end_char);
                
                if(it != repeated_map.end() && it -> second == 1) {
                    char_recorder = end_char;
                    break;
                }
                else {
                    repeated_map[end_char] = 1;
                    end += 1;
                }
            }
            int w_size = end - start;
            if(w_size > max_length)
                max_length = w_size;
            if(end >= s.size())
                break;
            for(int k = start; k < s.size(); k++) {
                char k_char = s[k];
                repeated_map[k_char] = 0;
                if(k_char == char_recorder) {
                    start = k+1;
                    break;
                }
            }
            if(start == end)
                end += 1;
        }
        return max_length;
    }
    
};