/**
 * @brief Binary Indexed Tree to count smaller numbers after self
 * @intuition Process from right to left, use BIT to count smaller elements seen
 * @approach Coordinate compress, then use BIT for range counting
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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

class Solution final {
public:
    [[nodiscard]] std::vector<int> countSmaller(std::vector<int>& nums) const {
        std::unordered_set<int> unique(nums.begin(), nums.end());
        std::vector<int> sorted(unique.begin(), unique.end());
        std::sort(sorted.begin(), sorted.end());
        
        std::unordered_map<int, int> rank;
        const int n = static_cast<int>(sorted.size());
        for (int i = 0; i < n; ++i) {
            rank[sorted[i]] = i + 1;
        }
        
        BinaryIndexedTree tree(n);
        std::vector<int> ans(nums.size());
        
        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
            const int x = rank[nums[i]];
            tree.update(x, 1);
            ans[i] = tree.query(x - 1);
        }
        return ans;
    }
};
