/**
 * @brief Check if array can be divided into k-length strictly increasing subsequences
 * @intuition The maximum frequency of any element limits how many subsequences we need
 * @approach Find the maximum count of consecutive identical elements. If this count times k
 *           exceeds array size, division is impossible.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool canDivideIntoSubsequences(const vector<int>& nums, const int k) {
        int cnt = 0;
        int a = 0;
        for (const int b : nums) {
            cnt = a == b ? cnt + 1 : 1;
            if (cnt * k > nums.size()) {
                return false;
            }
            a = b;
        }
        return true;
    }
};
