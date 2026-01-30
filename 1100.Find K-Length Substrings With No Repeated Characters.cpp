/**
 * @brief Sliding window to count valid k-length substrings
 * @intuition Use a sliding window of size k and track character frequencies to detect duplicates
 * @approach Maintain a window of size k using a hash map to count characters. A window is valid
 *           when all k characters are unique (map size equals k). Slide the window and update counts.
 * @complexity Time: O(n), Space: O(min(k, 26))
 */
class Solution final {
public:
    [[nodiscard]] static int numKLenSubstrNoRepeats(const string& s, const int k) {
        const int n = s.size();
        if (n < k) {
            return 0;
        }
        unordered_map<char, int> cnt;
        for (int i = 0; i < k; ++i) {
            ++cnt[s[i]];
        }
        int ans = cnt.size() == k;
        for (int i = k; i < n; ++i) {
            ++cnt[s[i]];
            if (--cnt[s[i - k]] == 0) {
                cnt.erase(s[i - k]);
            }
            ans += cnt.size() == k;
        }
        return ans;
    }
};
