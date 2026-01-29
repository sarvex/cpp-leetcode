/**
 * @brief Find two numbers summing to target in sorted array using binary search
 * @intuition For each number, binary search for its complement
 * @approach Iterate and use lower_bound for O(log n) complement search
 * @complexity Time: O(n log n), Space: O(1)
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto twoSum(vector<int>& numbers, int target) const -> vector<int> {
        const int n = static_cast<int>(numbers.size());
        
        for (int i = 0; ; ++i) {
            const int complement = target - numbers[i];
            auto it = std::lower_bound(numbers.begin() + i + 1, numbers.end(), complement);
            const int j = static_cast<int>(it - numbers.begin());
            
            if (j < n && numbers[j] == complement) {
                return {i + 1, j + 1};  // 1-indexed
            }
        }
    }
};
