/**
 * @brief Check attendance record validity using STL algorithms
 * @intuition Valid if fewer than 2 absences and no 3 consecutive lates
 * @approach Count 'A' occurrences and check for "LLL" substring
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool checkRecord(const string& s) {
        return count(s.begin(), s.end(), 'A') < 2 && s.find("LLL") == string::npos;
    }
};
