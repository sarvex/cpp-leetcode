/**
 * @brief BFS level-by-level traversal of binary tree
 * @intuition Process nodes level by level using a queue
 * @approach Use queue to track nodes at each level, process all nodes at current level before moving to next
 * @complexity Time: O(n), Space: O(w) where w is max width of tree
 */

class Solution final {
public:
    [[nodiscard]] static auto levelOrder(TreeNode* root) -> std::vector<std::vector<int>> {
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
        return result;
    }
};
