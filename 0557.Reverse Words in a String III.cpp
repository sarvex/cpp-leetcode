/**
 * @brief Reverse each word in string while preserving word order
 * @intuition Split by spaces, reverse each word, rejoin
 * @approach Use stringstream to extract words, reverse each, concatenate with spaces
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string reverseWords(const string& s) {
        stringstream ss(s);
        string word;
        string ans;
        
        while (ss >> word) {
            reverse(word.begin(), word.end());
            ans += word;
            ans.push_back(' ');
        }
        
        ans.pop_back();
        return ans;
    }
};
