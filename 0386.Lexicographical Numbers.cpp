/**
 * @brief Generate numbers 1 to n in lexicographical order
 * @intuition Think of it as traversing a 10-ary tree (digits 0-9)
 * @approach Start at 1, try *10 first, else +1 with proper backtracking
 * @complexity Time: O(n), Space: O(1) excluding output
 */
class Solution final {
public:
    [[nodiscard]] static auto lexicalOrder(int n) -> std::vector<int> {
        std::vector<int> ans;
        ans.reserve(n);
        int v = 1;

        for (int i = 0; i < n; ++i) {
            ans.push_back(v);
            if (v * 10 <= n) {
                v *= 10;
            } else {
                while (v % 10 == 9 || v + 1 > n) {
                    v /= 10;
                }
                ++v;
            }
        }

        return ans;
    }
};
