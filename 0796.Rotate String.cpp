/**
 * @brief Check if s can be rotated to become goal
 * @intuition Any rotation of s is a substring of s + s
 * @approach Check length equality and if goal is in doubled s
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool rotateString(const std::string& s, const std::string& goal) {
        return s.size() == goal.size() && (s + s).find(goal) != std::string::npos;
    }
};
