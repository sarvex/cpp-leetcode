/**
 * @brief DFS to traverse binary tree in vertical order
 * @intuition Track column offset and depth to order nodes correctly
 * @approach DFS with offset tracking, sort by depth within each column
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

using pii = std::pair<int, int>;

class Solution final {
public:
    [[nodiscard]] std::vector<std::vector<int>> verticalOrder(TreeNode* root) const {
        std::map<int, std::vector<pii>> columns;
        dfs(root, 0, 0, columns);
        
        std::vector<std::vector<int>> ans;
        for (auto& [_, nodes] : columns) {
            std::sort(nodes.begin(), nodes.end(), [](const pii& a, const pii& b) {
                return a.first < b.first;
            });
            std::vector<int> col;
            col.reserve(nodes.size());
            for (const auto& [depth, val] : nodes) {
                col.push_back(val);
            }
            ans.push_back(std::move(col));
        }
        return ans;
    }

private:
    void dfs(TreeNode* root, int depth, int offset, 
             std::map<int, std::vector<pii>>& columns) const {
        if (root == nullptr) {
            return;
        }
        columns[offset].emplace_back(depth, root->val);
        dfs(root->left, depth + 1, offset - 1, columns);
        dfs(root->right, depth + 1, offset + 1, columns);
    }
};
