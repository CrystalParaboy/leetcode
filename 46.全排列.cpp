class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> set;
        set.clear();
        function<void()> back = [&](){
            if(temp.size() == nums.size()) { 
                res.push_back(temp);
                return;
            }
            for(int i=0; i<nums.size(); i++){
                if(set.find(nums[i]) != set.end()) continue;
                set.insert(nums[i]);
                temp.push_back(nums[i]);
                back();
                set.erase(nums[i]);
                temp.pop_back();
            }
            return;
        };
        back();
        return res;


    }
};
