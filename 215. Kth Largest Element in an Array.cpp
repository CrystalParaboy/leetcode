class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i:nums){
            s.emplace(i);
            if(s.size()>k){
                s.erase(s.begin());
            }
        }
        auto res=s.begin();
        return *res;
    }
};
