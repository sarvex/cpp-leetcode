/**
 * @brief Calculate day of week for given date using Zeller's congruence
 * @intuition Zeller's formula computes day of week from date mathematically
 * @approach Apply Zeller's congruence formula adjusting for months Jan/Feb as 13/14 of previous year.
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static string dayOfTheWeek(int d, int m, int y) {
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int c = y / 100;
        y %= 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        const vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                      "Thursday", "Friday", "Saturday"};
        return weeks[(w + 7) % 7];
    }
};
