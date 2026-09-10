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
private:
    int matchingNodesCount = 0;

    // Helper function returning pair<sum, count> for subtree rooted at 'node'
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        // Post-order traversal: Process left and right subtrees first
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int currentSum = node->val + left.first + right.first;
        int currentCount = 1 + left.second + right.second;

        // Integer division automatically rounds down to nearest integer
        if (node->val == (currentSum / currentCount)) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        dfs(root);
        return matchingNodesCount;
    }
};