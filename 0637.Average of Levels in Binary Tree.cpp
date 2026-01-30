/**
 * @brief Compute average value at each level of binary tree
 * @intuition BFS level-by-level, sum values and divide by count
 * @approach Use queue for BFS, process entire level at once
 * @complexity Time: O(n), Space: O(w) where w is max width
 */
class Solution final {
public:
    [[nodiscard]] static vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        vector<double> ans;
        
        while (!q.empty()) {
            const int n = q.size();
            long long s = 0;
            for (int i = 0; i < n; ++i) {
                auto* node = q.front();
                q.pop();
                s += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(static_cast<double>(s) / n);
        }
        return ans;
    }
};
