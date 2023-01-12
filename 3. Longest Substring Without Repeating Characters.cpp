class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res=0, temp=0, begin=0;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                begin=max(begin,m[s[i]]);
                res=max(res,temp);
                m[s[i]]=i;
                temp=i-begin;
            }
            else{
                m[s[i]]=i;
                temp++;
            } 
        }
        res=max(res,temp);
        return res;
    }
};

/**
a b c a b c b d a 
**/
