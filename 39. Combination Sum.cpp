class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void back(vector<int> can,int target,bool mark,int index){
        if(target<0){
            return;
        } 
        else if(target==0){
            result.push_back(path);
            mark=true;
            return;
        }
        for(int i=index;i<can.size();i++){
            path.push_back(can[i]);
            back(can,target-can[i],mark,i);
            path.pop_back();
            if(mark){
                mark=false;
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        back(candidates,target,false,0);
        return result;
    }
};
