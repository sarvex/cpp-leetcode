/**
 * @brief Find the largest number that appears exactly once
 * @intuition Count frequencies and scan from largest to smallest for first unique
 * @approach Count occurrences of each number. Iterate from maximum possible value down,
 *           return first number with count of 1.
 * @complexity Time: O(n + max_val), Space: O(max_val)
 */
class Solution final {
public:
    [[nodiscard]] static int largestUniqueNumber(const vector<int>& nums) {
        int cnt[1001]{};
        for (int x : nums) {
            ++cnt[x];
        }
        for (int x = 1000; x >= 0; --x) {
            if (cnt[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
