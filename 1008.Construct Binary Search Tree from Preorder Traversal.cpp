/**
 * @brief Recursive BST construction with binary search for split point
 * @intuition First element is root; find split point where values become greater
 * @approach Use binary search to find boundary between left and right subtrees
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* bstFromPreorder(const std::vector<int>& preorder) {
        auto dfs = [&](this auto&& dfs, const int i, const int j) -> TreeNode* {
            if (i > j) {
                return nullptr;
            }
            auto* root = new TreeNode(preorder[i]);
            int l = i + 1, r = j + 1;
            while (l < r) {
                const int mid = (l + r) >> 1;
                if (preorder[mid] > preorder[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            root->left = dfs(i + 1, l - 1);
            root->right = dfs(l, j);
            return root;
        };
        return dfs(0, static_cast<int>(preorder.size()) - 1);
    }
};
