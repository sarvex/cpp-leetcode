/**
 * @brief Minimum rabbits in forest from survey answers
 * @intuition Rabbits answering k form groups of k+1; count groups needed
 * @approach Group by answer, compute minimum complete groups for each
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int numRabbits(const std::vector<int>& answers) {
        std::unordered_map<int, int> counts;
        for (const int x : answers) {
            ++counts[x];
        }
        
        int result = 0;
        for (const auto& [answer, count] : counts) {
            const int groupSize = answer + 1;
            result += (count + groupSize - 1) / groupSize * groupSize;
        }
        return result;
    }
};
