/**
 * @brief Implement rand10() using only rand7()
 * @intuition Generate uniform distribution over [1,49], reject values > 40
 * @approach Use rejection sampling: (rand7()-1)*7 + rand7() gives uniform [1,49]
 * @complexity Time: O(1) expected, Space: O(1)
 */

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution final {
public:
    [[nodiscard]] auto rand10() const -> int {
        while (true) {
            const int i = rand7() - 1;
            const int j = rand7();
            const int x = i * 7 + j;
            if (x <= 40) {
                return x % 10 + 1;
            }
        }
    }
};
