class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        int level=1;
        vector<vector<int>> res;
        if(root==nullptr) return res;
        q.push(root);
        while(q.size()){
            vector<int> vec;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* temp=q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            if(level%2==0) reverse(vec.begin(),vec.end());
            res.push_back(vec);
            level++;
        }
        return res;
    }
};
