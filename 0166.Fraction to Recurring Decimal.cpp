/**
 * @brief Convert fraction to decimal with repeating detection
 * @intuition Repeating decimals occur when same remainder appears twice
 * @approach Use hash map to detect remainder cycles, insert parentheses for repeating part
 * @complexity Time: O(denominator), Space: O(denominator)
 */

#include <cmath>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution final {
public:
    [[nodiscard]] auto fractionToDecimal(int numerator, int denominator) const -> string {
        if (numerator == 0) {
            return "0";
        }
        
        string result;
        const bool negative = (numerator > 0) ^ (denominator > 0);
        if (negative) {
            result += '-';
        }
        
        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));
        
        result += std::to_string(num / den);
        num %= den;
        
        if (num == 0) {
            return result;
        }
        
        result += '.';
        unordered_map<long long, int> remainderPos;
        
        while (num != 0) {
            remainderPos[num] = static_cast<int>(result.size());
            num *= 10;
            result += std::to_string(num / den);
            num %= den;
            
            if (remainderPos.contains(num)) {
                result.insert(remainderPos[num], "(");
                result += ')';
                break;
            }
        }
        
        return result;
    }
};
