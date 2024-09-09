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
class Solution 
{
private:
    // We're using DFS which requires a "global" max diameter variable
    int m_maxDiameter = 0;

public: 
    int solve(TreeNode* root)
    {
        if (!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        m_maxDiameter = max(m_maxDiameter, left + right);
        
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        solve(root);
        return m_maxDiameter;
    }
};