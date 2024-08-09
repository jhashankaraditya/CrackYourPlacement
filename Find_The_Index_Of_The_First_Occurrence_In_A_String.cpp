class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; i<haystack.size(); i++) {
            if (haystack[i]==needle[0]) {
                string hay_part=haystack.substr(i,needle.size());
                if (hay_part==needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};
