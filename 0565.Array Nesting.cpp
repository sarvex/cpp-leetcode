/**
 * @brief Find longest cycle in permutation array
 * @intuition Each index leads to exactly one cycle; track visited to avoid recount
 * @approach For each unvisited start, follow chain marking visited, track max length
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int arrayNesting(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<bool> visited(n);
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            
            int current = nums[i];
            int length = 1;
            visited[current] = true;
            
            while (nums[current] != nums[i]) {
                current = nums[current];
                ++length;
                visited[current] = true;
            }
            
            result = max(result, length);
        }
        
        return result;
    }
};
