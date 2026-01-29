/**
 * @brief Binary Indexed Trees for mutable 2D range sum queries
 * @intuition Use one BIT per row for efficient updates and queries
 * @approach Maintain BIT for each row, query by summing across rows
 * @complexity Time: O(m log n) per sumRegion, O(log n) per update, Space: O(mn)
 */
#include <memory>
#include <vector>

class BinaryIndexedTree final {
public:
    explicit BinaryIndexedTree(int n) : n_(n), tree_(n + 1) {}

    void update(int x, int delta) {
        while (x <= n_) {
            tree_[x] += delta;
            x += lowbit(x);
        }
    }

    [[nodiscard]] int query(int x) const {
        int sum = 0;
        while (x > 0) {
            sum += tree_[x];
            x -= lowbit(x);
        }
        return sum;
    }

private:
    [[nodiscard]] static constexpr int lowbit(int x) {
        return x & (-x);
    }
    
    int n_;
    std::vector<int> tree_;
};

class NumMatrix final {
public:
    explicit NumMatrix(const std::vector<std::vector<int>>& matrix) {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        trees_.reserve(m);
        
        for (int i = 0; i < m; ++i) {
            trees_.push_back(std::make_unique<BinaryIndexedTree>(n));
            for (int j = 0; j < n; ++j) {
                trees_[i]->update(j + 1, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        const int prev = trees_[row]->query(col + 1) - trees_[row]->query(col);
        trees_[row]->update(col + 1, val - prev);
    }

    [[nodiscard]] int sumRegion(int row1, int col1, int row2, int col2) const {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += trees_[i]->query(col2 + 1) - trees_[i]->query(col1);
        }
        return sum;
    }

private:
    std::vector<std::unique_ptr<BinaryIndexedTree>> trees_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
