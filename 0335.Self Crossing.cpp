/**
 * @brief Check if path crosses itself
 * @intuition Three cases of crossing: immediate, after 4 steps, after 5+ steps
 * @approach Check crossing conditions at each step
 * @complexity Time: O(n), Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] bool isSelfCrossing(const std::vector<int>& distance) const {
        const int n = static_cast<int>(distance.size());
        
        for (int i = 3; i < n; ++i) {
            // Case 1: Current line crosses line 3 steps back
            if (distance[i] >= distance[i - 2] && 
                distance[i - 1] <= distance[i - 3]) {
                return true;
            }
            // Case 2: Current line crosses line 4 steps back
            if (i >= 4 && 
                distance[i - 1] == distance[i - 3] && 
                distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
            // Case 3: Current line crosses line 5+ steps back
            if (i >= 5 && 
                distance[i - 2] >= distance[i - 4] && 
                distance[i - 1] <= distance[i - 3] && 
                distance[i] >= distance[i - 2] - distance[i - 4] && 
                distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                return true;
            }
        }
        return false;
    }
};
