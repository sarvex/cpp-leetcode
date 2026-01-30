/**
 * @brief Check if any permutation of s1 is substring of s2 using sliding window
 * @intuition Window of size len(s1) in s2 should have same char frequencies as s1
 * @approach Sliding window with char count array; track how many chars still needed
 * @complexity Time: O(n), Space: O(1) where n = len(s2)
 */
class Solution final {
public:
    [[nodiscard]] static bool checkInclusion(const string& s1, const string& s2) {
        int need = 0;
        int cnt[26]{};
        
        for (const char c : s1) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());
        
        for (int i = 0; i < n; ++i) {
            int idx = s2[i] - 'a';
            if (--cnt[idx] == 0) {
                --need;
            }
            
            if (i >= m) {
                idx = s2[i - m] - 'a';
                if (++cnt[idx] == 1) {
                    ++need;
                }
            }
            
            if (need == 0) {
                return true;
            }
        }
        
        return false;
    }
};
