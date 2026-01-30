/**
 * @brief Find next permutation of digits to get smallest larger number
 * @intuition Same as next permutation algorithm on digit string
 * @approach Find rightmost digit smaller than its right neighbor, swap with next larger digit, reverse suffix
 * @complexity Time: O(d), Space: O(d) where d is number of digits
 */
class Solution final {
public:
    [[nodiscard]] static int nextGreaterElement(int n) {
        string s = to_string(n);
        const int len = static_cast<int>(s.size());
        
        int i = len - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            --i;
        }
        
        if (i < 0) {
            return -1;
        }
        
        int j = len - 1;
        while (s[i] >= s[j]) {
            --j;
        }
        
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        
        const long ans = stol(s);
        return ans > INT_MAX ? -1 : static_cast<int>(ans);
    }
};
