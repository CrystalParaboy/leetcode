class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return intervals;
        function<bool(vector<int>&, vector<int>&)> sortFunc = [&](vector<int> &fir, vector<int> &sec){
            return fir[0] < sec[0];
        };
        sort(intervals.begin(), intervals.end(), sortFunc);
        int i=0;
        while(i<intervals.size()){
            if(i==intervals.size()-1) break;
            if(intervals[i+1][1] <= intervals[i][1]) intervals.erase(intervals.begin()+i+1);
            else if(intervals[i+1][0] <= intervals[i][1]){
                intervals[i][1] = intervals[i+1][1];
                intervals.erase(intervals.begin()+i+1);
            }
            else ++i;
        }
        /**
        for(auto i:intervals) cout<<i[0]<<' ';
        **/

        return intervals;
    }
};
