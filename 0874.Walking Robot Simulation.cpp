/**
 * @brief Simulate robot movement tracking maximum Euclidean distance squared
 * @intuition Process commands in order, avoiding obstacles, tracking furthest point
 * @approach Use hash set for O(1) obstacle lookup. Process turn commands to update
 *           direction. For move commands, step one at a time checking obstacles.
 * @complexity Time: O(n + m * max_steps), Space: O(m)
 */
class Solution final {
public:
    [[nodiscard]] static auto robotSim(const std::vector<int>& commands,
        const std::vector<std::vector<int>>& obstacles) -> int {
        constexpr std::array<int, 5> dirs = {0, 1, 0, -1, 0};
        
        auto hash = [](int x, int y) {
            return static_cast<long long>(x) * 60010 + y;
        };
        
        std::unordered_set<long long> obstacleSet;
        for (const auto& e : obstacles) {
            obstacleSet.insert(hash(e[0], e[1]));
        }
        
        int ans = 0, k = 0;
        int x = 0, y = 0;
        
        for (const int c : commands) {
            if (c == -2) {
                k = (k + 3) % 4;
            } else if (c == -1) {
                k = (k + 1) % 4;
            } else {
                for (int steps = c; steps > 0; --steps) {
                    const int nx = x + dirs[k], ny = y + dirs[k + 1];
                    if (obstacleSet.contains(hash(nx, ny))) break;
                    x = nx;
                    y = ny;
                    ans = std::max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};
