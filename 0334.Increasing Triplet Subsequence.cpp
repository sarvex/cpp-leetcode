/**
 * @brief Check if increasing triplet subsequence exists
 * @intuition Track smallest and second smallest values seen so far
 * @approach Maintain two variables, if we find value greater than both, return true
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool increasingTriplet(const std::vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (const int num : nums) {
            if (num > second) {
                return true;
            }
            if (num <= first) {
                first = num;
            } else {
                second = num;
            }
        }
        return false;
    }
};
