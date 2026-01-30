/**
 * @brief Minimize total distance for squirrel to collect all nuts
 * @intuition All nuts go to tree and back except first; optimize first nut choice
 * @approach Total = 2*sum(dist to tree); save most by picking nut where tree_dist - squirrel_dist is max
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minDistance(int height, int width,
                                          const vector<int>& tree,
                                          const vector<int>& squirrel,
                                          const vector<vector<int>>& nuts) {
        const int tr = tree[0], tc = tree[1];
        const int sr = squirrel[0], sc = squirrel[1];
        
        int totalDist = 0;
        for (const auto& nut : nuts) {
            totalDist += abs(nut[0] - tr) + abs(nut[1] - tc);
        }
        totalDist *= 2;
        
        int ans = INT_MAX;
        for (const auto& nut : nuts) {
            const int distToTree = abs(nut[0] - tr) + abs(nut[1] - tc);
            const int distToSquirrel = abs(nut[0] - sr) + abs(nut[1] - sc);
            ans = min(ans, totalDist - distToTree + distToSquirrel);
        }
        
        return ans;
    }
};
