/**
 * @brief Check if word abbreviation is unique in dictionary
 * @intuition Store all words for each abbreviation, check conflicts
 * @approach Map abbreviation -> set of words, unique if no other words share abbr
 * @complexity Time: O(n) init, O(1) query, Space: O(n)
 */
class ValidWordAbbr final {
public:
    explicit ValidWordAbbr(const vector<string>& dictionary) {
        for (const auto& s : dictionary) {
            abbr_map_[abbreviate(s)].insert(s);
        }
    }

    [[nodiscard]] bool isUnique(const string& word) const {
        const string abbr = abbreviate(word);
        if (!abbr_map_.contains(abbr)) {
            return true;
        }
        const auto& words = abbr_map_.at(abbr);
        return words.size() == 1 && words.contains(word);
    }

private:
    unordered_map<string, unordered_set<string>> abbr_map_;

    [[nodiscard]] static string abbreviate(const string& s) {
        const int n = static_cast<int>(s.size());
        if (n < 3) {
            return s;
        }
        return s.substr(0, 1) + to_string(n - 2) + s.substr(n - 1, 1);
    }
};
