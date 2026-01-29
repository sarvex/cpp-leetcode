/**
 * @brief BST iterator using inorder traversal caching
 * @intuition Precompute inorder traversal, then iterate through cached values
 * @approach Store inorder traversal in vector, use index for iteration
 * @complexity Time: O(1) per operation, Space: O(n) for storage
 */

#include <vector>

using std::vector;

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

class BSTIterator final {
private:
    vector<int> values_;
    size_t index_;
    
    auto inorder(TreeNode* node) -> void {
        if (node != nullptr) {
            inorder(node->left);
            values_.push_back(node->val);
            inorder(node->right);
        }
    }
    
public:
    explicit BSTIterator(TreeNode* root) : index_(0) {
        inorder(root);
    }
    
    [[nodiscard]] auto next() -> int {
        return values_[index_++];
    }
    
    [[nodiscard]] auto hasNext() const -> bool {
        return index_ < values_.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
