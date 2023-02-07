class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int res = 0;
        vector<int> dp(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]) dp[i] = max(dp[j]+1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

/**
8 10 1 9 1 9 2 3 6 80
**/
