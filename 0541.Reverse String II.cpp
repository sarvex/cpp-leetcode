/**
 * @brief Reverse first k characters in every 2k chunk
 * @intuition Process string in chunks of 2k, reversing first k chars of each chunk
 * @approach Iterate with step 2k, reverse from i to min(i+k, n) using std::reverse
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static string reverseStr(string s, const int k) {
        const int n = static_cast<int>(s.size());
        
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        
        return s;
    }
};
