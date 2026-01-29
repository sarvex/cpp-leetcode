/**
 * @brief Find majority element using Boyer-Moore voting algorithm
 * @intuition Majority element count exceeds half, so it survives cancellation
 * @approach Track candidate and count; switch candidate when count reaches zero
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto majorityElement(const std::vector<int>& nums) -> int {
        int candidate = 0;
        int count = 0;
        
        for (const int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else {
                count += (num == candidate) ? 1 : -1;
            }
        }
        
        return candidate;
    }
};
