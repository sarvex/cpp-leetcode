/**
 * @brief Maximize candy types sister can eat
 * @intuition Sister eats n/2 candies; max types = min(unique types, n/2)
 * @approach Use set to count unique types, return min of set size and n/2
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int distributeCandies(const vector<int>& candyType) {
        unordered_set<int> types(candyType.begin(), candyType.end());
        return static_cast<int>(min(candyType.size() / 2, types.size()));
    }
};
