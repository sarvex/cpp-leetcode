/**
 * @brief Format license key with groups of k characters (uppercase)
 * @intuition First group may have fewer chars, rest have exactly k
 * @approach Count valid chars, determine first group size, build result
 * @complexity Time: O(n), Space: O(n)
 */
#include <algorithm>
#include <cctype>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto licenseKeyFormatting(const std::string& s, int k) const -> std::string {
        const int n = static_cast<int>(s.length());
        const int validChars = n - static_cast<int>(std::count(s.begin(), s.end(), '-'));
        int cnt = validChars % k;
        if (cnt == 0) {
            cnt = k;
        }

        std::string ans;

        for (int i = 0; i < n; ++i) {
            const char c = s[i];
            if (c == '-') {
                continue;
            }
            ans += static_cast<char>(std::toupper(c));
            if (--cnt == 0) {
                cnt = k;
                if (i != n - 1) {
                    ans += '-';
                }
            }
        }

        if (!ans.empty() && ans.back() == '-') {
            ans.pop_back();
        }

        return ans;
    }
};
