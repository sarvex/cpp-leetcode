#include <vector>
#include <concepts>
using namespace std;

class Solution {
public:
    /**
     * @brief Two-pointer in-place deduplication allowing at most two occurrences
     *
     * @intuition: Use two pointers - one for reading (current element) and one for
     * writing (insertion position). We can determine if an element should be kept by
     * checking if it's different from the element two positions before the write pointer.
     *
     * @approach: Iterate through the array once, maintaining a write position.
     * For each element, we either:
     * 1. Allow it if we have fewer than 2 elements written
     * 2. Allow it if it's different from the element at (write_pos - 2)
     * This ensures each element appears at most twice while preserving order.
     *
     * @complexity Time: O(n) where n is the array length, single pass through array
     * @complexity Space: O(1) in-place modification with constant extra space
     */
    [[nodiscard]]
    constexpr int removeDuplicates(vector<int>& nums) noexcept {
        if (nums.empty()) return 0;

        size_t writePos = 0;  // Position to write the next valid element
        for (const auto number : nums) {
            if (writePos < 2 || number != nums[writePos - 2]) {
                nums[writePos++] = number;
            }
        }
        return static_cast<int>(writePos);
    }
};
