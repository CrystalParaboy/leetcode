class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end());
        int tail=points[0][1];
        int res=1;
        for(int i=1;i<points.size();i++){
            if(tail<points[i][0]){
                res++;
                tail=points[i][1];
            }
            else{
                tail=min(tail,points[i][1]);
            }
        }
        return res;
    }
};
