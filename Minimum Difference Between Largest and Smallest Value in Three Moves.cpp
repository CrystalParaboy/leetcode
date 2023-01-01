class Solution {
public:
    int minDifference(vector<int>& A) {
        if(A.size()<=4){
            return 0;
        }
        int n = A.size();
        sort(A.begin(),A.end());
        return min({A[n - 1] - A[3], A[n - 2] - A[2], A[n - 3] - A[1], A[n - 4] - A[0]});
    }
};
