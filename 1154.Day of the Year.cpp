/**
 * @brief Calculate day number in year from date string
 * @intuition Sum days of preceding months plus current day, accounting for leap year February
 * @approach Parse date, determine if leap year for February days. Sum days of months before
 *           current month plus the day value.
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int dayOfYear(const string& date) {
        int y, m, d;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        int v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
        int days[] = {31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = d;
        for (int i = 0; i < m - 1; ++i) {
            ans += days[i];
        }
        return ans;
    }
};
