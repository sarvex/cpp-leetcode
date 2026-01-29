/**
 * @brief Count paths in tree that sum to target (path goes downward)
 * @intuition Prefix sum: if currSum - targetSum exists, found valid path
 * @approach DFS with hash map tracking prefix sums on current path
 * @complexity Time: O(n) Space: O(h) where h is tree height
 */
#include <unordered_map>

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
    [[nodiscard]] auto pathSum(TreeNode* root, int targetSum) const -> int {
        std::unordered_map<long long, int> cnt;
        cnt[0] = 1;

        auto dfs = [&](this auto&& dfs, TreeNode* node, long long s) -> int {
            if (!node) {
                return 0;
            }

            s += node->val;
            int ans = cnt[s - targetSum];
            ++cnt[s];
            ans += dfs(node->left, s) + dfs(node->right, s);
            --cnt[s];

            return ans;
        };

        return dfs(root, 0);
    }
};
