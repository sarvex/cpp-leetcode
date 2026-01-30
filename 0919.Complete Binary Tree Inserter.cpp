/**
 * @brief Array-based complete binary tree insertion
 * @intuition Store nodes level-order; parent of node i is at (i-1)/2
 * @approach BFS to build array, insert using parent index formula
 * @complexity Time: O(n) construction, O(1) insert, Space: O(n)
 */
class CBTInserter final {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                auto node = q.front();
                q.pop();
                tree_.push_back(node);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }

    [[nodiscard]] int insert(const int val) {
        auto p = tree_[(tree_.size() - 1) / 2];
        auto node = new TreeNode(val);
        tree_.push_back(node);
        if (!p->left) {
            p->left = node;
        } else {
            p->right = node;
        }
        return p->val;
    }

    [[nodiscard]] TreeNode* get_root() const {
        return tree_[0];
    }

private:
    vector<TreeNode*> tree_;
};
