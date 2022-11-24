class Solution {
public:
    int minDistance(string word1, string word2) {
        int w2=word2.length();
        int w1=word1.length();
        int dp[w1+1][w2+1];
        for(int i=0;i<=w1;i++) dp[i][0]=i;
        for(int j=0;j<=w2;j++) dp[0][j]=j;
        for(int i=1;i<=w1;i++){
            for(int j=1;j<=w2;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
        return dp[w1][w2];
    }
};
