/**
 * @brief Find smallest range containing at least one element from each list
 * @intuition Use sliding window on merged sorted list, track list representation
 * @approach Merge all elements with list index, slide window maintaining all lists covered
 * @complexity Time: O(n log n) where n is total elements, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> smallestRange(const vector<vector<int>>& nums) {
        int n = 0;
        for (const auto& v : nums) {
            n += v.size();
        }
        
        vector<pair<int, int>> t(n);
        const int k = nums.size();
        for (int i = 0, j = 0; i < k; ++i) {
            for (const int v : nums[i]) {
                t[j++] = {v, i};
            }
        }
        ranges::sort(t);
        
        int j = 0;
        unordered_map<int, int> cnt;
        vector<int> ans = {-1000000, 1000000};
        
        for (int i = 0; i < n; ++i) {
            const auto [b, v] = t[i];
            ++cnt[v];
            while (static_cast<int>(cnt.size()) == k) {
                const auto [a, w] = t[j];
                const int x = b - a - (ans[1] - ans[0]);
                if (x < 0 || (x == 0 && a < ans[0])) {
                    ans[0] = a;
                    ans[1] = b;
                }
                if (--cnt[w] == 0) {
                    cnt.erase(w);
                }
                ++j;
            }
        }
        return ans;
    }
};
