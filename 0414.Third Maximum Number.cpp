/**
 * @brief Find third distinct maximum, or maximum if fewer than 3 distinct
 * @intuition Track top 3 distinct values while iterating
 * @approach Use LONG_MIN as sentinel to detect unset values
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto thirdMax(const std::vector<int>& nums) -> int {
        long m1 = LONG_MIN;
        long m2 = LONG_MIN;
        long m3 = LONG_MIN;

        for (const int num : nums) {
            if (num == m1 || num == m2 || num == m3) {
                continue;
            }
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            } else if (num > m2) {
                m3 = m2;
                m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }

        return static_cast<int>(m3 != LONG_MIN ? m3 : m1);
    }
};
