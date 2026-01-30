/**
 * @brief Two-pass DP to find longest mountain subarray
 * @intuition Mountain has increasing then decreasing parts; track both directions
 * @approach First pass: f[i] = length of increasing sequence ending at i.
 *           Second pass: g[i] = length of decreasing sequence starting at i.
 *           Mountain at i requires f[i] > 1 and g[i] > 1; length = f[i] + g[i] - 1.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto longestMountain(const std::vector<int>& arr) -> int {
        const int n = static_cast<int>(arr.size());
        std::vector<int> f(n, 1);
        std::vector<int> g(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
        }
        
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                g[i] = g[i + 1] + 1;
                if (f[i] > 1) {
                    ans = std::max(ans, f[i] + g[i] - 1);
                }
            }
        }
        return ans;
    }
};
