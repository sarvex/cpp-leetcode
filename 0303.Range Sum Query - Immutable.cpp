/**
 * @brief Prefix sum for immutable range sum queries
 * @intuition Precompute prefix sums to answer range queries in O(1)
 * @approach Build prefix sum array, then query as s[right+1] - s[left]
 * @complexity Time: O(n) build, O(1) query, Space: O(n)
 */
class NumArray final {
public:
    explicit NumArray(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        prefix_sum_.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix_sum_[i + 1] = prefix_sum_[i] + nums[i];
        }
    }

    [[nodiscard]] int sumRange(int left, int right) const {
        return prefix_sum_[right + 1] - prefix_sum_[left];
    }

private:
    vector<int> prefix_sum_;
};
