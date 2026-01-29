/**
 * @brief BFS with alternating direction for zigzag traversal
 * @intuition Level order traversal but reverse alternate levels
 * @approach Use BFS and flip direction flag each level, reverse when needed
 * @complexity Time: O(n), Space: O(w) where w is max width of tree
 */

class Solution final {
public:
    [[nodiscard]] static auto zigzagLevelOrder(TreeNode* root) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        
        std::queue<TreeNode*> q{{root}};
        bool leftToRight = true;
        
        while (!q.empty()) {
            std::vector<int> level;
            for (int n = q.size(); n > 0; --n) {
                auto* node = q.front();
                q.pop();
                level.emplace_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (!leftToRight) {
                std::ranges::reverse(level);
            }
            result.emplace_back(std::move(level));
            leftToRight = !leftToRight;
        }
        return result;
    }
};
