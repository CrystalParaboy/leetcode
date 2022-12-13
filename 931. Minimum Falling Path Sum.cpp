class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) {
            int m=matrix[0][0];
            for(auto i:matrix[0]){
                m=min(m,i);
            }
            return m;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j+1]);
                }
                else if(j==n-1){
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j-1]);
                }
                else
                    matrix[i][j]+=min({matrix[i-1][j],matrix[i-1][j+1],matrix[i-1][j-1]});
            }
        }
        int m=matrix[n-1][0];
        for(auto i:matrix[n-1]){
            m=min(i,m);
        }
        return m;
    }
};
