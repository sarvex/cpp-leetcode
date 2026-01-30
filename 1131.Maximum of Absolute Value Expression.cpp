/**
 * @brief Find maximum Manhattan-like distance between array elements with index component
 * @intuition Expand absolute value expression into 4 cases based on sign combinations
 * @approach For each of 4 sign combinations (+/- for arr1, +/- for arr2), track min and max
 *           of (a*arr1[i] + b*arr2[i] + i). Answer is maximum range across all combinations.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxAbsValExpr(const vector<int>& arr1, const vector<int>& arr2) {
        constexpr int dirs[5] = {1, -1, -1, 1, 1};
        constexpr int inf = 1 << 30;
        int ans = -inf;
        const int n = arr1.size();
        for (int k = 0; k < 4; ++k) {
            int a = dirs[k], b = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, a * arr1[i] + b * arr2[i] + i);
                mi = min(mi, a * arr1[i] + b * arr2[i] + i);
                ans = max(ans, mx - mi);
            }
        }
        return ans;
    }
};
