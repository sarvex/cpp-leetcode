/**
 * @brief Get rightmost node at each level using BFS
 * @intuition Level order traversal, first node at each level (processing right first)
 * @approach BFS prioritizing right children, capture first node of each level
 * @complexity Time: O(n), Space: O(w) where w is max width
 */

class Solution final {
public:
    [[nodiscard]] static auto rightSideView(TreeNode* root) -> std::vector<int> {
        std::vector<int> result;
        if (!root) {
            return result;
        }
        
        std::queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            result.push_back(q.front()->val);
            
            for (int k = q.size(); k > 0; --k) {
                auto* node = q.front();
                q.pop();
                
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
            }
        }
        
        return result;
    }
};
