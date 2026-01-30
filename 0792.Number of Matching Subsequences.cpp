/**
 * @brief Count words that are subsequences of s
 * @intuition Process s once, advance word pointers as matching chars appear
 * @approach Bucket words by current needed character, advance on match
 * @complexity Time: O(|s| + sum of word lengths), Space: O(total word chars)
 */
class Solution final {
public:
    [[nodiscard]] static int numMatchingSubseq(const std::string& s,
                                                const std::vector<std::string>& words) {
        std::array<std::queue<std::string>, 26> buckets;
        for (const auto& word : words) {
            buckets[word[0] - 'a'].push(word);
        }
        
        int count = 0;
        for (const char c : s) {
            auto& bucket = buckets[c - 'a'];
            for (int k = static_cast<int>(bucket.size()); k > 0; --k) {
                auto word = bucket.front();
                bucket.pop();
                if (word.size() == 1) {
                    ++count;
                } else {
                    buckets[word[1] - 'a'].push(word.substr(1));
                }
            }
        }
        return count;
    }
};
