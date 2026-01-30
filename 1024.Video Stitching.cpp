/**
 * @brief Greedy interval covering
 * @intuition At each position, extend reach maximally using available clips
 * @approach Track furthest reach from each start, greedily jump to farthest
 * @complexity Time: O(n + time), Space: O(time)
 */
class Solution final {
public:
    [[nodiscard]] static int videoStitching(const vector<vector<int>>& clips, const int time) {
        vector<int> last(time);
        for (const auto& v : clips) {
            const int a = v[0], b = v[1];
            if (a < time) {
                last[a] = max(last[a], b);
            }
        }
        int mx = 0, ans = 0;
        int pre = 0;
        for (int i = 0; i < time; ++i) {
            mx = max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
};
