/**
 * @brief Check if string forms additive sequence
 * @intuition Try all possible first two numbers, then verify sequence
 * @approach Enumerate starting pairs, recursively check if rest follows additive pattern
 * @complexity Time: O(n^3), Space: O(n) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static bool isAdditiveNumber(const string& num) {
        const int n = static_cast<int>(num.size());
        for (int i = 1; i < min(n - 1, 19); ++i) {
            for (int j = i + 1; j < min(n, i + 19); ++j) {
                if (i > 1 && num[0] == '0') {
                    break;
                }
                if (j - i > 1 && num[i] == '0') {
                    continue;
                }
                const auto a = stoll(num.substr(0, i));
                const auto b = stoll(num.substr(i, j - i));
                if (dfs(a, b, num.substr(j))) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    [[nodiscard]] static bool dfs(long long a, long long b, const string& num) {
        if (num.empty()) {
            return true;
        }
        if (a + b > 0 && num[0] == '0') {
            return false;
        }
        for (int i = 1; i < min(static_cast<int>(num.size()) + 1, 19); ++i) {
            if (a + b == stoll(num.substr(0, i))) {
                if (dfs(b, a + b, num.substr(i))) {
                    return true;
                }
            }
        }
        return false;
    }
};
