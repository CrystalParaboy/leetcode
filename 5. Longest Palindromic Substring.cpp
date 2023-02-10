class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string res = s.substr(0,1);
        for(int i = 0; i < s.size(); ++i){
            int off = 1;
            while(i - off >= 0 && i + off < s.size() && s[i - off] == s[i + off]){
                ++off;
            }
            if(off > 1)
                res = res.size() >= off*2-1 ? res : s.substr(i-off+1, 2*off-1);
            if(s[i] == s[i+1]){
                off = 1;
                while(i - off >=0 && i + 1 + off < s.size() && s[i - off] == s[i + 1 + off]){
                    ++off;
                }
                res = res.size() >= off*2 ? res : s.substr(i - off + 1, 2*off);
            }
        }
        return res;
    }
};
