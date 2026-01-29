/**
 * @brief Greedy summing of positive price differences for max profit
 * @intuition Buy on every upward trend; sum all gains
 * @approach Use ranges to compute sum of all positive differences between consecutive days
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto maxProfit(const std::vector<int>& prices) -> int {
        auto diffs = prices | std::views::slide(2) 
                           | std::views::transform([](const auto& w) {
                               return std::max(0, w[1] - w[0]);
                             });
        return std::accumulate(diffs.begin(), diffs.end(), 0);
    }
};
