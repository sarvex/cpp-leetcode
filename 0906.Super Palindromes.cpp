/**
 * @brief Precompute palindrome roots and check if squares are super-palindromes
 * @intuition Generate all palindrome roots, square them, and check if result is palindrome
 * @approach Build palindromes by mirroring digits; precompute all candidates up to sqrt(10^18)
 * @complexity Time: O(sqrt(R) * log(R)), Space: O(sqrt(R))
 */
using ull = unsigned long long;

ull ps[200000];

int init = [] {
    for (int i = 1; i <= 100000; ++i) {
        string s = to_string(i);
        string t1 = s;
        ranges::reverse(t1);
        string t2 = s.substr(0, s.length() - 1);
        ranges::reverse(t2);
        ps[2 * i - 2] = stoull(s + t1);
        ps[2 * i - 1] = stoull(s + t2);
    }
    return 0;
}();

class Solution final {
public:
    [[nodiscard]] static int superpalindromesInRange(const string& left, const string& right) {
        const ull l = stoull(left), r = stoull(right);
        int ans = 0;
        for (const ull p : ps) {
            const ull x = p * p;
            if (x >= l && x <= r && isPalindrome(x)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    [[nodiscard]] static bool isPalindrome(ull x) {
        ull y = 0;
        for (ull t = x; t; t /= 10) {
            y = y * 10 + t % 10;
        }
        return x == y;
    }
};
