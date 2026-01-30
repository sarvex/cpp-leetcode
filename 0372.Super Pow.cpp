/**
 * @brief Calculate a^b mod 1337 where b is represented as array of digits
 * @intuition Use modular exponentiation: a^[1,2,3] = a^3 * (a^10)^[1,2]
 * @approach Process digits from right to left, multiply by successive powers
 * @complexity Time: O(n * log(10)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto superPow(int a, const std::vector<int>& b) -> int {
        constexpr int mod = 1337;
        long long ans = 1;

        auto qpow = [](long long base, int n) {
            long long result = 1;
            while (n > 0) {
                if (n & 1) {
                    result = result * base % mod;
                }
                base = base * base % mod;
                n >>= 1;
            }
            return static_cast<int>(result);
        };

        int base = a;
        for (int i = static_cast<int>(b.size()) - 1; i >= 0; --i) {
            ans = ans * qpow(base, b[i]) % mod;
            base = qpow(base, 10);
        }

        return static_cast<int>(ans);
    }
};
