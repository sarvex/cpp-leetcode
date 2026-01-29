/**
 * @brief Get specific row of Pascal's triangle with O(k) space
 * @intuition Update row in-place from right to left to avoid overwriting
 * @approach Start with all 1s, iteratively update using previous values
 * @complexity Time: O(k^2), Space: O(k)
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto getRow(int rowIndex) const -> vector<int> {
        vector<int> row(rowIndex + 1, 1);
        
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        
        return row;
    }
};
