/**
 * @brief Track running binary value modulo 5
 * @intuition Build binary number incrementally, keep only remainder mod 5
 * @approach Shift left, add new bit, mod 5 at each step
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<bool> prefixesDivBy5(const vector<int>& nums) {
        vector<bool> ans;
        int x = 0;
        for (const int v : nums) {
            x = (x << 1 | v) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
};
