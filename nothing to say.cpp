class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=1) return n;
        int temp=0;
        int step=0;
        while(n>0){
            temp++;
            n-=temp;
            step+=n>=0? 1:0;
        }
        return step;
    }
};
