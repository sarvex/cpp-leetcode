/**
 * @brief Two-pointer comparison with backspace handling from end
 * @intuition Process strings backwards, skipping characters deleted by backspace
 * @approach Use two pointers starting from end. Track backspace count for each string.
 *           Skip characters being deleted, then compare current valid characters.
 * @complexity Time: O(n + m), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto backspaceCompare(const std::string& s,
                                                const std::string& t) -> bool {
        int i = static_cast<int>(s.size()) - 1;
        int j = static_cast<int>(t.size()) - 1;
        int skip1 = 0, skip2 = 0;
        
        for (; i >= 0 || j >= 0; --i, --j) {
            while (i >= 0) {
                if (s[i] == '#') {
                    ++skip1;
                    --i;
                } else if (skip1) {
                    --skip1;
                    --i;
                } else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (t[j] == '#') {
                    ++skip2;
                    --j;
                } else if (skip2) {
                    --skip2;
                    --j;
                } else {
                    break;
                }
            }
            
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } else if (i >= 0 || j >= 0) {
                return false;
            }
        }
        return true;
    }
};
