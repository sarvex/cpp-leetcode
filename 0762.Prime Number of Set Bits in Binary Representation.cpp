/**
 * @brief Count numbers in range with prime number of set bits
 * @intuition Numbers up to 10^6 have at most 20 bits; primes <= 20 are small set
 * @approach For each number, count set bits and check if count is in prime set
 * @complexity Time: O(n log n) where n is range size, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int countPrimeSetBits(const int left, const int right) {
        static const std::unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;
        for (int i = left; i <= right; ++i) {
            count += primes.contains(__builtin_popcount(i));
        }
        return count;
    }
};
