/**
 * @brief BST iterator using inorder traversal caching
 * @intuition Precompute inorder traversal, then iterate through cached values
 * @approach Store inorder traversal in vector, use index for iteration
 * @complexity Time: O(1) per operation, Space: O(n) for storage
 */

class BSTIterator final {
private:
    std::vector<int> values_;
    std::size_t index_ = 0;
    
    static auto inorder(TreeNode* node, std::vector<int>& result) -> void {
        if (node != nullptr) {
            inorder(node->left, result);
            result.push_back(node->val);
            inorder(node->right, result);
        }
    }
    
public:
    explicit BSTIterator(TreeNode* root) {
        inorder(root, values_);
    }
    
    [[nodiscard]] auto next() -> int {
        return values_[index_++];
    }
    
    [[nodiscard]] auto hasNext() const -> bool {
        return index_ < values_.size();
    }
};
