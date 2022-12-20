class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<int, vector<string>> memo {{s.size(), {""}}};
    function<bool(vector<string>& words,string s)> count =[&](vector<string>& words,string s){
    for(string A:words){
        if(A==s) return true;
    }
    return false;  
    };
    function<vector<string>(int)> sentences = [&](int i) {
        if (!memo.count(i))
            for (int j=i+1; j<=s.size(); j++)
                if (count(wordDict,s.substr(i, j-i)))
                    for (string tail : sentences(j))
                        memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
        return memo[i];
    };
    return sentences(0);
}


};
