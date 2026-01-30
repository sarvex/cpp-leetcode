/**
 * @brief Greedy partition into equal sum parts
 * @intuition Total must be divisible by 3; find partition points greedily
 * @approach Accumulate sum, count partitions when target reached
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool canThreePartsEqualSum(const vector<int>& arr) {
        const int s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3) {
            return false;
        }
        const int target = s / 3;
        int cnt = 0, t = 0;
        for (const int x : arr) {
            t += x;
            if (t == target) {
                t = 0;
                ++cnt;
            }
        }
        return cnt >= 3;
    }
};
