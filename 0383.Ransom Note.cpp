/**
 * @brief Check if ransomNote can be constructed from magazine letters
 * @intuition Each letter in magazine can only be used once
 * @approach Count magazine chars, decrement for ransomNote, fail if negative
 * @complexity Time: O(m + n), Space: O(1) - fixed 26 char alphabet
 */
class Solution final {
public:
    [[nodiscard]] static auto canConstruct(const std::string& ransomNote,
                                            const std::string& magazine) -> bool {
        int cnt[26]{};

        for (const char c : magazine) {
            ++cnt[c - 'a'];
        }

        for (const char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
