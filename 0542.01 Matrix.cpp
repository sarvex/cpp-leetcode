/**
 * @brief Multi-source BFS from all zero cells
 * @intuition Distance to nearest 0 can be found by BFS starting from all zeros simultaneously
 * @approach Initialize queue with all zeros (distance 0), then BFS to update neighbors' distances
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
        const int m = static_cast<int>(mat.size());
        const int n = static_cast<int>(mat[0].size());
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; ++d) {
                const int x = row + dirs[d];
                const int y = col + dirs[d + 1];
                
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[row][col] + 1;
                    q.emplace(x, y);
                }
            }
        }
        
        return ans;
    }
};
