/**
 * @brief Binary search on length with rolling hash verification
 * @intuition Binary search for longest duplicate; use rolling hash to find duplicates
 * @approach Rabin-Karp rolling hash with binary search on substring length
 * @complexity Time: O(n log n), Space: O(n)
 */
using ULL = unsigned long long;

class Solution final {
public:
    [[nodiscard]] static string longestDupSubstring(const string& s) {
        const int n = s.size();
        constexpr int base = 131;
        
        vector<ULL> p(n + 1), h(n + 1);
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        
        auto check = [&](const int len) -> string {
            unordered_set<ULL> vis;
            for (int i = 1; i + len - 1 <= n; ++i) {
                const int j = i + len - 1;
                const ULL t = h[j] - h[i - 1] * p[j - i + 1];
                if (vis.contains(t)) return s.substr(i - 1, len);
                vis.insert(t);
            }
            return "";
        };
        
        int left = 0, right = n;
        string ans;
        while (left < right) {
            const int mid = (left + right + 1) >> 1;
            string t = check(mid);
            if (t.empty()) {
                right = mid - 1;
            } else {
                left = mid;
                ans = t;
            }
        }
        return ans;
    }
};
