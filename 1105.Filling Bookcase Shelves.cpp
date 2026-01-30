/**
 * @brief Dynamic programming to minimize bookshelf height
 * @intuition For each book, try placing it on a new shelf or on the current shelf with previous books
 * @approach Use DP where f[i] is the minimum height to place first i books. For each book,
 *           try extending the current shelf backwards while width permits, tracking max height.
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minHeightShelves(const vector<vector<int>>& books, const int shelfWidth) {
        const int n = books.size();
        vector<int> f(n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = max(h, books[j - 1][1]);
                f[i] = min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
};
