class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> num;
        long a,b,temp;
        for(auto A:tokens){
            if(A!="+"&&A!="-"&&A!="*"&&A!="/"){
                num.push(stoi(A));
            }
            else{
                if(A=="+"){
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    temp=a+b;
                    num.push(temp);
                }
                else if(A=="-"){
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    temp=b-a;
                    num.push(temp);
                }
                else if(A=="*"){
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    temp=b*a;
                    num.push(temp);
                }
                else if(A=="/"){
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    temp=b/a;
                    num.push(temp);
                }
            }
        }
        return num.top();
        
    }
};
