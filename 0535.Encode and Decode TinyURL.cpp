/**
 * @brief Encode and decode URLs using incremental IDs
 * @intuition Map each URL to unique ID; store bidirectional mapping for encode/decode
 * @approach Assign incrementing numeric ID to each new URL, store in hash map.
 *           Decode extracts ID from shortened URL and looks up original.
 * @complexity Time: O(1) per operation, Space: O(n) for n URLs
 */
class Solution final {
public:
    [[nodiscard]] auto encode(const string& longUrl) -> string {
        const string key = to_string(++idx);
        urlMap[key] = longUrl;
        return domain + key;
    }

    [[nodiscard]] auto decode(const string& shortUrl) const -> string {
        const auto pos = shortUrl.rfind('/') + 1;
        return urlMap.at(shortUrl.substr(pos));
    }

private:
    unordered_map<string, string> urlMap;
    int idx = 0;
    const string domain = "https://tinyurl.com/";
};
