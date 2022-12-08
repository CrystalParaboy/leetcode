class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=(rolls.size()+n)*mean;
        int sum_m=0;
        int sum_n;
        sum_m=accumulate(rolls.begin(),rolls.end(),0);
        sum_n=sum-sum_m;
        if(sum_n>n*6||sum_n<n) return {};
        int rem=sum_n%n;
        vector<int> result(n,sum_n/n);
        for(int i=0;i<rem;i++){
            result[i]++;
        }
        return result;
    }
};

/**

sum=(m+n) *mean
   =rolls.sum + n.sum
**/
