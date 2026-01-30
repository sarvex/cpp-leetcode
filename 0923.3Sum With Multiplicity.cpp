/**
 * @brief Count triplets summing to target with multiplicity
 * @intuition Fix two elements, count occurrences of third
 * @approach Maintain suffix frequency; for each pair, lookup complement
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int threeSumMulti(const vector<int>& arr, const int target) {
        constexpr int mod = 1e9 + 7;
        int cnt[101]{};
        for (const int x : arr) {
            ++cnt[x];
        }
        const int n = static_cast<int>(arr.size());
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            --cnt[arr[j]];
            for (int i = 0; i < j; ++i) {
                const int c = target - arr[i] - arr[j];
                if (c >= 0 && c <= 100) {
                    ans = (ans + cnt[c]) % mod;
                }
            }
        }
        return ans;
    }
};
