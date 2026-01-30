/**
 * @brief DP with binary search for egg drop problem
 * @intuition For k eggs and n floors, find minimum moves in worst case
 * @approach f[n][k] = minimum moves. Binary search for optimal floor to drop:
 *           balance egg breaks (lower floors) vs survives (upper floors).
 * @complexity Time: O(k * n * log n), Space: O(n * k)
 */
class Solution final {
public:
    [[nodiscard]] static auto superEggDrop(int k, int n) -> int {
        std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1, 0));
        
        auto dfs = [&](auto&& self, int floors, int eggs) -> int {
            if (floors < 1) return 0;
            if (eggs == 1) return floors;
            if (f[floors][eggs] != 0) return f[floors][eggs];
            
            int l = 1, r = floors;
            while (l < r) {
                const int mid = (l + r + 1) >> 1;
                const int breakCase = self(self, mid - 1, eggs - 1);
                const int surviveCase = self(self, floors - mid, eggs);
                if (breakCase <= surviveCase) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            
            return f[floors][eggs] = std::max(self(self, l - 1, eggs - 1),
                                               self(self, floors - l, eggs)) + 1;
        };
        
        return dfs(dfs, n, k);
    }
};
