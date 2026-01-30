/**
 * @brief Count binary trees where parent = left_child * right_child
 * @intuition For each root, count valid (left, right) pairs from smaller elements
 * @approach Sort array. For each element as root, find factor pairs from smaller
 *           elements. Use DP: f[i] = 1 + sum of f[j]*f[k] for all valid j,k pairs.
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto numFactoredBinaryTrees(std::vector<int>& arr) -> int {
        constexpr int mod = 1'000'000'007;
        std::ranges::sort(arr);
        
        std::unordered_map<int, int> idx;
        const int n = static_cast<int>(arr.size());
        for (int i = 0; i < n; ++i) {
            idx[arr[i]] = i;
        }
        
        std::vector<long> f(n, 1);
        for (int i = 0; i < n; ++i) {
            const int a = arr[i];
            for (int j = 0; j < i; ++j) {
                const int b = arr[j];
                if (a % b == 0) {
                    const int c = a / b;
                    if (idx.count(c)) {
                        const int k = idx[c];
                        f[i] = (f[i] + f[j] * f[k]) % mod;
                    }
                }
            }
        }
        
        long ans = 0;
        for (const long v : f) {
            ans = (ans + v) % mod;
        }
        return static_cast<int>(ans);
    }
};
