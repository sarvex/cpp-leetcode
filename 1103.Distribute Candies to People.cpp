/**
 * @brief Simulate candy distribution in round-robin fashion
 * @intuition Give each person incrementing amounts of candy until we run out
 * @approach Iterate through positions giving 1, 2, 3, ... candies each turn, wrapping around
 *           using modulo. Give remaining candies if we don't have enough for the full amount.
 * @complexity Time: O(sqrt(candies)), Space: O(num_people)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> distributeCandies(int candies, const int num_people) {
        vector<int> ans(num_people);
        for (int i = 0; candies > 0; ++i) {
            ans[i % num_people] += min(candies, i + 1);
            candies -= min(candies, i + 1);
        }
        return ans;
    }
};
