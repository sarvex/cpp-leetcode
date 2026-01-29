/**
 * @brief Form largest number by custom string concatenation comparison
 * @intuition Compare a+b vs b+a to determine ordering
 * @approach Convert to strings, sort with custom comparator, concatenate
 * @complexity Time: O(n log n * k) where k is avg number length, Space: O(n*k)
 */

class Solution final {
public:
    [[nodiscard]] static auto largestNumber(std::vector<int>& nums) -> std::string {
        std::vector<std::string> strs;
        strs.reserve(nums.size());
        
        for (const int num : nums) {
            strs.push_back(std::to_string(num));
        }
        
        std::ranges::sort(strs, [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });
        
        if (strs[0] == "0") {
            return "0";
        }
        
        std::string result;
        for (const auto& s : strs) {
            result += s;
        }
        
        return result;
    }
};
