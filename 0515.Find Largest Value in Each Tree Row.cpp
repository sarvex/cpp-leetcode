/**
 * @brief Find maximum value at each tree level using BFS
 * @intuition Level-order traversal tracking maximum value per level
 * @approach BFS with level-by-level processing. For each level, track maximum node value
 *           and add to result before moving to next level.
 * @complexity Time: O(n), Space: O(w) where w is max tree width
 */
class Solution final {
public:
    [[nodiscard]] static auto largestValues(TreeNode* root) -> vector<int> {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int maxVal = INT_MIN;
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                auto* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
