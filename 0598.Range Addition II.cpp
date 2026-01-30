/**
 * @brief Count cells with maximum value after increment operations
 * @intuition All operations increment top-left rectangle; max is at intersection of all
 * @approach Find minimum row bound and column bound across all operations
 * @complexity Time: O(k), Space: O(1) where k is number of operations
 */
class Solution final {
public:
    [[nodiscard]] static int maxCount(int m, int n, const vector<vector<int>>& ops) {
        for (const auto& op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
