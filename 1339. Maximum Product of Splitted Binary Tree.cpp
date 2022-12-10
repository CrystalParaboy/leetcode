/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
static int MOD=1e9+7;
class Solution {
public:
    long long result,sum=0;
    int maxProduct(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!root->left&&!root->right) return root->val;
        TreeNode* node;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            node=st.top();
            st.pop();
            sum+=node->val;
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);            
        }
        int a=SumUnder(root);
        return result%MOD;
    }
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
       if(!root)
            return 0;
       int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right); 
       result=max({result,(sum-sumUnderLeft)*sumUnderLeft,(sum-sumUnderRight)*sumUnderRight}); 
       return sumUnderLeft+sumUnderRight+root->val;
    }
};
