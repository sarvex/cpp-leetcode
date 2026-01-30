/**
 * @brief Asteroid collision simulation using stack
 * @intuition Only right-moving and left-moving asteroids can collide
 * @approach Stack of right-moving asteroids, handle left-moving collisions
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> asteroidCollision(const std::vector<int>& asteroids) {
        std::vector<int> stack;
        
        for (const int asteroid : asteroids) {
            if (asteroid > 0) {
                stack.push_back(asteroid);
            } else {
                while (!stack.empty() && stack.back() > 0 && stack.back() < -asteroid) {
                    stack.pop_back();
                }
                if (!stack.empty() && stack.back() == -asteroid) {
                    stack.pop_back();
                } else if (stack.empty() || stack.back() < 0) {
                    stack.push_back(asteroid);
                }
            }
        }
        return stack;
    }
};
