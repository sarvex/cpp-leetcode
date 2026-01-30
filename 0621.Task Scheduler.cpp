/**
 * @brief Find minimum intervals to complete all tasks with cooldown
 * @intuition Most frequent task determines minimum time with cooldown gaps
 * @approach Calculate idle slots based on max frequency, fill with other tasks
 * @complexity Time: O(n), Space: O(1) for 26 letters
 */
class Solution final {
public:
    [[nodiscard]] static int leastInterval(const vector<char>& tasks, const int n) {
        vector<int> cnt(26);
        int x = 0;
        for (const char c : tasks) {
            ++cnt[c - 'A'];
            x = max(x, cnt[c - 'A']);
        }
        int s = 0;
        for (const int v : cnt) {
            s += v == x;
        }
        return max(static_cast<int>(tasks.size()), (x - 1) * (n + 1) + s);
    }
};
