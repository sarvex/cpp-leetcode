/**
 * @brief Calendar double-booking prevention using difference array
 * @intuition Track interval boundaries; sum reveals overlap count at any point
 * @approach Use ordered map as difference array, check max overlap after booking
 * @complexity Time: O(n^2) total for n bookings, Space: O(n)
 */
class MyCalendarTwo final {
public:
    MyCalendarTwo() = default;

    [[nodiscard]] bool book(const int startTime, const int endTime) {
        ++timeline_[startTime];
        --timeline_[endTime];
        
        int activeBookings = 0;
        for (const auto& [_, delta] : timeline_) {
            activeBookings += delta;
            if (activeBookings > 2) {
                --timeline_[startTime];
                ++timeline_[endTime];
                return false;
            }
        }
        return true;
    }

private:
    std::map<int, int> timeline_;
};
