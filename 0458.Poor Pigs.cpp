/**
 * @brief Find minimum pigs to determine poisoned bucket
 * @intuition Each pig can encode (rounds+1) states via death timing
 * @approach Need (rounds+1)^pigs >= buckets
 * @complexity Time: O(log buckets) Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] auto poorPigs(int buckets, int minutesToDie, int minutesToTest) const -> int {
        const int base = minutesToTest / minutesToDie + 1;
        int res = 0;

        for (int p = 1; p < buckets; p *= base) {
            ++res;
        }

        return res;
    }
};
