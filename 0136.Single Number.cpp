/**
 * @brief Find single number using XOR property
 * @intuition XOR of a number with itself is 0, XOR with 0 is itself
 * @approach XOR all numbers, pairs cancel out leaving the single number
 * @complexity Time: O(n), Space: O(1)
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto singleNumber(vector<int>& nums) const -> int {
        int result = 0;
        for (const int num : nums) {
            result ^= num;
        }
        return result;
    }
};
