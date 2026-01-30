/**
 * @brief Add two negabinary numbers with carry handling
 * @intuition Negabinary addition requires special carry: +2 becomes -1 carry, -1 becomes +1 carry
 * @approach Process from LSB, handle carry with negabinary rules
 * @complexity Time: O(max(n, m)), Space: O(max(n, m))
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> addNegabinary(const vector<int>& arr1, const vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        vector<int> ans;
        for (int c = 0; i >= 0 || j >= 0 || c; --i, --j) {
            const int a = i < 0 ? 0 : arr1[i];
            const int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c += 1;
            }
            ans.push_back(x);
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
