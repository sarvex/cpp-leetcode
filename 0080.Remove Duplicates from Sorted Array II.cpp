/**
 * @brief Two-pointer in-place deduplication allowing at most two occurrences
 * @intuition Use two pointers - one for reading and one for writing position
 * @approach For each element, allow it if fewer than 2 elements written or
 *           if different from the element two positions before the write pointer
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto removeDuplicates(vector<int>& nums) -> int {
        if (nums.empty()) {
            return 0;
        }

        size_t writePos = 0;
        for (const auto num : nums) {
            if (writePos < 2 || num != nums[writePos - 2]) {
                nums[writePos++] = num;
            }
        }
        return static_cast<int>(writePos);
    }
};
