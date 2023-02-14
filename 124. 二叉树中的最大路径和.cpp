/**
所有树的题目，都想成一颗只有根、左节点、右节点 的小树。然后一颗颗小树构成整棵大树，
所以只需要考虑这颗小树即可。接下来分情况，
按照题意：一颗三个节点的小树的结果只可能有如下6种情况：

根 + 左 + 右
根 + 左
根 + 右
根
左
右

好了，分析上述6种情况， 只有 2,3,4 可以向上累加，而1,5,6不可以累加
（这个很好想，情况1向上累加的话，必然出现分叉，情况5和6直接就跟上面的树枝断开的，没法累加），
所以我们找一个全局变量存储 1,5,6这三种不可累加的最大值， 
另一方面咱们用遍历树的方法求2,3,4这三种可以累加的情况。 
最后把两类情况得到的最大值再取一个最大值即可。
 */
class Solution {
private:
    int ans = 0;
    int scan(TreeNode* root){
        if(root == nullptr) return 0;
        int left_v = scan(root->left), right_v = scan(root->right);
        left_v = left_v > 0 ? left_v : 0;
        right_v = right_v > 0 ? right_v : 0;
        ans = max(ans, root->val + left_v + right_v);
        return root->val + max(left_v, right_v);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root) ans = root->val;
        scan(root);
        return ans;
    }
};
