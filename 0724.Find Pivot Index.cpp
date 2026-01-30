/**
 * @brief Find pivot index where left sum equals right sum
 * @intuition Track running left sum and decreasing right sum
 * @approach Single pass: maintain left sum, right sum starts as total
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int pivotIndex(const std::vector<int>& nums) {
        int leftSum = 0;
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            rightSum -= nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
