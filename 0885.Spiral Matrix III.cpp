/**
 * @brief Generate spiral path from starting position
 * @intuition Spiral expands: move 1 right, 1 down, 2 left, 2 up, 3 right, etc.
 * @approach Simulate spiral movement. Direction changes after each segment.
 *           Segment lengths alternate: k, k, k+1, k+1, k+2, k+2, etc.
 * @complexity Time: O(max(rows, cols)^2), Space: O(rows * cols)
 */
class Solution final {
public:
    [[nodiscard]] static auto spiralMatrixIII(int rows, int cols,
                                               int rStart, int cStart)
        -> std::vector<std::vector<int>> {
        const int total = rows * cols;
        std::vector<std::vector<int>> ans;
        ans.push_back({rStart, cStart});
        
        if (total == 1) return ans;
        
        for (int k = 1;; k += 2) {
            std::vector<std::vector<int>> dirs = {
                {0, 1, k}, {1, 0, k}, {0, -1, k + 1}, {-1, 0, k + 1}
            };
            
            for (const auto& dir : dirs) {
                const int dr = dir[0], dc = dir[1];
                int steps = dir[2];
                
                while (steps-- > 0) {
                    rStart += dr;
                    cStart += dc;
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                        if (static_cast<int>(ans.size()) == total) {
                            return ans;
                        }
                    }
                }
            }
        }
    }
};
