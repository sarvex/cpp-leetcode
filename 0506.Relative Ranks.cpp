/**
 * @brief Assign ranks based on scores using sorted indices
 * @intuition Sort indices by score descending, then assign ranks in order
 * @approach Create index array, sort by descending score value. Iterate sorted indices
 *           assigning "Gold/Silver/Bronze Medal" for top 3, numeric rank for others.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findRelativeRanks(const vector<int>& score) -> vector<string> {
        const int n = static_cast<int>(score.size());
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        ranges::sort(idx, [&score](int a, int b) {
            return score[a] > score[b];
        });
        
        vector<string> ans(n);
        const array<string, 3> top3 = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        for (int i = 0; i < n; ++i) {
            ans[idx[i]] = i < 3 ? top3[i] : to_string(i + 1);
        }
        return ans;
    }
};
