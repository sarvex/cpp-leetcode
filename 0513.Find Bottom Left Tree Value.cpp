/**
 * @brief Find leftmost value in last row using BFS
 * @intuition BFS level by level; first node of each level is the leftmost, last level gives answer
 * @approach Level-order traversal storing first node's value of each level.
 *           After traversal completes, ans holds the leftmost value of the bottom row.
 * @complexity Time: O(n), Space: O(w) where w is max tree width
 */
class Solution final {
public:
    [[nodiscard]] static auto findBottomLeftValue(TreeNode* root) -> int {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        
        while (!q.empty()) {
            ans = q.front()->val;
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                auto* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
