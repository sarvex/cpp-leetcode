/**
 * @brief Design hit counter for last 300 seconds
 * @intuition Store all timestamps, use binary search for range counting
 * @approach Store timestamps in vector, binary search for window start
 * @complexity Time: O(1) hit, O(log n) getHits, Space: O(n)
 */
#include <algorithm>
#include <vector>

class HitCounter final {
public:
    HitCounter() = default;

    void hit(int timestamp) {
        timestamps_.push_back(timestamp);
    }

    [[nodiscard]] int getHits(int timestamp) const {
        const auto it = std::lower_bound(timestamps_.begin(), timestamps_.end(), 
                                          timestamp - 300 + 1);
        return static_cast<int>(timestamps_.end() - it);
    }

private:
    std::vector<int> timestamps_;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
