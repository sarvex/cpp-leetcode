/**
 * @brief Find max rectangle sum no larger than k
 * @intuition Compress to 1D, use prefix sum with ordered set for constraint
 * @approach For each column pair, compute row sums and find max subarray <= k
 * @complexity Time: O(m^2 * n log n), Space: O(n)
 */
#include <algorithm>
#include <set>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int maxSumSubmatrix(const std::vector<std::vector<int>>& matrix, int k) const {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        constexpr int inf = 1 << 30;
        int ans = -inf;
        
        for (int i = 0; i < m; ++i) {
            std::vector<int> sums(n);
            for (int j = i; j < m; ++j) {
                for (int col = 0; col < n; ++col) {
                    sums[col] += matrix[j][col];
                }
                
                std::set<int> prefixSums;
                int prefix = 0;
                prefixSums.insert(0);
                
                for (const int x : sums) {
                    prefix += x;
                    auto it = prefixSums.lower_bound(prefix - k);
                    if (it != prefixSums.end()) {
                        ans = std::max(ans, prefix - *it);
                    }
                    prefixSums.insert(prefix);
                }
            }
        }
        return ans;
    }
};
