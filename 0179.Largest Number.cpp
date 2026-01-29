/**
 * @brief Form largest number by custom string concatenation comparison
 * @intuition Compare a+b vs b+a to determine ordering
 * @approach Convert to strings, sort with custom comparator, concatenate
 * @complexity Time: O(n log n * k) where k is avg number length, Space: O(n*k)
 */

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto largestNumber(vector<int>& nums) const -> string {
        vector<string> strs;
        strs.reserve(nums.size());
        
        for (const int num : nums) {
            strs.push_back(std::to_string(num));
        }
        
        std::ranges::sort(strs, [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // Handle all zeros case
        if (strs[0] == "0") {
            return "0";
        }
        
        string result;
        for (const auto& s : strs) {
            result += s;
        }
        
        return result;
    }
};
