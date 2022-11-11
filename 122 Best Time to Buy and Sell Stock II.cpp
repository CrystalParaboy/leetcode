class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int dp[prices.size()];
        if(prices[1]>prices[0]) dp[1]=prices[1]-prices[0];
        else dp[1]=0;
        for(int i=2;i<prices.size();i++){
            if(prices[i]>prices[i-1]) dp[i]=dp[i-1]+prices[i]-prices[i-1];
            else dp[i]=dp[i-1];                  
        }
        return dp[prices.size()-1];
    }
};

//7 1 4 5 1 3 8
