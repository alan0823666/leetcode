class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int count = 0;
        vector<string> tmp;
        vector<string> ret;
        int only_word_count = 0;
        for(int i = 0; i < words.size(); i++) {
            cout << words[i] << endl;
            
            if(count + 1 + words[i].size() > maxWidth && tmp.size() != 0) {
                string x= "";
                int space_sum = maxWidth - only_word_count;
                if(tmp.size() == 1) {
                    cout << "fuck" << tmp[0] << endl;
                    x += tmp[0];
                    for(int k = 0 ; k < space_sum; k++)
                            x +=  ' ' ;
                    ret.push_back(x);
                    tmp.resize(0);
                    count = only_word_count = 0;
                }
                else {
                int space_lenth = space_sum / (tmp.size()-1);
                int space_rest = space_sum - space_lenth * (tmp.size()-1);
                for(int i = 0; i < tmp.size()-1; i++) {
                        x += tmp[i];
                        if(space_rest > 0)
                            for(int k = 0 ; k < space_lenth+1; k++)
                              x +=  ' ' ;
                        else
                            for(int k = 0 ; k < space_lenth; k++)
                               x +=  ' ' ;
                            space_rest -= 1;
                    }
                    x += tmp[tmp.size() - 1];
                    ret.push_back(x);
                    tmp.resize(0);
                    count = only_word_count = 0;
                }

            }
            if(words[i].size() == maxWidth) {
                ret.push_back(words[i]);
                continue;
            }
            
            tmp.push_back(words[i]);
            if(tmp.size() == 1) {
                count += words[i].size();
            }
            else
                count += words[i].size() + 1;
            only_word_count += words[i].size();
            
        }
        if(tmp.size() == 0)
            return ret;
        string rin = "";
        for(int i = 0 ; i < tmp.size(); i++) {
            rin += tmp[i];
            if(i != tmp.size()-1)
                rin += " ";
        }
        for(int i = 0; rin.size() < maxWidth; i++)
            rin += " ";
        ret.push_back(rin);
        return ret;
    }

};