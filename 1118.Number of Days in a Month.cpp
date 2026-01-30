/**
 * @brief Calculate number of days in a given month accounting for leap years
 * @intuition February has 29 days in leap years, otherwise use standard month lengths
 * @approach Check leap year condition for February. Use lookup table for other months.
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int numberOfDays(const int year, const int month) {
        const bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        const vector<int> days = {0, 31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month];
    }
};
