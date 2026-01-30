/**
 * @brief Maintain disjoint intervals from data stream
 * @intuition Use ordered map to track intervals, merge adjacent ones
 * @approach Find neighbors using upper_bound, merge if adjacent
 * @complexity Time: O(log n) addNum, O(n) getIntervals, Space: O(n)
 */
class SummaryRanges final {
public:
    SummaryRanges() = default;

    void addNum(const int val) {
        auto right = intervals_.upper_bound(val);
        auto left = right == intervals_.begin() ? intervals_.end() : std::prev(right);
        
        if (left != intervals_.end() && right != intervals_.end() && 
            left->second[1] + 1 == val && right->second[0] - 1 == val) {
            left->second[1] = right->second[1];
            intervals_.erase(right);
        } else if (left != intervals_.end() && val <= left->second[1] + 1) {
            left->second[1] = std::max(val, left->second[1]);
        } else if (right != intervals_.end() && val >= right->second[0] - 1) {
            right->second[0] = std::min(val, right->second[0]);
        } else {
            intervals_[val] = {val, val};
        }
    }

    [[nodiscard]] std::vector<std::vector<int>> getIntervals() const {
        std::vector<std::vector<int>> result;
        result.reserve(intervals_.size());
        for (const auto& [key, interval] : intervals_) {
            result.push_back(interval);
        }
        return result;
    }

private:
    std::map<int, std::vector<int>> intervals_;
};
