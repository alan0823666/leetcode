class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        
        for(int start = 0; start + needle.size() <= haystack.size(); start++) {
            
            bool all_the_same = true;
            for(int i = 0; i < needle.size(); i++) {
                if(haystack[start + i] != needle[i]) {
                    all_the_same = false;
                    break;
                }
            }
            if(all_the_same)
                return start;
        }
        return -1;
    }
    
};