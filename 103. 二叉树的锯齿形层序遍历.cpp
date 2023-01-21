
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level=0;
        deque<TreeNode*> node_deq;
        vector<vector<int>> res;
        node_deq.push_back(root);
        while(1){
            deque<TreeNode*> temp_deq;
            vector<int> val_vec;
            if(level % 2 ==0) {
                while(!node_deq.empty()){
                    TreeNode* cur = node_deq.front();
                    node_deq.pop_front();
                    if(cur){
                        val_vec.push_back(cur->val);
                        if(cur->left) temp_deq.push_back(cur->left);
                        if(cur->right) temp_deq.push_back(cur->right);
                    } 
                    
                }
            }
            else{
                while(!node_deq.empty()){
                    TreeNode* cur = node_deq.back();
                    node_deq.pop_back();
                    if(cur){
                        val_vec.push_back(cur->val);
                        if(cur->right) temp_deq.push_front(cur->right);
                        if(cur->left) temp_deq.push_front(cur->left);
                    } 
                }
            }
            node_deq = temp_deq;
            if(!val_vec.empty()) res.push_back(val_vec);
            else break;
            ++level;
        }
        return res;

    }
};
