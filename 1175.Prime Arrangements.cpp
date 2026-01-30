/**
 * @brief Count permutations where primes are at prime indices
 * @intuition Primes at prime indices, composites at composite indices: factorial of each count
 * @approach Count primes up to n using sieve. Answer is factorial(primes) * factorial(non-primes) mod 10^9+7.
 * @complexity Time: O(n log log n) for sieve, Space: O(n)
 */
class Solution final {
private:
    static constexpr int MOD = 1e9 + 7;

    [[nodiscard]] static long long factorial(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }

    [[nodiscard]] static int countPrimes(int n) {
        vector<bool> primes(n + 1, true);
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                ++cnt;
                for (int j = i + i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return cnt;
    }

public:
    [[nodiscard]] static int numPrimeArrangements(const int n) {
        int cnt = countPrimes(n);
        long long ans = factorial(cnt) * factorial(n - cnt);
        return static_cast<int>(ans % MOD);
    }
};
