/**
 * @brief Determine if target amount can be measured with two jugs
 * @intuition BFS exploring all possible states of jug volumes
 * @approach State space search with fill, empty, and pour operations
 * @complexity Time: O(xy), Space: O(xy)
 */
class Solution final {
public:
    [[nodiscard]] static bool canMeasureWater(const int x, const int y, const int z) {
        using pii = std::pair<int, int>;
        std::stack<pii> stk;
        stk.emplace(0, 0);
        
        auto hash_function = [](const pii& o) { 
            return std::hash<int>()(o.first) ^ std::hash<int>()(o.second); 
        };
        std::unordered_set<pii, decltype(hash_function)> vis(0, hash_function);
        
        while (!stk.empty()) {
            auto st = stk.top();
            stk.pop();
            
            if (vis.contains(st)) {
                continue;
            }
            vis.insert(st);
            
            auto [i, j] = st;
            if (i == z || j == z || i + j == z) {
                return true;
            }
            
            stk.emplace(x, j);
            stk.emplace(i, y);
            stk.emplace(0, j);
            stk.emplace(i, 0);
            
            const int a = std::min(i, y - j);
            const int b = std::min(j, x - i);
            stk.emplace(i - a, j + a);
            stk.emplace(i + b, j - b);
        }
        return false;
    }
};
