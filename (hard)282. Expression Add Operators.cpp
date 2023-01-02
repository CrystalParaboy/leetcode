class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        function<void(int pos, string cur, long sum, long pre, char op)> back=
        [&](int pos, string cur, long sum, long pre, char op ){
            if(sum==target&&pos==num.size()) res.push_back(cur);
            else {
                for(int i=pos+1;i<=num.size();i++){
                    string t=num.substr(pos,i-pos);
                    long now=stol(t);
                    if(i>pos+1&&t[0]=='0') continue;
                    if(pos==0){
                        back(i,t,now,now,'#');
                        continue;
                    }
                    back(i,cur+'+'+t,sum+now,now,'+');
                    back(i,cur+'-'+t,sum-now,now,'-');
                    if(op=='+') back(i,cur+'*'+t,sum-pre+pre*now,pre*now,op);
                    else if(op=='-') back(i,cur+'*'+t,sum+pre-pre*now,pre*now,op);
                    else back(i,cur+'*'+t,pre*now,pre*now,op);
                }
            }
        };
        back(0,"",0,0,'#');
        return res;
    }
};
