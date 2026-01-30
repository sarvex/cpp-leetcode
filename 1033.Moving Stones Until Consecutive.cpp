/**
 * @brief Compute minimum and maximum moves for three stones
 * @intuition Min moves depend on gaps; max is total positions minus consecutive
 * @approach Sort stones, calculate based on gap sizes
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> numMovesStones(int a, int b, int c) {
        const int x = min({a, b, c});
        const int z = max({a, b, c});
        const int y = a + b + c - x - z;
        int mi = 0, mx = 0;
        if (z - x > 2) {
            mi = (y - x < 3 || z - y < 3) ? 1 : 2;
            mx = z - x - 2;
        }
        return {mi, mx};
    }
};
