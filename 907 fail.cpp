class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<long>dp(arr.size()+1,0);
        dp[1]=arr[0];
        for(int i=2;i<=arr.size();i++){
            int min=arr[i-1];
            dp[i]+=dp[i-1];
            for(int j=i;j>0;j--){
                if(arr[j-1]<min) min=arr[j-1];
                dp[i]+=min;
            }
        }
        int result=dp[arr.size()]%1000000007;
        return result;
        
    }
};

/**
3 dp[2]=dp[1]+arr[2]+min
dp[3]=dp[2]+arr[3]+
**/
