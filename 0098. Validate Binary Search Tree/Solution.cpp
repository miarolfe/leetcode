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
    bool isValidBST(TreeNode* root) {
        long long lowerBound = -2147483657;
        long long upperBound = 2147483657;
        return helper(root, lowerBound, upperBound);
    }

    bool helper(TreeNode* root, long long lowerBound, long long upperBound)
    {
        if (!root) return true;

        return (root->val > lowerBound) && (root->val < upperBound) && helper(root->left, lowerBound, root->val) && helper(root->right, root->val, upperBound);
    }
};
