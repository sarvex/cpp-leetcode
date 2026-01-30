/**
 * @brief Find minimum operations to make password strong
 * @intuition Balance insertions, deletions, and replacements for length and rules
 * @approach Handle short (<6), valid (6-20), and long (>20) passwords separately
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto strongPasswordChecker(const std::string& password) -> int {
        const int types = countTypes(password);
        const auto n = static_cast<int>(password.size());

        if (n < 6) {
            return std::max(6 - n, 3 - types);
        }

        if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char prev = '~';

            for (const char curr : password) {
                if (curr == prev) {
                    ++cnt;
                } else {
                    replace += cnt / 3;
                    cnt = 1;
                    prev = curr;
                }
            }
            replace += cnt / 3;
            return std::max(replace, 3 - types);
        }

        int replace = 0;
        int remove = n - 20;
        int remove2 = 0;
        int cnt = 0;
        char prev = '~';

        for (const char curr : password) {
            if (curr == prev) {
                ++cnt;
            } else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) {
                        --remove;
                        --replace;
                    } else if (cnt % 3 == 1) {
                        ++remove2;
                    }
                }
                replace += cnt / 3;
                cnt = 1;
                prev = curr;
            }
        }

        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) {
                --remove;
                --replace;
            } else if (cnt % 3 == 1) {
                ++remove2;
            }
        }
        replace += cnt / 3;

        const int use2 = std::min({replace, remove2, remove / 2});
        replace -= use2;
        remove -= use2 * 2;

        const int use3 = std::min(replace, remove / 3);
        replace -= use3;

        return (n - 20) + std::max(replace, 3 - types);
    }

private:
    [[nodiscard]] static auto countTypes(const std::string& s) -> int {
        int a = 0, b = 0, c = 0;
        for (const char ch : s) {
            if (std::islower(ch)) {
                a = 1;
            } else if (std::isupper(ch)) {
                b = 1;
            } else if (std::isdigit(ch)) {
                c = 1;
            }
        }
        return a + b + c;
    }
};
