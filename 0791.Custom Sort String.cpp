/**
 * @brief Sort string based on custom character order
 * @intuition Assign priority based on position in order string
 * @approach Map each char to its order index, sort by priority
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::string customSortString(const std::string& order, 
                                                       std::string s) {
        std::array<int, 26> priority{};
        for (size_t i = 0; i < order.size(); ++i) {
            priority[order[i] - 'a'] = static_cast<int>(i);
        }
        
        std::ranges::sort(s, [&](const char a, const char b) {
            return priority[a - 'a'] < priority[b - 'a'];
        });
        return s;
    }
};
