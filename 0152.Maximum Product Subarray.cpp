/**
 * @brief Find max product subarray using DP tracking min and max
 * @intuition Negative numbers can flip min to max, track both
 * @approach Track current max and min products ending at each position
 * @complexity Time: O(n), Space: O(1)
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto maxProduct(vector<int>& nums) const -> int {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            const int prevMax = maxProd;
            const int prevMin = minProd;
            
            maxProd = std::max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            minProd = std::min({nums[i], prevMax * nums[i], prevMin * nums[i]});
            result = std::max(result, maxProd);
        }
        
        return result;
    }
};
