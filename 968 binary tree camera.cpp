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
    int result=0;
    int minCameraCover(TreeNode* root) {
        if(travel(root)==0) result++;
        return result;
    }
    int travel(TreeNode* node){
        
        if(node==nullptr) return 2;
        int left=travel(node->left);
        int right=travel(node->right);
        if(left==2&&right==2) return 0;
        if(left==0||right==0) {
            result++;
            return 1;
        }
        if(left==1||right==1) return 2;
        return -1;


    }
};
