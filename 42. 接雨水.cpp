class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        vector<int> l(height.size(),0);
        vector<int> r = l;
        for(int i=1; i<height.size();i++){
            l[i] = max(l[i-1],height[i-1]);
        }
        for(int j=height.size()-2; j>=0;j--)
            r[j] = max(r[j+1], height[j+1]);
        for(int i=1;i<height.size()-1;i++){
            int m = min(r[i],l[i]);
            if(height[i] < m) sum+= m-height[i];
        }
        return sum;
    }
};
