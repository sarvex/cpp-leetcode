/**
 * @brief Monotonic stack for stock span calculation
 * @intuition Track consecutive days with price <= current using decreasing stack
 * @approach Maintain stack of (price, count) pairs; pop and accumulate counts for
 *           all prices <= current, then push current with accumulated span
 * @complexity Time: O(1) amortized per call, Space: O(n)
 */
class StockSpanner final {
public:
    StockSpanner() = default;

    [[nodiscard]] int next(const int price) {
        int cnt = 1;
        while (!stk_.empty() && stk_.top().first <= price) {
            cnt += stk_.top().second;
            stk_.pop();
        }
        stk_.emplace(price, cnt);
        return cnt;
    }

private:
    stack<pair<int, int>> stk_;
};
