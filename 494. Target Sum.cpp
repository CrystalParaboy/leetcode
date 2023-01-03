class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum<abs(target)||(target+sum)%2==1) return 0;
        int tar=(target+sum)/2;
        vector<int> dp(tar+1,0);
        dp[0]=1;
        for(int i=1;i<=nums.size();i++){
            for(int j=tar;j>=nums[i-1];j--){
                dp[j]=(dp[j]+dp[j-nums[i-1]]);
            }
        }
        return dp[tar];
    }
};
