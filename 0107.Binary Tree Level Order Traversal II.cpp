/**
 * @brief Bottom-up level order traversal using BFS
 * @intuition Same as regular level order, but reverse result at end
 * @approach Use BFS to collect levels top-down, then reverse the result
 * @complexity Time: O(n), Space: O(w) where w is max width of tree
 */

class Solution final {
public:
    [[nodiscard]] static auto levelOrderBottom(TreeNode* root) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        
        std::queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            std::vector<int> level;
            for (int n = q.size(); n > 0; --n) {
                auto* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(std::move(level));
        }
        
        std::ranges::reverse(result);
        return result;
    }
};
