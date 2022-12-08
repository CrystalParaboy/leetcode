class Solution {
public:
    vector<int> result;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=(rolls.size()+n)*mean;
        int sum_m=0;
        int sum_n;
        for(int i:rolls){
            sum_m+=i;
        }
        sum_n=sum-sum_m;
        back(sum_n,n);
        return result;
    }

    void back(int& sum_n,int& n){
        if(n<=0||sum_n<=0) return; 
        if(sum_n>n*6) return;
        if(sum_n<n*1) return;
        for(int i=1;i<=6;i++){
            result.push_back(i);
            sum_n-=i;
            n--;
            back(sum_n,n);
            if(n==0&&sum_n==0) break;
            result.pop_back();
            sum_n+=i;
            n++;
        }
        return;
    }
};

/**

sum=(m+n) *mean
   =rolls.sum + n.sum
**/
