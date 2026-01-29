/**
 * @brief Check if words form a valid word square (rows equal columns)
 * @intuition Character at (i,j) must equal character at (j,i) for all valid positions
 * @approach Check symmetry with bounds validation
 * @complexity Time: O(m*n) where m is words count, n is max length Space: O(1)
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto validWordSquare(const std::vector<std::string>& words) const -> bool {
        const int m = static_cast<int>(words.size());

        for (int i = 0; i < m; ++i) {
            const int n = static_cast<int>(words[i].size());
            for (int j = 0; j < n; ++j) {
                if (j >= m || i >= static_cast<int>(words[j].size()) || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
