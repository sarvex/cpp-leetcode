/**
 * @brief Check if start can transform to end via LR swaps
 * @intuition L can move left, R can move right; relative order preserved
 * @approach Two pointers: match L and R, verify movement constraints
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool canTransform(const std::string& start, const std::string& end) {
        const int n = static_cast<int>(start.size());
        int i = 0, j = 0;
        
        while (true) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            
            ++i;
            ++j;
        }
    }
};
