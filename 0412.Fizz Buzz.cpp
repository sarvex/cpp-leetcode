/**
 * @brief Generate FizzBuzz sequence from 1 to n
 * @intuition Replace multiples of 3 with Fizz, 5 with Buzz, both with FizzBuzz
 * @approach Iterate and check divisibility, build string accordingly
 * @complexity Time: O(n) Space: O(1) excluding output
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto fizzBuzz(int n) const -> std::vector<std::string> {
        std::vector<std::string> ans;
        ans.reserve(n);

        for (int i = 1; i <= n; ++i) {
            std::string s;
            if (i % 3 == 0) {
                s += "Fizz";
            }
            if (i % 5 == 0) {
                s += "Buzz";
            }
            if (s.empty()) {
                s = std::to_string(i);
            }
            ans.push_back(std::move(s));
        }

        return ans;
    }
};
