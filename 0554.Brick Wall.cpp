/**
 * @brief Find vertical line crossing minimum bricks using hash map
 * @intuition Line at brick edge crosses zero bricks; maximize edges at same position
 * @approach Count cumulative widths (excluding last brick per row); max count = min crosses
 * @complexity Time: O(n*m), Space: O(n*m) where n=rows, m=bricks per row
 */
class Solution final {
public:
    [[nodiscard]] static int leastBricks(const vector<vector<int>>& wall) {
        unordered_map<int, int> edgeCount;
        
        for (const auto& row : wall) {
            int sum = 0;
            for (size_t i = 0; i + 1 < row.size(); ++i) {
                sum += row[i];
                ++edgeCount[sum];
            }
        }
        
        int maxEdges = 0;
        for (const auto& [_, count] : edgeCount) {
            maxEdges = max(maxEdges, count);
        }
        
        return static_cast<int>(wall.size()) - maxEdges;
    }
};
