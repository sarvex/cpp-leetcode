/**
 * @brief Custom sort for log files with letter logs before digit logs
 * @intuition Letter logs sorted by content then ID; digit logs maintain order
 * @approach Stable sort with custom comparator distinguishing log types
 * @complexity Time: O(n * m * log n), Space: O(m)
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) {
            const int idx1 = log1.find(' ');
            const int idx2 = log2.find(' ');
            const string id1 = log1.substr(0, idx1);
            const string id2 = log2.substr(0, idx2);
            const string content1 = log1.substr(idx1 + 1);
            const string content2 = log2.substr(idx2 + 1);

            const bool isLetter1 = isalpha(content1[0]);
            const bool isLetter2 = isalpha(content2[0]);

            if (isLetter1 && isLetter2) {
                if (content1 != content2) {
                    return content1 < content2;
                }
                return id1 < id2;
            }

            return isLetter1 > isLetter2;
        });

        return logs;
    }
};
