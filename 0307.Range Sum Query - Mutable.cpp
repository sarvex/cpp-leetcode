/**
 * @brief Binary Indexed Tree for mutable range sum queries
 * @intuition BIT allows efficient point updates and prefix sum queries
 * @approach Use BIT to maintain prefix sums with O(log n) updates and queries
 * @complexity Time: O(log n) per operation, Space: O(n)
 */
class BinaryIndexedTree final {
public:
    explicit BinaryIndexedTree(int n) : n_(n), tree_(n + 1) {}

    void update(int x, int delta) {
        while (x <= n_) {
            tree_[x] += delta;
            x += x & (-x);
        }
    }

    [[nodiscard]] int query(int x) const {
        int sum = 0;
        while (x > 0) {
            sum += tree_[x];
            x -= x & (-x);
        }
        return sum;
    }

private:
    int n_;
    vector<int> tree_;
};

class NumArray final {
public:
    explicit NumArray(const vector<int>& nums) 
        : tree_(static_cast<int>(nums.size())) {
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            tree_.update(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        const int prev = sumRange(index, index);
        tree_.update(index + 1, val - prev);
    }

    [[nodiscard]] int sumRange(int left, int right) const {
        return tree_.query(right + 1) - tree_.query(left);
    }

private:
    BinaryIndexedTree tree_;
};
