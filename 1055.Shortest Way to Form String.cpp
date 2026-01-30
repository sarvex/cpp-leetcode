/**
 * @brief Greedy subsequence matching with multiple passes
 * @intuition Match as many target chars as possible per source pass
 * @approach Iterate source repeatedly, greedily match target characters
 * @complexity Time: O(m * n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int shortestWay(const string& source, const string& target) {
        const int m = source.size(), n = target.size();
        int ans = 0, j = 0;
        while (j < n) {
            int i = 0;
            bool ok = false;
            while (i < m && j < n) {
                if (source[i] == target[j]) {
                    ok = true;
                    ++j;
                }
                ++i;
            }
            if (!ok) {
                return -1;
            }
            ++ans;
        }
        return ans;
    }
};
