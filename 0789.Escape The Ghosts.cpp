/**
 * @brief Check if player can reach target before any ghost
 * @intuition If any ghost can reach target in <= player's distance, player loses
 * @approach Compare Manhattan distances from player and each ghost to target
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool escapeGhosts(const std::vector<std::vector<int>>& ghosts,
                                            const std::vector<int>& target) {
        const int tx = target[0];
        const int ty = target[1];
        const int playerDist = std::abs(tx) + std::abs(ty);
        
        for (const auto& ghost : ghosts) {
            const int ghostDist = std::abs(tx - ghost[0]) + std::abs(ty - ghost[1]);
            if (ghostDist <= playerDist) {
                return false;
            }
        }
        return true;
    }
};
