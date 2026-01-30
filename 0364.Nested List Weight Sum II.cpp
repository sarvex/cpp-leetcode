/**
 * @brief Weighted sum with depth increasing from bottom
 * @intuition Total = (maxDepth+1)*sum - weighted sum with normal depths
 * @approach DFS to find max depth and compute normal weighted sum
 * @complexity Time: O(n), Space: O(depth)
 */
class Solution final {
public:
    [[nodiscard]] static int depthSumInverse(std::vector<NestedInteger>& nestedList) {
        int maxDepth = 0;
        int weightedSum = 0;
        int totalSum = 0;
        
        auto dfs = [&](this auto&& dfs, NestedInteger& item, int depth) -> void {
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
