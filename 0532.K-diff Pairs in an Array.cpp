/**
 * @brief Count unique k-diff pairs in array
 * @intuition Use sets to track seen numbers and valid pair starts
 * @approach For each number, check if x-k or x+k was seen before.
 *           Add smaller of pair to answer set (ensures uniqueness). Track all seen numbers.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findPairs(const vector<int>& nums, int k) -> int {
        unordered_set<int> pairStarts;
        unordered_set<int> seen;
        
        for (int x : nums) {
            if (seen.contains(x - k)) {
                pairStarts.insert(x - k);
            }
            if (seen.contains(x + k)) {
                pairStarts.insert(x);
            }
            seen.insert(x);
        }
        return static_cast<int>(pairStarts.size());
    }
};
