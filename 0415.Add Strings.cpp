/**
 * @brief Add two non-negative integers represented as strings
 * @intuition Simulate elementary school addition from right to left
 * @approach Process digits with carry, reverse result at end
 * @complexity Time: O(max(m,n)) Space: O(max(m,n))
 */
#include <algorithm>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto addStrings(const std::string& num1, const std::string& num2) const -> std::string {
        int i = static_cast<int>(num1.size()) - 1;
        int j = static_cast<int>(num2.size()) - 1;
        std::string ans;

        for (int c = 0; i >= 0 || j >= 0 || c; --i, --j) {
            const int a = i < 0 ? 0 : num1[i] - '0';
            const int b = j < 0 ? 0 : num2[j] - '0';
            c += a + b;
            ans += std::to_string(c % 10);
            c /= 10;
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    [[nodiscard]] auto subStrings(const std::string& num1, const std::string& num2) const -> std::string {
        std::string n1 = num1;
        std::string n2 = num2;
        const int m = static_cast<int>(n1.size());
        const int n = static_cast<int>(n2.size());
        const bool neg = m < n || (m == n && n1 < n2);

        if (neg) {
            std::swap(n1, n2);
        }

        int i = static_cast<int>(n1.size()) - 1;
        int j = static_cast<int>(n2.size()) - 1;
        std::string ans;

        for (int c = 0; i >= 0; --i, --j) {
            c = (n1[i] - '0') - c - (j < 0 ? 0 : n2[j] - '0');
            ans += std::to_string((c + 10) % 10);
            c = c < 0 ? 1 : 0;
        }

        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }

        if (neg) {
            ans.push_back('-');
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
