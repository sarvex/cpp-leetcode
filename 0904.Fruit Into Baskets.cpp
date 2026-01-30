/**
 * @brief Sliding window for maximum fruits with at most 2 types
 * @intuition Find longest subarray with at most 2 distinct elements
 * @approach Expand right pointer, shrink left when more than 2 types;
 *           track counts in hash map
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0, j = 0; i < static_cast<int>(fruits.size()); ++i) {
            const int x = fruits[i];
            ++cnt[x];
            while (cnt.size() > 2) {
                const int y = fruits[j++];
                if (--cnt[y] == 0) {
                    cnt.erase(y);
                }
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
