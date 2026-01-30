/**
 * @brief Find duplicate and missing numbers in array
 * @intuition Compare expected sum and unique sum with actual sum
 * @approach Use set to find unique sum, calculate duplicate and missing from differences
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> findErrorNums(const vector<int>& nums) {
        const int n = nums.size();
        const int s1 = (1 + n) * n / 2;
        
        unordered_set<int> unique_set(nums.begin(), nums.end());
        int s2 = 0;
        for (const int x : unique_set) {
            s2 += x;
        }
        
        const int s = accumulate(nums.begin(), nums.end(), 0);
        return {s - s2, s1 - s2};
    }
};
