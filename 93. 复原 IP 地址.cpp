class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        int len = s.size();
        if(len < 4 || len > 12) return res;
        back(s, 0, 0);
        return res;

    }

    void back(string &s, int start, int n){
        if(n == 3 && isvalid(s, start, s.size()-1)){
            res.push_back(s);
            return;
        } 
        for(int i = 0; i < 3; i++){
            if(isvalid(s, start, start + i)) {
                s.insert(s.begin() + i + start + 1, '.');
                back(s, start + i + 2, n + 1);
                s.erase(s.begin() + start + i +1);
            }
            else break;
        }
    }
    
    bool isvalid(string &s, int start, int end){
        if(end - start > 2 || start > end) return false;
        if(s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0') return false;
            num = num*10 + int(s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
};
