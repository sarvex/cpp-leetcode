/**
 * @brief Find smallest letter greater than target using binary search
 * @intuition Array is sorted; use upper_bound for first strictly greater element
 * @approach Binary search with wraparound to first element if none found
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static char nextGreatestLetter(const std::vector<char>& letters, 
                                                  const char target) {
        const auto it = std::ranges::upper_bound(letters, target);
        return it == letters.end() ? letters.front() : *it;
    }
};
