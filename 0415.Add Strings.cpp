/**
 * @brief Add two non-negative integers represented as strings
 * @intuition Simulate elementary school addition from right to left
 * @approach Process digits with carry, reverse result at end
 * @complexity Time: O(max(m,n)), Space: O(max(m,n))
 */
class Solution final {
public:
    [[nodiscard]] static auto addStrings(const std::string& num1, const std::string& num2) -> std::string {
        int i = static_cast<int>(num1.size()) - 1;
        int j = static_cast<int>(num2.size()) - 1;
        std::string ans;

        for (int c = 0; i >= 0 || j >= 0 || c != 0; --i, --j) {
            const int a = i < 0 ? 0 : num1[i] - '0';
            const int b = j < 0 ? 0 : num2[j] - '0';
            c += a + b;
            ans += static_cast<char>(c % 10 + '0');
            c /= 10;
        }

        std::ranges::reverse(ans);
        return ans;
    }
};
