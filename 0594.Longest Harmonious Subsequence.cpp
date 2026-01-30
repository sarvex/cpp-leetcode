/**
 * @brief Find longest subsequence where max-min = 1
 * @intuition Harmonious means exactly two distinct values differing by 1
 * @approach Count frequencies; for each value x, if x+1 exists, candidate = cnt[x] + cnt[x+1]
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findLHS(const vector<int>& nums) {
        unordered_map<int, int> cnt;
        
        for (const int x : nums) {
            ++cnt[x];
        }
        
        int ans = 0;
        for (const auto& [x, count] : cnt) {
            if (cnt.contains(x + 1)) {
                ans = max(ans, count + cnt[x + 1]);
            }
        }
        
        return ans;
    }
};
