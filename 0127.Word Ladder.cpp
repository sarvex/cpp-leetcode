/**
 * @brief Find shortest transformation sequence using BFS
 * @intuition BFS finds shortest path in unweighted graph of word transformations
 * @approach Try all single-char changes, use set for O(1) word lookup and removal
 * @complexity Time: O(n * m * 26), Space: O(n * m) where n=words, m=word length
 */

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

class Solution final {
public:
    [[nodiscard]] auto ladderLength(const string& beginWord, const string& endWord, 
                                     vector<string>& wordList) const -> int {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q{{beginWord}};
        int steps = 1;
        
        while (!q.empty()) {
            ++steps;
            for (int count = q.size(); count > 0; --count) {
                string current = q.front();
                q.pop();
                
                for (size_t j = 0; j < current.size(); ++j) {
                    const char original = current[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        current[j] = c;
                        if (!words.contains(current)) {
                            continue;
                        }
                        if (current == endWord) {
                            return steps;
                        }
                        q.push(current);
                        words.erase(current);
                    }
                    current[j] = original;
                }
            }
        }
        return 0;
    }
};
