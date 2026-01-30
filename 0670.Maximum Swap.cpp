/**
 * @brief Maximize number by swapping at most two digits
 * @intuition Swap leftmost digit with largest digit to its right (rightmost if ties)
 * @approach Track rightmost position of maximum digit from right, find first beneficial swap
 * @complexity Time: O(n), Space: O(n) for string
 */
class Solution final {
public:
    [[nodiscard]] static int maximumSwap(int num) {
        string s = to_string(num);
        const int n = s.size();
        vector<int> d(n);
        iota(d.begin(), d.end(), 0);
        
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] <= s[d[i + 1]]) {
                d[i] = d[i + 1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            const int j = d[i];
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                break;
            }
        }
        return stoi(s);
    }
};
