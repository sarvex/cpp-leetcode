/**
 * @brief Convert BST to circular sorted doubly linked list in-place
 * @intuition In-order traversal visits nodes in sorted order
 * @approach Track previous node during in-order, link nodes bidirectionally
 * @complexity Time: O(n) Space: O(h) for recursion stack
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution final {
public:
    [[nodiscard]] auto treeToDoublyList(Node* root) -> Node* {
        if (!root) {
            return nullptr;
        }

        prev_ = nullptr;
        head_ = nullptr;
        dfs(root);
        prev_->right = head_;
        head_->left = prev_;

        return head_;
    }

private:
    Node* prev_ = nullptr;
    Node* head_ = nullptr;

    auto dfs(Node* root) -> void {
        if (!root) {
            return;
        }

        dfs(root->left);

        if (prev_) {
            prev_->right = root;
            root->left = prev_;
        } else {
            head_ = root;
        }
        prev_ = root;

        dfs(root->right);
    }
};
