/**
 * @brief Sliding window with at most K flips
 * @intuition Maintain window where zeros count <= k, maximize window size
 * @approach Expand right, shrink left when zeros exceed k, track max length
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int longestOnes(const std::vector<int>& nums, const int k) {
        int l = 0, cnt = 0;
        for (const int x : nums) {
            cnt += x ^ 1;
            if (cnt > k) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return static_cast<int>(nums.size()) - l;
    }
};
