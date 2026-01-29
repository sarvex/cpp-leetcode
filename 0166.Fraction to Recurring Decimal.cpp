/**
 * @brief Convert fraction to decimal with repeating detection
 * @intuition Repeating decimals occur when same remainder appears twice
 * @approach Use hash map to detect remainder cycles, insert parentheses for repeating part
 * @complexity Time: O(denominator), Space: O(denominator)
 */

class Solution final {
public:
    [[nodiscard]] static auto fractionToDecimal(int numerator, int denominator) -> std::string {
        if (numerator == 0) {
            return "0";
        }
        
        std::string result;
        const bool negative = (numerator > 0) ^ (denominator > 0);
        if (negative) {
            result += '-';
        }
        
        auto num = std::abs(static_cast<long long>(numerator));
        auto den = std::abs(static_cast<long long>(denominator));
        
        result += std::to_string(num / den);
        num %= den;
        
        if (num == 0) {
            return result;
        }
        
        result += '.';
        std::unordered_map<long long, int> remainderPos;
        
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
