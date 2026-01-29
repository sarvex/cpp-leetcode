/**
 * @brief Binary Indexed Tree to count range sums within bounds
 * @intuition Use prefix sums, count pairs where lower <= s[j] - s[i] <= upper
 * @approach Coordinate compress, use BIT for counting in range
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <algorithm>
#include <vector>

class BinaryIndexedTree final {
public:
    explicit BinaryIndexedTree(int n) : n_(n), tree_(n + 1) {}

    void update(int x, int v) {
        while (x <= n_) {
            tree_[x] += v;
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
    std::vector<int> tree_;
};

class Solution final {
public:
    [[nodiscard]] int countRangeSum(const std::vector<int>& nums, int lower, int upper) const {
        using ll = long long;
        const int n = static_cast<int>(nums.size());
        
        std::vector<ll> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        std::vector<ll> sorted;
        sorted.reserve((n + 1) * 3);
        for (int i = 0; i <= n; ++i) {
            sorted.push_back(prefix[i]);
            sorted.push_back(prefix[i] - lower);
            sorted.push_back(prefix[i] - upper);
        }
        std::sort(sorted.begin(), sorted.end());
        sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
        const int m = static_cast<int>(sorted.size());
        
        BinaryIndexedTree tree(m);
        int ans = 0;
        
        for (int i = 0; i <= n; ++i) {
            const int l = static_cast<int>(std::lower_bound(sorted.begin(), sorted.end(), 
                                                            prefix[i] - upper) - sorted.begin()) + 1;
            const int r = static_cast<int>(std::lower_bound(sorted.begin(), sorted.end(), 
                                                            prefix[i] - lower) - sorted.begin()) + 1;
            ans += tree.query(r) - tree.query(l - 1);
            tree.update(static_cast<int>(std::lower_bound(sorted.begin(), sorted.end(), 
                                                          prefix[i]) - sorted.begin()) + 1, 1);
        }
        return ans;
    }
};
