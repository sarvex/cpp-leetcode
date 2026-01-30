/**
 * @brief Divide and conquer to construct beautiful array
 * @intuition No arithmetic triple possible if odd numbers before evens
 * @approach Recursively build odd positions and even positions separately
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> beautifulArray(const int n) {
        if (n == 1) return {1};
        vector<int> left = beautifulArray((n + 1) >> 1);
        vector<int> right = beautifulArray(n >> 1);
        vector<int> ans(n);
        int i = 0;
        for (const int x : left) ans[i++] = x * 2 - 1;
        for (const int x : right) ans[i++] = x * 2;
        return ans;
    }
};
