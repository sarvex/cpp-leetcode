/**
 * @brief Sliding window to find minimum swaps to group all 1s together
 * @intuition Find window of size k (count of 1s) with maximum 1s already present
 * @approach Count total 1s as window size. Slide window and track max 1s in any window.
 *           Minimum swaps = total 1s - max 1s in any window.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minSwaps(const vector<int>& data) {
        int k = 0;
        for (int v : data) {
            k += v;
        }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            t += data[i];
        }
        int mx = t;
        for (int i = k; i < data.size(); ++i) {
            t += data[i];
            t -= data[i - k];
            mx = max(mx, t);
        }
        return k - mx;
    }
};
