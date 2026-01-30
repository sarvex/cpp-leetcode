/**
 * @brief Track maximum height after each falling square
 * @intuition Use segment tree with lazy propagation for range max queries and updates
 * @approach For each square, query max height in landing range, update with new height
 * @complexity Time: O(n log M) where M is coordinate range, Space: O(n log M)
 */
class SegmentTree final {
public:
    SegmentTree() : root_(new Node(1, 1e9)) {}

    void modify(const int l, const int r, const int v) {
        modify(l, r, v, root_);
    }

    [[nodiscard]] int query(const int l, const int r) const {
        return query(l, r, root_);
    }

private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int l, r, mid;
        int v = 0, add = 0;
        
        Node(const int l, const int r) : l(l), r(r), mid((l + r) >> 1) {}
    };
    
    Node* root_;

    void modify(const int l, const int r, const int v, Node* node) {
        if (l > r) {
            return;
        }
        if (node->l >= l && node->r <= r) {
            node->v = v;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) {
            modify(l, r, v, node->left);
        }
        if (r > node->mid) {
            modify(l, r, v, node->right);
        }
        pushup(node);
    }

    [[nodiscard]] int query(const int l, const int r, Node* node) const {
        if (l > r) {
            return 0;
        }
        if (node->l >= l && node->r <= r) {
            return node->v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node->mid) {
            v = max(v, query(l, r, node->left));
        }
        if (r > node->mid) {
            v = max(v, query(l, r, node->right));
        }
        return v;
    }

    static void pushup(Node* node) {
        node->v = max(node->left->v, node->right->v);
    }

    static void pushdown(Node* node) {
        if (!node->left) {
            node->left = new Node(node->l, node->mid);
        }
        if (!node->right) {
            node->right = new Node(node->mid + 1, node->r);
        }
        if (node->add) {
            node->left->v = node->add;
            node->right->v = node->add;
            node->left->add = node->add;
            node->right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution final {
public:
    [[nodiscard]] static vector<int> fallingSquares(const vector<vector<int>>& positions) {
        vector<int> ans;
        SegmentTree tree;
        int mx = 0;
        
        for (const auto& p : positions) {
            const int l = p[0];
            const int w = p[1];
            const int r = l + w - 1;
            const int h = tree.query(l, r) + w;
            mx = max(mx, h);
            ans.push_back(mx);
            tree.modify(l, r, h);
        }
        return ans;
    }
};
