/**
 * @brief Convert integer to base 7 representation
 * @intuition Repeatedly divide by 7 and collect remainders in reverse order
 * @approach Handle zero and negative cases separately. For positive numbers,
 *           extract digits via modulo 7, prepending each to result string.
 * @complexity Time: O(log n), Space: O(log n)
 */
class Solution final {
public:
    [[nodiscard]] static auto convertToBase7(int num) -> string {
        if (num == 0) return "0";
        if (num < 0) return "-" + convertToBase7(-num);
        
        string ans;
        while (num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        return ans;
    }
};
