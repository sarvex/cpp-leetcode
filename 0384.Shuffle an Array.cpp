/**
 * @brief Shuffle array with Fisher-Yates algorithm, support reset
 * @intuition Fisher-Yates ensures uniform random permutation
 * @approach Swap each element with random element from remaining positions
 * @complexity Time: O(n) per operation, Space: O(n)
 */
class Solution final {
public:
    explicit Solution(std::vector<int>& nums)
        : nums_(nums), original_(nums) {}

    [[nodiscard]] auto reset() -> std::vector<int> {
        nums_ = original_;
        return nums_;
    }

    [[nodiscard]] auto shuffle() -> std::vector<int> {
        const auto n = static_cast<int>(nums_.size());
        for (int i = 0; i < n; ++i) {
            const int j = i + rand() % (n - i);
            std::swap(nums_[i], nums_[j]);
        }
        return nums_;
    }

private:
    std::vector<int> nums_;
    std::vector<int> original_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
