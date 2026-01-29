/**
 * @brief Validate if string is valid IPv4, IPv6, or Neither
 * @intuition Check format rules for each type separately
 * @approach Split by delimiter, validate each segment per IP type rules
 * @complexity Time: O(n) Space: O(n)
 */
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto validIPAddress(const std::string& queryIP) const -> std::string {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

private:
    [[nodiscard]] auto isIPv4(const std::string& s) const -> bool {
        if (s.empty() || s.back() == '.') {
            return false;
        }

        auto ss = split(s, '.');
        if (ss.size() != 4) {
            return false;
        }

        for (const auto& t : ss) {
            if (t.empty() || (t.size() > 1 && t[0] == '0')) {
                return false;
            }
            const int x = convert(t);
            if (x < 0 || x > 255) {
                return false;
            }
        }

        return true;
    }

    [[nodiscard]] auto isIPv6(const std::string& s) const -> bool {
        if (s.empty() || s.back() == ':') {
            return false;
        }

        auto ss = split(s, ':');
        if (ss.size() != 8) {
            return false;
        }

        for (const auto& t : ss) {
            if (t.size() < 1 || t.size() > 4) {
                return false;
            }
            for (const char c : t) {
                if (!std::isxdigit(c)) {
                    return false;
                }
            }
        }

        return true;
    }

    [[nodiscard]] static auto convert(const std::string& s) -> int {
        int x = 0;
        for (const char c : s) {
            if (!std::isdigit(c)) {
                return -1;
            }
            x = x * 10 + (c - '0');
            if (x > 255) {
                return x;
            }
        }
        return x;
    }

    [[nodiscard]] static auto split(const std::string& s, char delimiter) -> std::vector<std::string> {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream iss(s);

        while (std::getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }
};
