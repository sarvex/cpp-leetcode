/**
 * @brief Minimum operations to get n 'A's using copy-all and paste
 * @intuition Factor n into primes; sum of prime factors gives minimum steps
 * @approach DFS with memoization to find optimal factorization path
 * @complexity Time: O(sqrt(n) * log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minSteps(const int n) {
        vector<int> f(n + 1, -1);
        
        auto dfs = [&](this auto&& dfs, int x) -> int {
            if (x == 1) {
                return 0;
            }
            if (f[x] != -1) {
                return f[x];
            }
            
            int ans = x;
            for (int i = 2; i * i <= x; ++i) {
                if (x % i == 0) {
                    ans = min(ans, dfs(x / i) + i);
                }
            }
            f[x] = ans;
            return ans;
        };
        
        return dfs(n);
    }
};
