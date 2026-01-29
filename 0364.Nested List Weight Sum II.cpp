/**
 * @brief Weighted sum with depth increasing from bottom
 * @intuition Total = (maxDepth+1)*sum - weighted sum with normal depths
 * @approach DFS to find max depth and compute normal weighted sum
 * @complexity Time: O(n), Space: O(depth)
 */
#include <algorithm>
#include <functional>
#include <vector>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution final {
public:
    [[nodiscard]] int depthSumInverse(std::vector<NestedInteger>& nestedList) const {
        int maxDepth = 0;
        int weightedSum = 0;
        int totalSum = 0;
        
        std::function<void(NestedInteger&, int)> dfs = [&](NestedInteger& item, int depth) {
            maxDepth = std::max(maxDepth, depth);
            if (item.isInteger()) {
                weightedSum += item.getInteger() * depth;
                totalSum += item.getInteger();
            } else {
                for (auto& child : item.getList()) {
                    dfs(child, depth + 1);
                }
            }
        };
        
        for (auto& item : nestedList) {
            dfs(item, 1);
        }
        return (maxDepth + 1) * totalSum - weightedSum;
    }
};
