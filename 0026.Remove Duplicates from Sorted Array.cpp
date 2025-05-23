#include <vector>
#include <ranges>
#include <algorithm>

class Solution final {
public:
    /**
     * Two-pointer in-place array deduplication using ranges
     *
     * @intuition: Since array is sorted, duplicates are adjacent. We can use a write pointer
     * that only advances when we find a new unique element.
     *
     * @approach: Use two pointers - one for the current unique position (writePos) and one
     * for scanning (readPos). When we find a new unique element, we write it to the next
     * writePos position.
     *
     * @complexity Time: O(n) where n is array length. Single pass through array
     * @complexity Space: O(1) constant extra space used
     */
    [[nodiscard]]
    constexpr int removeDuplicates(std::vector<int>& nums) noexcept {
        if (nums.empty()) {
            return 0;
        }

        auto writePos = 0;
        for (auto readPos : std::views::iota(1u, nums.size())) {
            if (nums[readPos] != nums[writePos]) {
                ++writePos;
                nums[writePos] = nums[readPos];
            }
        }

        return writePos + 1;
    }
};
