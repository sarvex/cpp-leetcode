/**
 * @brief Find longest interval where tiring days exceed non-tiring days
 * @intuition Transform to prefix sum problem: +1 for tiring day (>8h), -1 otherwise
 * @approach Track first occurrence of each prefix sum. When sum > 0, interval from start is valid.
 *           When sum <= 0, look for earliest position with sum-1 (one fewer tiring day).
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int longestWPI(const vector<int>& hours) {
        int ans = 0, s = 0;
        unordered_map<int, int> pos;
        for (int i = 0; i < hours.size(); ++i) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                ans = i + 1;
            } else if (pos.count(s - 1)) {
                ans = max(ans, i - pos[s - 1]);
            }
            if (!pos.count(s)) {
                pos[s] = i;
            }
        }
        return ans;
    }
};
