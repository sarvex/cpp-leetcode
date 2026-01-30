/**
 * @brief Precompute nearest occurrence of each color from both directions
 * @intuition For each position, distance to nearest color is min of left and right closest
 * @approach Build arrays tracking nearest occurrence of each color going left and right.
 *           For each query, answer is minimum of left[i][c] distance and right[i][c] distance.
 * @complexity Time: O(n + q), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> shortestDistanceColor(const vector<int>& colors,
                                                           const vector<vector<int>>& queries) {
        const int n = colors.size();
        constexpr int inf = 1 << 30;
        vector<vector<int>> right(n + 1, vector<int>(3, inf));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                right[i][j] = right[i + 1][j];
            }
            right[i][colors[i] - 1] = i;
        }
        vector<vector<int>> left(n + 1, vector<int>(3, -inf));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                left[i][j] = left[i - 1][j];
            }
            left[i][colors[i - 1] - 1] = i - 1;
        }
        vector<int> ans;
        for (const auto& q : queries) {
            int i = q[0], c = q[1] - 1;
            int d = min(i - left[i + 1][c], right[i][c] - i);
            ans.push_back(d > n ? -1 : d);
        }
        return ans;
    }
};
