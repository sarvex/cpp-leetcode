/**
 * @brief Minimum difference between any two BST nodes
 * @intuition In-order traversal gives sorted sequence; min diff is between adjacent
 * @approach In-order traversal tracking previous value, update minimum difference
 * @complexity Time: O(n), Space: O(h) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static int minDiffInBST(TreeNode* root) {
        constexpr int INF = 1 << 30;
        int minDiff = INF;
        int prev = -INF;
        
        auto dfs = [&](auto&& self, TreeNode* node) -> void {
            if (!node) return;
            self(self, node->left);
            minDiff = std::min(minDiff, node->val - prev);
            prev = node->val;
            self(self, node->right);
        };
        
        dfs(dfs, root);
        return minDiff;
    }
};
