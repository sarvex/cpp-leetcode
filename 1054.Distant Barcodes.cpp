/**
 * @brief Rearrange by frequency to avoid adjacent duplicates
 * @intuition Place most frequent elements at even indices first, then odd
 * @approach Sort by frequency, interleave placement at even then odd positions
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        const int mx = *max_element(barcodes.begin(), barcodes.end());
        vector<int> cnt(mx + 1);
        for (const int x : barcodes) {
            ++cnt[x];
        }
        sort(barcodes.begin(), barcodes.end(), [&](const int a, const int b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        const int n = barcodes.size();
        vector<int> ans(n);
        for (int k = 0, j = 0; k < 2; ++k) {
            for (int i = k; i < n; i += 2) {
                ans[i] = barcodes[j++];
            }
        }
        return ans;
    }
};
