/**
 * @brief Calendar max concurrent bookings using segment tree
 * @intuition Track maximum overlap using lazy propagation segment tree
 * @approach Dynamic segment tree with lazy propagation for range updates
 * @complexity Time: O(log N) per booking, Space: O(Q log N)
 */
class MyCalendarThree final {
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int l, r, mid;
        int maxVal = 0;
        int lazy = 0;

        Node(int l, int r) : l(l), r(r), mid((l + r) >> 1) {}
    };

    class SegmentTree {
    public:
        SegmentTree() : root_(new Node(1, 1e9 + 1)) {}

        void modify(const int l, const int r, const int val) {
            modify(l, r, val, root_);
        }

        [[nodiscard]] int query(const int l, const int r) {
            return query(l, r, root_);
        }

    private:
        Node* root_;

        void modify(const int l, const int r, const int val, Node* node) {
            if (l > r) return;
            if (node->l >= l && node->r <= r) {
                node->maxVal += val;
                node->lazy += val;
                return;
            }
            pushdown(node);
            if (l <= node->mid) modify(l, r, val, node->left);
            if (r > node->mid) modify(l, r, val, node->right);
            pushup(node);
        }

        [[nodiscard]] int query(const int l, const int r, Node* node) {
            if (l > r) return 0;
            if (node->l >= l && node->r <= r) return node->maxVal;
            pushdown(node);
            int result = 0;
            if (l <= node->mid) result = std::max(result, query(l, r, node->left));
            if (r > node->mid) result = std::max(result, query(l, r, node->right));
            return result;
        }

        static void pushup(Node* node) {
            node->maxVal = std::max(node->left->maxVal, node->right->maxVal);
        }

        static void pushdown(Node* node) {
            if (!node->left) node->left = new Node(node->l, node->mid);
            if (!node->right) node->right = new Node(node->mid + 1, node->r);
            if (node->lazy) {
                node->left->maxVal += node->lazy;
                node->right->maxVal += node->lazy;
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
                node->lazy = 0;
            }
        }
    };

public:
    MyCalendarThree() : tree_(std::make_unique<SegmentTree>()) {}

    [[nodiscard]] int book(const int start, const int end) {
        tree_->modify(start + 1, end, 1);
        return tree_->query(1, 1e9 + 1);
    }

private:
    std::unique_ptr<SegmentTree> tree_;
};
