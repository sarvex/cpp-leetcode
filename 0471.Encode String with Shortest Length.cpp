/**
 * @brief Encode string with shortest length using k[encoded_string] pattern
 * @intuition DP: try all split points, check if substring can be compressed
 * @approach For each substring, check if it can be formed by repeating a pattern
 * @complexity Time: O(n^3), Space: O(n^2)
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto encode(const std::string& s) const -> std::string {
        const int n = static_cast<int>(s.size());
        std::vector<std::vector<std::string>> f(n, std::vector<std::string>(n));

        auto compress = [&](int i, int j) -> std::string {
            std::string t = s.substr(i, j - i + 1);
            if (t.size() < 5) {
                return t;
            }
            const std::size_t k = (t + t).find(t, 1);
            if (k < t.size()) {
                const int cnt = static_cast<int>(t.size() / k);
                return std::to_string(cnt) + "[" + f[i][i + static_cast<int>(k) - 1] + "]";
            }
            return t;
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                f[i][j] = compress(i, j);
                if (j - i + 1 > 4) {
                    for (int k = i; k < j; ++k) {
                        std::string t = f[i][k] + f[k + 1][j];
                        if (t.size() < f[i][j].size()) {
                            f[i][j] = std::move(t);
                        }
                    }
                }
            }
        }

        return f[0][n - 1];
    }
};
