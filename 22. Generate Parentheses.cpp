class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        back(res, str, n, 0);
        return res;
    }

    void back(vector<string>& res, string str, int left, int right){
        if(left == 0 && right ==0){
            res.push_back(str);
            return;
        }
        if(left > 0){
            back(res, str+'(', left-1, right+1);
        }
        if(right >0){
            back(res, str+')', left, right-1);
        }
        return;

    }
};
