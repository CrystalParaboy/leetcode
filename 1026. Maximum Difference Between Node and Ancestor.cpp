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
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return back(root,root->val,root->val);
    }
    int back(TreeNode* root,int mx,int mi){
        return root? max(back(root->left,max(mx,root->val),min(mi,root->val)),
                         back(root->right,max(mx,root->val),min(mi,root->val))):mx-mi;
    }
};
