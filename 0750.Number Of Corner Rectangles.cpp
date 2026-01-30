/**
 * @brief Count corner rectangles in binary grid
 * @intuition For each row pair of 1s, count how many previous rows had same pair
 * @approach Track column pairs with 1s; for each new pair, add previous count
 * @complexity Time: O(m*n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int countCornerRectangles(const std::vector<std::vector<int>>& grid) {
        const int n = static_cast<int>(grid[0].size());
        int result = 0;
        std::map<std::pair<int, int>, int> pairCounts;
        
        for (const auto& row : grid) {
            for (int i = 0; i < n; ++i) {
                if (row[i]) {
                    for (int j = i + 1; j < n; ++j) {
                        if (row[j]) {
                            result += pairCounts[{i, j}];
                            ++pairCounts[{i, j}];
                        }
                    }
                }
            }
        }
        return result;
    }
};
