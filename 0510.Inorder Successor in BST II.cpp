/**
 * @brief Find inorder successor in BST with parent pointers
 * @intuition Successor is either leftmost in right subtree or first ancestor where node is in left subtree
 * @approach If right child exists, go right then all the way left. Otherwise, traverse up
 *           while current node is parent's right child; parent is the successor.
 * @complexity Time: O(h), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto inorderSuccessor(Node* node) -> Node* {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }
        while (node->parent && node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
};
