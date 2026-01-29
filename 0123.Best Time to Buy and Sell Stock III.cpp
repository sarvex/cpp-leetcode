/**
 * @brief Max profit with at most 2 transactions using state machine DP
 * @intuition Track 4 states: first buy, first sell, second buy, second sell
 * @approach Update all states in sequence for each price
 * @complexity Time: O(n), Space: O(1)
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto maxProfit(vector<int>& prices) const -> int {
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;
        
        for (size_t i = 1; i < prices.size(); ++i) {
            buy1 = std::max(buy1, -prices[i]);
            sell1 = std::max(sell1, buy1 + prices[i]);
            buy2 = std::max(buy2, sell1 - prices[i]);
            sell2 = std::max(sell2, buy2 + prices[i]);
        }
        
        return sell2;
    }
};
