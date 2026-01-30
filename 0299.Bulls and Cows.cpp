/**
 * @brief Count bulls and cows in number guessing game
 * @intuition Bulls: exact match; Cows: right digit, wrong position
 * @approach Count exact matches, then count misplaced digit frequencies
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static string getHint(const string& secret, const string& guess) {
        int bulls = 0;
        int cows = 0;
        int secretCnt[10] = {};
        int guessCnt[10] = {};
        
        for (size_t i = 0; i < secret.size(); ++i) {
            const int a = secret[i] - '0';
            const int b = guess[i] - '0';
            if (a == b) {
                ++bulls;
            } else {
                ++secretCnt[a];
                ++guessCnt[b];
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            cows += min(secretCnt[i], guessCnt[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
