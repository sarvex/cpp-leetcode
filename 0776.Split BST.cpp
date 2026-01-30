/**
 * @brief Split BST into two trees at target value
 * @intuition Recursively split subtrees based on comparison with target
 * @approach DFS: if root <= target, split right; else split left; reconnect
 * @complexity Time: O(h), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] std::vector<TreeNode*> splitBST(TreeNode* root, const int target) {
        return split(root, target);
    }

private:
    [[nodiscard]] std::vector<TreeNode*> split(TreeNode* root, const int target) {
        if (!root) {
            return {nullptr, nullptr};
        }
        if (root->val <= target) {
            auto result = split(root->right, target);
            root->right = result[0];
            result[0] = root;
            return result;
        } else {
            auto result = split(root->left, target);
            root->left = result[1];
            result[1] = root;
            return result;
        }
    }
};
