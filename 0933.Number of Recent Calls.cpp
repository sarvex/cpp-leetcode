/**
 * @brief Queue-based recent call counter
 * @intuition Maintain queue of timestamps within 3000ms window
 * @approach Push new timestamp, pop old ones outside window
 * @complexity Time: O(1) amortized per call, Space: O(3000)
 */
class RecentCounter final {
public:
    RecentCounter() = default;

    [[nodiscard]] int ping(const int t) {
        q_.push(t);
        while (q_.front() < t - 3000) {
            q_.pop();
        }
        return static_cast<int>(q_.size());
    }

private:
    queue<int> q_;
};
