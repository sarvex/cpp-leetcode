/**
 * @brief Backtracking to generate all valid IP addresses
 * @intuition IP has 4 parts, each 0-255 with no leading zeros
 * @approach DFS trying 1-3 digit segments; validate each part; collect when 4 valid parts found
 * @complexity Time: O(3^4 * n), Space: O(n) for recursion and result
 */
class Solution final {
public:
    [[nodiscard]] static auto restoreIpAddresses(const string& s) -> vector<string> {
        const int n = static_cast<int>(s.size());
        vector<string> result;
        vector<string> parts;
        
        auto dfs = [&](this auto&& dfs, const int i) -> void {
            if (i >= n && parts.size() == 4) {
                result.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
                return;
            }
            if (i >= n || parts.size() >= 4) {
                return;
            }
            
            int value = 0;
            for (int j = i; j < min(n, i + 3); ++j) {
                value = value * 10 + (s[j] - '0');
                if (value > 255 || (j > i && s[i] == '0')) {
                    break;
                }
                parts.push_back(s.substr(i, j - i + 1));
                dfs(j + 1);
                parts.pop_back();
            }
        };
        
        dfs(0);
        return result;
    }
};
