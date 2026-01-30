/**
 * @brief Check if global inversions equal local inversions
 * @intuition Global >= local always; equal iff no non-adjacent inversions
 * @approach Check if max of prefix (excluding last) ever exceeds current element
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isIdealPermutation(const std::vector<int>& nums) {
        int maxSoFar = 0;
        for (size_t i = 2; i < nums.size(); ++i) {
            maxSoFar = std::max(maxSoFar, nums[i - 2]);
            if (maxSoFar > nums[i]) {
                return false;
            }
        }
        return true;
    }
};
