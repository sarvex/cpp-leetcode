/**
 * @brief Find common restaurants with minimum index sum
 * @intuition Index restaurants from one list, scan other to find matches with smallest sum
 * @approach Hash map list2 indices, iterate list1 tracking minimum sum matches
 * @complexity Time: O(n + m), Space: O(m)
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> findRestaurant(const vector<string>& list1,
                                                        const vector<string>& list2) {
        unordered_map<string, int> indexMap;
        
        for (size_t i = 0; i < list2.size(); ++i) {
            indexMap[list2[i]] = static_cast<int>(i);
        }
        
        vector<string> ans;
        int minSum = INT_MAX;
        
        for (size_t i = 0; i < list1.size(); ++i) {
            if (indexMap.contains(list1[i])) {
                const int j = indexMap[list1[i]];
                const int sum = static_cast<int>(i) + j;
                
                if (sum < minSum) {
                    minSum = sum;
                    ans.clear();
                    ans.push_back(list1[i]);
                } else if (sum == minSum) {
                    ans.push_back(list1[i]);
                }
            }
        }
        
        return ans;
    }
};
