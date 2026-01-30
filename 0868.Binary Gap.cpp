/**
 * @brief Find maximum distance between consecutive 1s in binary representation
 * @intuition Track position of last 1 bit and compute gaps
 * @approach Iterate through bits. When finding a 1, compute distance from
 *           previous 1 position. Track maximum gap.
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto binaryGap(int n) -> int {
        int ans = 0;
        
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n & 1) {
                ans = std::max(ans, cur - pre);
                pre = cur;
            }
            ++cur;
        }
        return ans;
    }
};
