class Solution {
public:
    string simplifyPath(string path) {
        vector <string> seperate;
        string tmp = "";
        for(int i = 0 ; i < path.size(); i++) {
            if(path[i] == '/') {
                if(tmp.size() != 0) {
                    seperate.push_back(tmp);
                    tmp = "";
                }
            }
            else
                tmp += path[i];

        }
        if(tmp.size() != 0) {
                seperate.push_back(tmp);
                tmp = "";
            }
        stack <string> simp;
        for(int i = 0; i < seperate.size(); i++) {
            cout << seperate[i] << endl;
            if(seperate[i] == "..") {
                if(simp.empty() != true)
                    simp.pop();
                continue;
            }
            if(seperate[i] == ".") {
                continue;
            }
            simp.push(seperate[i]);
        }
        string ret = "/";
        stack <string> reverse;
        while(simp.empty() != true) {
            reverse.push(simp.top());
            simp.pop();
        }
        while(reverse.empty() != true) {
            ret += reverse.top();
            ret += "/";
            reverse.pop();
        }
        if(ret.size() > 1)
            ret.resize(ret.size() - 1);
        return ret;
    }
};