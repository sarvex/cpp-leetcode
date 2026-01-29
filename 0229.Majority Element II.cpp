/**
 * @brief Boyer-Moore voting for elements appearing > n/3 times
 * @intuition At most 2 elements can appear more than n/3 times
 * @approach Track two candidates, verify counts at end
 * @complexity Time: O(n), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto majorityElement(const std::vector<int>& nums) const -> std::vector<int> {
    int count1 = 0;
    int count2 = 0;
    int candidate1 = 0;
    int candidate2 = 1;
    
    for (const int num : nums) {
      if (num == candidate1) {
        ++count1;
      } else if (num == candidate2) {
        ++count2;
      } else if (count1 == 0) {
        candidate1 = num;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = num;
        count2 = 1;
      } else {
        --count1;
        --count2;
      }
    }
    
    std::vector<int> result;
    const auto threshold = nums.size() / 3;
    if (std::count(nums.begin(), nums.end(), candidate1) > static_cast<long>(threshold)) {
      result.push_back(candidate1);
    }
    if (std::count(nums.begin(), nums.end(), candidate2) > static_cast<long>(threshold)) {
      result.push_back(candidate2);
    }
    return result;
  }
};
