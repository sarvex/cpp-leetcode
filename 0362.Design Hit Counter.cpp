/**
 * @brief Design hit counter for last 300 seconds
 * @intuition Store all timestamps, use binary search for range counting
 * @approach Store timestamps in vector, binary search for window start
 * @complexity Time: O(1) hit, O(log n) getHits, Space: O(n)
 */
class HitCounter final {
public:
    HitCounter() = default;

    void hit(const int timestamp) {
        timestamps_.push_back(timestamp);
    }

    [[nodiscard]] int getHits(const int timestamp) const {
        const auto it = std::ranges::lower_bound(timestamps_, timestamp - 300 + 1);
        return static_cast<int>(timestamps_.end() - it);
    }

private:
    std::vector<int> timestamps_;
};
