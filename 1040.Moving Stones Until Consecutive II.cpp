/**
 * @brief Sliding window for minimum moves, math for maximum moves
 * @intuition Min: find window of size n with most stones; Max: maximize gaps used
 * @approach Sort stones, sliding window for min, calculate max from extreme gaps
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        const int n = stones.size();
        int mi = n;
        const int mx = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        for (int i = 0, j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                ++i;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2) {
                mi = min(mi, 2);
            } else {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return {mi, mx};
    }
};
