class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> list;
        queue<TreeNode*> level;
        list.push(root);
        while(!list.empty()){
            auto temp = list.front();
            list.pop();
            if(!temp) continue;
            if(temp->left) level.push(temp->left);
            if(temp->right) level.push(temp->right);
            if(list.empty()){
                if(temp) res.push_back(temp->val);
                if(!level.empty()) {
                    list = level;
                    while(!level.empty()){level.pop();}
                }
            }
            
        }
        return res;
    }
};
