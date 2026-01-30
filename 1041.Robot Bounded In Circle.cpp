/**
 * @brief Track robot position and direction after one cycle
 * @intuition Robot returns to origin if: ends at origin OR direction changed
 * @approach Simulate instructions, check final position and direction
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isRobotBounded(const string& instructions) {
        int dist[4]{};
        int k = 0;
        for (const char c : instructions) {
            if (c == 'L') {
                k = (k + 1) % 4;
            } else if (c == 'R') {
                k = (k + 3) % 4;
            } else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || k;
    }
};
