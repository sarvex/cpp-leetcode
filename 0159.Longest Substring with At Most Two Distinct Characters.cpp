/**
 * @brief Find longest substring with at most two distinct characters using sliding window
 * @intuition Sliding window expands right, contracts left when exceeding 2 distinct chars
 * @approach Use hash map to track character counts in current window
 * @complexity Time: O(n), Space: O(1) since at most 3 entries in map
 */

class Solution final {
public:
    [[nodiscard]] static auto lengthOfLongestSubstringTwoDistinct(const std::string& s) -> int {
        std::unordered_map<char, int> charCount;
        const int n = static_cast<int>(s.size());
        int maxLen = 0;
        
        for (int left = 0, right = 0; right < n; ++right) {
            ++charCount[s[right]];
            
            while (charCount.size() > 2) {
                if (--charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                ++left;
            }
            
            maxLen = std::max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
