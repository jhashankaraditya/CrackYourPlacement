class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=1, min_len=INT_MAX;
        string longest_prefix;
        for (int i=0; i<strs.size(); i++) {
            int size=strs[i].size();
            min_len=min(min_len,size);
        }
        for (len=1; len<=min_len; len++) {
            unordered_map<string,bool> marked;
            for (int j=0; j<strs.size(); j++) {
                string curr_str=strs[j].substr(0,len);
                marked[curr_str]=1;
            }
            if (marked.size()==1) {
                longest_prefix=strs[0].substr(0,len);
            }
            else break;
        }
        return longest_prefix;
    }
};
