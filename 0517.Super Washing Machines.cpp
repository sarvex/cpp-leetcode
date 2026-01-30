/**
 * @brief Calculate minimum moves to balance washing machines
 * @intuition Track cumulative excess/deficit; max of absolute running sum and individual excess
 * @approach Calculate target per machine. Scan left to right tracking running sum of excess.
 *           Answer is max of: absolute running sum (dresses crossing boundary) and 
 *           individual machine excess (one machine gives out multiple).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto findMinMoves(const vector<int>& machines) -> int {
        const int n = static_cast<int>(machines.size());
        const int total = accumulate(machines.begin(), machines.end(), 0);
        
        if (total % n != 0) return -1;
        
        const int target = total / n;
        int runningSum = 0;
        int ans = 0;
        
        for (int x : machines) {
            const int excess = x - target;
            runningSum += excess;
            ans = max({ans, abs(runningSum), excess});
        }
        return ans;
    }
};
