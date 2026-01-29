/**
 * @brief Find single number when others appear three times using bit counting
 * @intuition Count bits at each position mod 3 to isolate single number's bits
 * @approach For each bit position, sum across all numbers and mod by 3
 * @complexity Time: O(32n) = O(n), Space: O(1)
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto singleNumber(vector<int>& nums) const -> int {
        int result = 0;
        
        for (int bit = 0; bit < 32; ++bit) {
            int bitCount = 0;
            for (const int num : nums) {
                bitCount += (num >> bit) & 1;
            }
            bitCount %= 3;
            result |= bitCount << bit;
        }
        
        return result;
    }
};
