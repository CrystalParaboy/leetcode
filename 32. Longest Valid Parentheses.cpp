class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        for(int i = 0; i < str.length(); i++){
            if(str[i]=='('){
                s.push(i);
            }else{
                if(!s.empty() && str[s.top()] == '('){
                    s.pop();
                }
                else{
                    s.push(i);
                }
            }
        }
        if(s.empty())return str.length();
        int a = str.length(), b = 0;
        int ans = 0;
        while(!s.empty()){
            b = s.top();
            s.pop();
            ans = max(ans,a-b-1);
            a = b;
        }
        ans = max(ans,a);
        return ans;
    }
};
