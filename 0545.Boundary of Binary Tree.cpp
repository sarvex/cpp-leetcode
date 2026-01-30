/**
 * @brief Collect tree boundary: root + left boundary + leaves + right boundary (reversed)
 * @intuition Boundary consists of leftmost path, all leaves, and rightmost path in reverse
 * @approach Use DFS with mode parameter: 0=left boundary, 1=leaves, 2=right boundary
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> boundaryOfBinaryTree(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, vector<int>& nums, TreeNode* node, int mode) -> void {
            if (!node) {
                return;
            }
            
            if (mode == 0) {
                if (node->left != node->right) {
                    nums.push_back(node->val);
                    if (node->left) {
                        dfs(nums, node->left, mode);
                    } else {
                        dfs(nums, node->right, mode);
                    }
                }
            } else if (mode == 1) {
                if (node->left == node->right) {
                    nums.push_back(node->val);
                } else {
                    dfs(nums, node->left, mode);
                    dfs(nums, node->right, mode);
                }
            } else {
                if (node->left != node->right) {
                    nums.push_back(node->val);
                    if (node->right) {
                        dfs(nums, node->right, mode);
                    } else {
                        dfs(nums, node->left, mode);
                    }
                }
            }
        };
        
        vector<int> ans = {root->val};
        
        if (root->left == root->right) {
            return ans;
        }
        
        vector<int> left, right, leaves;
        dfs(left, root->left, 0);
        dfs(leaves, root, 1);
        dfs(right, root->right, 2);
        
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leaves.begin(), leaves.end());
        ans.insert(ans.end(), right.rbegin(), right.rend());
        
        return ans;
    }
};
