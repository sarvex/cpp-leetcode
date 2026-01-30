/**
 * @brief BFS to traverse binary tree in vertical order
 * @intuition Track column offset, use BFS to maintain top-to-bottom order
 * @approach BFS with offset tracking, group by column
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        
        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            columns[col].push_back(node->val);
            
            if (node->left != nullptr) {
                q.emplace(node->left, col - 1);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, col + 1);
            }
        }
        
        vector<vector<int>> ans;
        ans.reserve(columns.size());
        for (auto& [_, vals] : columns) {
            ans.push_back(move(vals));
        }
        return ans;
    }
};
