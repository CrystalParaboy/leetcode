
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> node_que;
        node_que.push(root);
        while(1){
            queue<TreeNode*> temp_node;
            vector<int> temp_val;
            while(!node_que.empty()){
                auto cur = node_que.front();
                node_que.pop();
                if(cur) {
                    temp_val.push_back(cur->val);
                    if(cur->left) temp_node.push(cur->left);
                    if(cur->right) temp_node.push(cur->right);
                }
            }
            node_que = temp_node;
            if(!temp_val.empty()) res.push_back(temp_val);
            else break;
            
        }
        return res;
    }
};
