/**
 * @brief Compare version numbers component by component
 * @intuition Parse each dot-separated component and compare numerically
 * @approach Two pointers parsing numbers between dots, treat missing parts as 0
 * @complexity Time: O(m+n), Space: O(1)
 */

#include <string>

using std::string;

class Solution final {
public:
    [[nodiscard]] auto compareVersion(const string& version1, const string& version2) const -> int {
        const int m = static_cast<int>(version1.size());
        const int n = static_cast<int>(version2.size());
        
        for (int i = 0, j = 0; i < m || j < n; ++i, ++j) {
            int num1 = 0;
            int num2 = 0;
            
            while (i < m && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0');
            }
            
            while (j < n && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0');
            }
            
            if (num1 != num2) {
                return num1 < num2 ? -1 : 1;
            }
        }
        
        return 0;
    }
};
