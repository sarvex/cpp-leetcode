/**
 * @brief Single-pass min tracking for max profit in stock prices
 * @intuition Track the minimum price so far and compute the max profit at each step
 * @approach Iterate through prices, updating the minimum and calculating profit on the fly
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto maxProfit(const std::vector<int>& prices) -> int {
        if (prices.empty()) {
            return 0;
        }
        
        int minPrice = prices.front();
        int profit = 0;
        
        for (const auto price : prices) {
            profit = std::max(profit, price - minPrice);
            minPrice = std::min(minPrice, price);
        }
        
        return profit;
    }
};
