/**
 * @brief Verify preorder serialization using stack reduction
 * @intuition Valid serialization has pattern: number, #, # reduces to single #
 * @approach Use stack, reduce "num, #, #" to "#" until only "#" remains
 * @complexity Time: O(n), Space: O(n)
 */
#include <sstream>
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] bool isValidSerialization(const std::string& preorder) const {
        std::vector<std::string> stk;
        std::stringstream ss(preorder);
        std::string token;
        
        while (std::getline(ss, token, ',')) {
            stk.push_back(token);
            while (stk.size() >= 3 && 
                   stk[stk.size() - 1] == "#" && 
                   stk[stk.size() - 2] == "#" && 
                   stk[stk.size() - 3] != "#") {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back("#");
            }
        }
        return stk.size() == 1 && stk[0] == "#";
    }
};
