/**
 * @brief Calendar booking without double-booking using ordered map
 * @intuition Store intervals sorted by end time, check overlap with predecessor
 * @approach Use map with end time as key, start time as value for efficient lookup
 * @complexity Time: O(log n) per booking, Space: O(n)
 */
class MyCalendar final {
public:
    MyCalendar() = default;

    [[nodiscard]] bool book(const int startTime, const int endTime) {
        auto it = calendar_.lower_bound(startTime + 1);
        if (it != calendar_.end() && it->second < endTime) {
            return false;
        }
        calendar_[endTime] = startTime;
        return true;
    }

private:
    std::map<int, int> calendar_;
};
