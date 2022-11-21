class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> my_stack;
        my_stack.push(-1);
        
        int ret = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                my_stack.push(i);
            }
            else {
                
                my_stack.pop();
                
                
                if(my_stack.empty())
                    my_stack.push(i);
                else
                    ret = max(ret, i - my_stack.top());
            }
        }
        return ret;
    }
};