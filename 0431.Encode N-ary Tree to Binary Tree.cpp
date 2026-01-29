/**
 * @brief Encode n-ary tree to binary tree and decode back
 * @intuition First child becomes left, siblings become right chain
 * @approach Encode: left=first child, right=next sibling; Decode: reverse
 * @complexity Time: O(n) Space: O(n)
 */
#include <vector>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Codec final {
public:
    [[nodiscard]] auto encode(Node* root) const -> TreeNode* {
        if (!root) {
            return nullptr;
        }

        auto* node = new TreeNode(root->val);

        if (root->children.empty()) {
            return node;
        }

        TreeNode* left = encode(root->children[0]);
        node->left = left;

        for (std::size_t i = 1; i < root->children.size(); ++i) {
            left->right = encode(root->children[i]);
            left = left->right;
        }

        return node;
    }

    [[nodiscard]] auto decode(TreeNode* data) const -> Node* {
        if (!data) {
            return nullptr;
        }

        auto* node = new Node(data->val, std::vector<Node*>());

        if (!data->left) {
            return node;
        }

        TreeNode* left = data->left;
        while (left) {
            node->children.push_back(decode(left));
            left = left->right;
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
