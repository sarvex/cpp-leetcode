/**
 * @brief Mask email or phone number according to format rules
 * @intuition Detect type by '@' presence, then apply appropriate masking
 * @approach For email: lowercase, keep first/last char around '@', mask middle.
 *           For phone: extract digits, format with country code if >10 digits.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto maskPII(const std::string& s) -> std::string {
        const auto i = s.find('@');
        
        if (i != std::string::npos) {
            std::string ans;
            ans += std::tolower(s[0]);
            ans += "*****";
            for (std::size_t j = i - 1; j < s.size(); ++j) {
                ans += std::tolower(s[j]);
            }
            return ans;
        }
        
        std::string t;
        for (const char c : s) {
            if (std::isdigit(c)) {
                t += c;
            }
        }
        
        const int cnt = static_cast<int>(t.size()) - 10;
        const std::string suf = "***-***-" + t.substr(t.size() - 4);
        return cnt == 0 ? suf : "+" + std::string(cnt, '*') + "-" + suf;
    }
};
