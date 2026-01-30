/**
 * @brief Find most frequent subtree sums using DFS
 * @intuition Calculate subtree sum at each node, track frequency, return those with max frequency
 * @approach DFS computes subtree sum (node value + left sum + right sum), counting occurrences.
 *           Track maximum frequency during traversal. Collect all sums with max frequency.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findFrequentTreeSum(TreeNode* root) -> vector<int> {
        unordered_map<int, int> cnt;
        int mx = 0;
        
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (!node) return 0;
            const int sum = node->val + dfs(node->left) + dfs(node->right);
            mx = max(mx, ++cnt[sum]);
            return sum;
        };
        
        dfs(root);
        
        vector<int> ans;
        for (const auto& [k, v] : cnt) {
            if (v == mx) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};
