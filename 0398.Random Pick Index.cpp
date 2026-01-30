/**
 * @brief Pick random index of target value using reservoir sampling
 * @intuition Reservoir sampling ensures uniform distribution without extra space
 * @approach For kth occurrence, replace result with probability 1/k
 * @complexity Time: O(n) per pick, Space: O(1)
 */
class Solution final {
public:
    explicit Solution(std::vector<int>& nums) : nums_(nums) {}

    [[nodiscard]] auto pick(int target) const -> int {
        int n = 0;
        int ans = 0;
        const auto size = static_cast<int>(nums_.size());

        for (int i = 0; i < size; ++i) {
            if (nums_[i] == target) {
                ++n;
                if (rand() % n == 0) {
                    ans = i;
                }
            }
        }

        return ans;
    }

private:
    std::vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
