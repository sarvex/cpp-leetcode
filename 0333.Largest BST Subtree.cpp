/**
 * @brief Find size of largest BST subtree in binary tree
 * @intuition DFS returning min, max, and size for each subtree
 * @approach Post-order traversal validating BST property at each node
 * @complexity Time: O(n), Space: O(h) for recursion
 */
#include <algorithm>
#include <climits>
#include <vector>

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

class Solution final {
public:
    [[nodiscard]] int largestBSTSubtree(TreeNode* root) const {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    [[nodiscard]] std::vector<int> dfs(TreeNode* root, int& ans) const {
        if (root == nullptr) {
            return {INT_MAX, INT_MIN, 0};
        }
        
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        
        if (left[1] < root->val && root->val < right[0]) {
            const int size = left[2] + right[2] + 1;
            ans = std::max(ans, size);
            return {std::min(root->val, left[0]), 
                    std::max(root->val, right[1]), 
                    size};
        }
        return {INT_MIN, INT_MAX, 0};
    }
};
