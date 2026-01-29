/**
 * @brief Monotonic stack for BST preorder verification
 * @intuition Track lower bound while popping smaller elements
 * @approach Use stack to simulate BST structure, maintain min value
 * @complexity Time: O(n), Space: O(n)
 */
#include <climits>
#include <stack>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto verifyPreorder(const std::vector<int>& preorder) const -> bool {
    std::stack<int> stk;
    int lowerBound = INT_MIN;
    
    for (const int value : preorder) {
      if (value < lowerBound) {
        return false;
      }
      while (!stk.empty() && stk.top() < value) {
        lowerBound = stk.top();
        stk.pop();
      }
      stk.push(value);
    }
    return true;
  }
};
