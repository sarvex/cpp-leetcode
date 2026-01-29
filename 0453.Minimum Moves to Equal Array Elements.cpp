/**
 * @brief Find minimum moves to make all elements equal (increment n-1 elements)
 * @intuition Incrementing n-1 elements equals decrementing 1 element
 * @approach Sum of (element - minimum) for all elements
 * @complexity Time: O(n) Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto minMoves(const std::vector<int>& nums) const -> int {
        int s = 0;
        int mi = 1 << 30;

        for (const int x : nums) {
            s += x;
            mi = std::min(mi, x);
        }

        return s - mi * static_cast<int>(nums.size());
    }
};
