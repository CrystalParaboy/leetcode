class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[](vector<int> a,vector<int> b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0]; });
        int res=in.size();
        int i=1;
        int mx=in[0][1];
        if(res<=1) return res;
        while(i<in.size()){
                if(in[i][1]<=mx) res--;
                else mx=in[i][1];
                i++;
            
        }
        return res;
    }
};
