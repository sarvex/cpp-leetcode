/**
 * @brief Split binary array into three equal parts
 * @intuition Total 1s must be divisible by 3; match patterns from each third
 * @approach Find starts of each third by counting 1s; verify patterns match
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> threeEqualParts(const vector<int>& arr) {
        const int n = static_cast<int>(arr.size());
        const int cnt = accumulate(arr.begin(), arr.end(), 0);
        if (cnt % 3) return {-1, -1};
        if (!cnt) return {0, n - 1};
        const int target = cnt / 3;

        auto findStart = [&](int count) {
            int s = 0;
            for (int idx = 0; idx < n; ++idx) {
                s += arr[idx];
                if (s == count) return idx;
            }
            return 0;
        };
        int i = findStart(1), j = findStart(target + 1), k = findStart(target * 2 + 1);
        for (; k < n && arr[i] == arr[j] && arr[j] == arr[k]; ++i, ++j, ++k) {}
        return k == n ? vector<int>{i - 1, j} : vector<int>{-1, -1};
    }
};
