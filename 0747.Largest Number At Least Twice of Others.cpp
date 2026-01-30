/**
 * @brief Find dominant index where max is at least twice of all others
 * @intuition Find maximum, then verify it's at least twice all other elements
 * @approach Two passes: find max index, then verify dominance condition
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int dominantIndex(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int maxIdx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[maxIdx] < nums[i]) {
                maxIdx = i;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i != maxIdx && nums[maxIdx] < nums[i] * 2) {
                return -1;
            }
        }
        return maxIdx;
    }
};
