/**
 * @brief Check if strings can be equal by exactly one swap
 * @intuition Either 2 positions differ and swapping fixes it, or identical with duplicates
 * @approach Count character frequencies in both strings. Must be equal. If strings
 *           differ at exactly 2 positions, swap works. If identical, need duplicate char.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto buddyStrings(const std::string& s,
                                            const std::string& goal) -> bool {
        const int m = static_cast<int>(s.size());
        const int n = static_cast<int>(goal.size());
        if (m != n) return false;
        
        int diff = 0;
        std::array<int, 26> cnt1{}, cnt2{};
        
        for (int i = 0; i < n; ++i) {
            ++cnt1[s[i] - 'a'];
            ++cnt2[goal[i] - 'a'];
            if (s[i] != goal[i]) ++diff;
        }
        
        bool hasDuplicate = false;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) return false;
            if (cnt1[i] > 1) hasDuplicate = true;
        }
        
        return diff == 2 || (diff == 0 && hasDuplicate);
    }
};
