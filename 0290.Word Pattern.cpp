/**
 * @brief Check if pattern matches words in string
 * @intuition Bijection between pattern chars and words
 * @approach Use two hash maps for bidirectional mapping
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool wordPattern(const string& pattern, const string& s) {
        istringstream is(s);
        vector<string> words;
        string word;
        while (is >> word) {
            words.push_back(word);
        }
        
        if (pattern.size() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (size_t i = 0; i < words.size(); ++i) {
            const char c = pattern[i];
            const string& w = words[i];
            if ((charToWord.contains(c) && charToWord[c] != w) ||
                (wordToChar.contains(w) && wordToChar[w] != c)) {
                return false;
            }
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};
