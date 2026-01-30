/**
 * @brief Sum of all root-to-leaf paths in encoded binary tree
 * @intuition Decode node positions from encoded format, DFS to sum paths
 * @approach Map encoded nodes, traverse tree adding path sums at leaves
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int pathSum(const vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const int num : nums) {
            mp[num / 10] = num % 10;
        }
        
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int node, int sum) -> void {
            if (!mp.count(node)) {
                return;
            }
            sum += mp[node];
            const int d = node / 10;
            const int p = node % 10;
            const int l = (d + 1) * 10 + (p * 2) - 1;
            const int r = l + 1;
            
            if (!mp.count(l) && !mp.count(r)) {
                ans += sum;
                return;
            }
            dfs(l, sum);
            dfs(r, sum);
        };
        
        dfs(11, 0);
        return ans;
    }
};
