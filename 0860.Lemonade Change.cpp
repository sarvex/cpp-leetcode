/**
 * @brief Greedy change-making simulation
 * @intuition Always prefer giving 10s over 5s when making change for 20
 * @approach Track count of 5s and 10s. For each customer: 5 -> keep it,
 *           10 -> give one 5, 20 -> prefer 10+5, else three 5s.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto lemonadeChange(const std::vector<int>& bills) -> bool {
        int five = 0, ten = 0;
        
        for (const int v : bills) {
            if (v == 5) {
                ++five;
            } else if (v == 10) {
                ++ten;
                --five;
            } else {
                if (ten > 0) {
                    --ten;
                    --five;
                } else {
                    five -= 3;
                }
            }
            if (five < 0) return false;
        }
        return true;
    }
};
