class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<long>dp(arr.size()+1,0);
        for(int i=1;i<=arr.size();i++){
            int min=arr[i-1];
            bool change=0;
            dp[i]+=dp[i-1];
            int left;
            int right;
            for(int j=i-1;j>0;j--){
                if(arr[j-1]<min){
                    change=1;
                    left=j+1;
                    break;
                }
            }
            if(change==0) left=1;
            else change=0;
            for(int j=i+1;j<=arr.size();j++){
                if(arr[j-1]<min){
                    change=1;
                    right=j-1;
                    break;
                }
            }
            if(change==0) right=arr.size();
            left=i-left+1;
            right=right-i+1;
            dp[i]+=arr[i-1]*left*right;
        }
        int result=dp[arr.size()]%1000000007;
        return result;
        
    }
};
