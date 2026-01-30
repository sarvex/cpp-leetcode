/**
 * @brief Sliding window to maximize saved customers
 * @intuition Owner can suppress grumpiness for 'minutes' window; maximize grumpy customers saved
 * @approach Compute base satisfied, slide window to find best grumpy period to suppress
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxSatisfied(
        const vector<int>& customers,
        const vector<int>& grumpy,
        const int minutes) {
        
        int cnt = 0;
        int tot = 0;
        for (int i = 0; i < minutes; ++i) {
            cnt += customers[i] * grumpy[i];
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        int mx = cnt;
        const int n = customers.size();
        for (int i = minutes; i < n; ++i) {
            cnt += customers[i] * grumpy[i];
            cnt -= customers[i - minutes] * grumpy[i - minutes];
            mx = max(mx, cnt);
            tot += customers[i] * (grumpy[i] ^ 1);
        }
        return tot + mx;
    }
};
