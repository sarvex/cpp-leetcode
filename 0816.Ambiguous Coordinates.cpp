/**
 * @brief Generate all valid coordinate pairs from ambiguous string
 * @intuition For each split point, generate valid decimal representations
 * @approach Split string at each position into two parts. For each part, try
 *           inserting decimal point at all positions. Validate: no leading zeros
 *           (except "0"), no trailing zeros after decimal point.
 * @complexity Time: O(n^4), Space: O(n^3)
 */
class Solution final {
public:
    [[nodiscard]] static auto ambiguousCoordinates(const std::string& s)
        -> std::vector<std::string> {
        const int n = static_cast<int>(s.size());
        std::vector<std::string> ans;
        
        auto f = [&](int i, int j) -> std::vector<std::string> {
            std::vector<std::string> res;
            for (int k = 1; k <= j - i; ++k) {
                const std::string l = s.substr(i, k);
                const std::string r = s.substr(i + k, j - i - k);
                const bool ok = (l == "0" || l[0] != '0') && 
                               (r.empty() || r.back() != '0');
                if (ok) {
                    res.push_back(l + (k < j - i ? "." : "") + r);
                }
            }
            return res;
        };
        
        for (int i = 2; i < n - 1; ++i) {
            for (const auto& x : f(1, i)) {
                for (const auto& y : f(i, n - 1)) {
                    ans.emplace_back("(" + x + ", " + y + ")");
                }
            }
        }
        return ans;
    }
};
