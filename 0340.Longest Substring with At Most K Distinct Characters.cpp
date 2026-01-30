/**
 * @brief Sliding window for longest substring with at most k distinct chars
 * @intuition Expand window while <= k distinct, shrink when exceeding
 * @approach Use hash map to track char counts, slide window
 * @complexity Time: O(n), Space: O(k)
 */
class Solution final {
public:
    [[nodiscard]] static int lengthOfLongestSubstringKDistinct(const std::string& s, const int k) {
        std::unordered_map<char, int> cnt;
        int left = 0;
        
        for (const char c : s) {
            ++cnt[c];
            if (static_cast<int>(cnt.size()) > k) {
                if (--cnt[s[left]] == 0) {
                    cnt.erase(s[left]);
                }
                ++left;
            }
        }
        return static_cast<int>(s.size()) - left;
    }
};
