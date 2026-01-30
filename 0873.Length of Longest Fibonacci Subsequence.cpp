/**
 * @brief DP with hash map for longest Fibonacci-like subsequence
 * @intuition f[i][j] = length of Fibonacci sequence ending at (arr[j], arr[i])
 * @approach For each pair (j, i), check if arr[i] - arr[j] exists earlier in array.
 *           If found at index k, f[i][j] = f[j][k] + 1. Track maximum length.
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto lenLongestFibSubseq(const std::vector<int>& arr) -> int {
        const int n = static_cast<int>(arr.size());
        std::vector<std::vector<int>> f(n, std::vector<int>(n, 2));
        std::unordered_map<int, int> idx;
        
        for (int i = 0; i < n; ++i) {
            idx[arr[i]] = i;
        }
        
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                const int t = arr[i] - arr[j];
                if (auto it = idx.find(t); it != idx.end() && it->second < j) {
                    const int k = it->second;
                    f[i][j] = std::max(f[i][j], f[j][k] + 1);
                    ans = std::max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
