/**
 * @brief Find maximum width of binary tree (including nulls between nodes)
 * @intuition Use level-order traversal with node positions to compute width
 * @approach BFS tracking node indices, width = rightmost - leftmost + 1
 * @complexity Time: O(n), Space: O(w) where w is max width
 */
class Solution final {
public:
    [[nodiscard]] static int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 0;
        
        while (!q.empty()) {
            ans = max(ans, q.back().second - q.front().second + 1);
            const int offset = q.front().second;
            
            for (int n = q.size(); n > 0; --n) {
                auto [node, idx] = q.front();
                q.pop();
                const int j = idx - offset;
                
                if (node->left) {
                    q.push({node->left, j * 2});
                }
                if (node->right) {
                    q.push({node->right, j * 2 + 1});
                }
            }
        }
        return ans;
    }
};
