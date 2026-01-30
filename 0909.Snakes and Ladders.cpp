/**
 * @brief BFS to find shortest path in snakes and ladders game
 * @intuition Treat as shortest path problem on graph with special edges
 * @approach BFS from cell 1; handle board's alternating row direction
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int snakesAndLadders(const vector<vector<int>>& board) {
        const int n = static_cast<int>(board.size());
        queue<int> q{{1}};
        const int m = n * n;
        vector<bool> vis(m + 1);
        vis[1] = true;

        for (int ans = 0; !q.empty(); ++ans) {
            for (int k = static_cast<int>(q.size()); k > 0; --k) {
                const int x = q.front();
                q.pop();
                if (x == m) {
                    return ans;
                }
                for (int y = x + 1; y <= min(x + 6, m); ++y) {
                    int i = (y - 1) / n, j = (y - 1) % n;
                    if (i % 2 == 1) {
                        j = n - j - 1;
                    }
                    i = n - i - 1;
                    const int z = board[i][j] == -1 ? y : board[i][j];
                    if (!vis[z]) {
                        vis[z] = true;
                        q.push(z);
                    }
                }
            }
        }
        return -1;
    }
};
