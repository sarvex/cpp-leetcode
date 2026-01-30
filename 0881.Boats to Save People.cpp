/**
 * @brief Two-pointer greedy for minimum boats
 * @intuition Sort by weight; pair heaviest with lightest if possible
 * @approach Sort people. Use two pointers: try to pair lightest with heaviest.
 *           If they fit, move both pointers; otherwise only heaviest goes alone.
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto numRescueBoats(std::vector<int>& people,
                                              int limit) -> int {
        std::ranges::sort(people);
        int ans = 0;
        
        for (int i = 0, j = static_cast<int>(people.size()) - 1; i <= j; --j) {
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            ++ans;
        }
        return ans;
    }
};
