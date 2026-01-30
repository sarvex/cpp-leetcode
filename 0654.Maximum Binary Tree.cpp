/**
 * @brief Construct maximum binary tree from array
 * @intuition Root is maximum element, recursively build left/right from subarrays
 * @approach Find max in range, create node, recurse on left and right portions
 * @complexity Time: O(n^2) average, Space: O(n) for recursion
 */
class Solution final {
public:
    [[nodiscard]] TreeNode* constructMaximumBinaryTree(const vector<int>& nums) {
        auto dfs = [&](this auto&& dfs, int l, int r) -> TreeNode* {
            if (l > r) {
                return nullptr;
            }
            int i = l;
            for (int j = l; j <= r; ++j) {
                if (nums[i] < nums[j]) {
                    i = j;
                }
            }
            auto* root = new TreeNode(nums[i]);
            root->left = dfs(l, i - 1);
            root->right = dfs(i + 1, r);
            return root;
        };
        
        return dfs(0, nums.size() - 1);
    }
};
