class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int st = s.size() - 1;
        while(s[st] == ' ')
            st -= 1;
        for(int i = st; i >= 0 && s[i] != ' '; i--) {
            ret += 1;
        }
        return ret;
    }
};