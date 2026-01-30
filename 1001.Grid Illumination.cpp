/**
 * @brief Hash map tracking with row/col/diagonal illumination counts
 * @intuition Track lamp positions and count illumination per row, column, and diagonal
 * @approach Store lamps in set, maintain counts for each row/col/diagonal.
 *           For queries, check if any count > 0, then turn off adjacent lamps.
 * @complexity Time: O(L + Q), Space: O(L) where L = lamps, Q = queries
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> gridIllumination(
        const int n,
        const std::vector<std::vector<int>>& lamps,
        const std::vector<std::vector<int>>& queries) {
        
        auto f = [n](const int i, const int j) -> long long {
            return static_cast<long long>(i) * n + j;
        };
        
        std::unordered_set<long long> s;
        std::unordered_map<int, int> row, col, diag1, diag2;
        
        for (const auto& lamp : lamps) {
            const int i = lamp[0], j = lamp[1];
            if (!s.contains(f(i, j))) {
                s.insert(f(i, j));
                ++row[i];
                ++col[j];
                ++diag1[i - j];
                ++diag2[i + j];
            }
        }
        
        const int m = static_cast<int>(queries.size());
        std::vector<int> ans(m);
        
        for (int k = 0; k < m; ++k) {
            const int i = queries[k][0], j = queries[k][1];
            if (row[i] > 0 || col[j] > 0 || diag1[i - j] > 0 || diag2[i + j] > 0) {
                ans[k] = 1;
            }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n || !s.contains(f(x, y))) {
                        continue;
                    }
                    s.erase(f(x, y));
                    --row[x];
                    --col[y];
                    --diag1[x - y];
                    --diag2[x + y];
                }
            }
        }
        return ans;
    }
};
