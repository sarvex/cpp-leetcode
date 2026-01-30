/**
 * @brief Range module with dynamic segment tree
 * @intuition Track range coverage with lazy propagation for efficient updates
 * @approach Dynamic segment tree with lazy propagation for add/remove/query operations
 * @complexity Time: O(log N) per operation, Space: O(Q log N) where Q is query count
 */
class RangeModule final {
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int lazy = 0;
        bool covered = false;
    };

public:
    RangeModule() : root_(new Node()) {}

    void addRange(const int left, const int right) {
        modify(left, right - 1, 1, 1, 1e9, root_);
    }

    [[nodiscard]] bool queryRange(const int left, const int right) {
        return query(left, right - 1, 1, 1e9, root_);
    }

    void removeRange(const int left, const int right) {
        modify(left, right - 1, -1, 1, 1e9, root_);
    }

private:
    Node* root_;

    void modify(const int left, const int right, const int v, const int l, const int r, Node* node) {
        if (l >= left && r <= right) {
            node->covered = (v == 1);
            node->lazy = v;
            return;
        }
        pushdown(node);
        const int mid = (l + r) >> 1;
        if (left <= mid) {
            modify(left, right, v, l, mid, node->left);
        }
        if (right > mid) {
            modify(left, right, v, mid + 1, r, node->right);
        }
        pushup(node);
    }

    [[nodiscard]] bool query(const int left, const int right, const int l, const int r, Node* node) {
        if (l >= left && r <= right) {
            return node->covered;
        }
        pushdown(node);
        const int mid = (l + r) >> 1;
        bool result = true;
        if (left <= mid) {
            result = result && query(left, right, l, mid, node->left);
        }
        if (right > mid) {
            result = result && query(left, right, mid + 1, r, node->right);
        }
        return result;
    }

    static void pushup(Node* node) {
        node->covered = node->left && node->left->covered && node->right && node->right->covered;
    }

    static void pushdown(Node* node) {
        if (!node->left) {
            node->left = new Node();
        }
        if (!node->right) {
            node->right = new Node();
        }
        if (node->lazy) {
            node->left->lazy = node->right->lazy = node->lazy;
            node->left->covered = node->right->covered = (node->lazy == 1);
            node->lazy = 0;
        }
    }
};
