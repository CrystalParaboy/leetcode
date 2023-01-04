class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int m=0;
        int res=0;
        unordered_map<int,int> dp;
        for(int num:tasks){
            dp[num]++;
            m=max(num,m);
        }
        for(auto y:dp){
            int x=y.second;
            if(x==1) return -1;
            else if(x%3==0) res+=x/3;
            else if(x%3==1||x%3==2) res+=1+x/3;
        }
        return res;
    }
};
