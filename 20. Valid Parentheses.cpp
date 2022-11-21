class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        map<char, char> filp;
        filp['('] = ')';
        filp['['] = ']';
        filp['{'] = '}';
        for(int i = 0; i < s.size(); i++) {
            if(mystack.empty() == true) {
                mystack.push(s[i]);
            }
            else if(s[i] == filp[mystack.top()]){
                mystack.pop();
                continue;
            }
            else
                mystack.push(s[i]);
        }
        
        if(mystack.empty() == true)
            return true;
        return false;
        
    }
};