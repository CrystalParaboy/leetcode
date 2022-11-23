class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int dp[nums.size()+1];
        dp[1]=nums[0];
        dp[2]=max(nums[1],nums[0]);
        for(int i=3;i<=nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
    }
};
