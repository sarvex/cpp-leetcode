/**
 * @brief Random pick with blacklist mapping
 * @intuition Map blacklisted numbers in valid range to non-blacklisted numbers beyond
 * @approach Remap blacklist entries < k to available positions >= k using hashmap
 * @complexity Time: O(b) for init, O(1) for pick, Space: O(b) where b is blacklist size
 */
class Solution final {
public:
    Solution(const int n, const std::vector<int>& blacklist) : k_(n - static_cast<int>(blacklist.size())) {
        int i = k_;
        std::unordered_set<int> black(blacklist.begin(), blacklist.end());
        for (const int b : blacklist) {
            if (b < k_) {
                while (black.contains(i)) {
                    ++i;
                }
                mapping_[b] = i++;
            }
        }
    }

    [[nodiscard]] int pick() {
        const int x = std::rand() % k_;
        return mapping_.contains(x) ? mapping_[x] : x;
    }

private:
    int k_;
    std::unordered_map<int, int> mapping_;
};
