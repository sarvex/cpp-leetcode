/**
 * @brief Calculate moving average from data stream
 * @intuition Use circular buffer to maintain window of size k
 * @approach Track sum and use modulo for circular indexing
 * @complexity Time: O(1) per operation, Space: O(size)
 */
class MovingAverage final {
public:
    explicit MovingAverage(const int size) : data_(size) {}

    [[nodiscard]] double next(const int val) {
        const int i = count_ % static_cast<int>(data_.size());
        sum_ += val - data_[i];
        data_[i] = val;
        ++count_;
        return static_cast<double>(sum_) / std::min(count_, static_cast<int>(data_.size()));
    }

private:
    int sum_ = 0;
    int count_ = 0;
    std::vector<int> data_;
};
