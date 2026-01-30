/**
 * @brief Check if tree can be partitioned into two equal-sum subtrees
 * @intuition Compute all subtree sums, check if half of total exists as subtree sum
 * @approach DFS to compute subtree sums, verify total/2 exists (excluding root)
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] bool checkEqualTree(TreeNode* root) {
        vector<int> seen;
        
        auto sum = [&](this auto&& sum, TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            const int s = sum(node->left) + sum(node->right) + node->val;
            seen.push_back(s);
            return s;
        };
        
        const int total = sum(root);
        if (total % 2 != 0) {
            return false;
        }
        seen.pop_back();
        return ranges::count(seen, total / 2) > 0;
    }
};
