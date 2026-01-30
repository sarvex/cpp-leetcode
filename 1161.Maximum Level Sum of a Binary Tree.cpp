/**
 * @brief Find level with maximum sum in binary tree using BFS
 * @intuition Process tree level by level, track sum at each level
 * @approach Use BFS to traverse level by level. Compute sum at each level and track
 *           the level number with maximum sum.
 * @complexity Time: O(n), Space: O(w) where w is max width of tree
 */
class Solution final {
public:
    [[nodiscard]] static int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int mx = INT_MIN;
        int ans = 0;
        int i = 0;
        while (!q.empty()) {
            ++i;
            int s = 0;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                s += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (mx < s) {
                mx = s;
                ans = i;
            }
        }
        return ans;
    }
};
