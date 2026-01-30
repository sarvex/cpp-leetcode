/**
 * @brief Minimum steps to reach target on number line
 * @intuition Sum 1+2+...+k, flip signs to reach target; need sum >= |target| with same parity
 * @approach Find k where sum >= target and (sum - target) is even (can flip a step)
 * @complexity Time: O(sqrt(target)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int reachNumber(int target) {
        target = std::abs(target);
        int sum = 0;
        int step = 0;
        while (true) {
            if (sum >= target && (sum - target) % 2 == 0) {
                return step;
            }
            ++step;
            sum += step;
        }
    }
};
