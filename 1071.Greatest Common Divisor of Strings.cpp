/**
 * @brief GCD of string lengths determines common divisor string
 * @intuition If str1+str2 == str2+str1, GCD exists as prefix of length gcd(|s1|,|s2|)
 * @approach Check concatenation equality, return prefix of GCD length
 * @complexity Time: O(n + m), Space: O(n + m)
 */
class Solution final {
public:
    [[nodiscard]] static string gcdOfStrings(const string& str1, const string& str2) {
        if (str1 + str2 != str2 + str1) return "";
        const int n = __gcd(str1.size(), str2.size());
        return str1.substr(0, n);
    }
};
