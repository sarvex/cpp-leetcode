/**
 * @brief Read n characters with buffering for multiple calls
 * @intuition Buffer leftover characters from previous read4 calls
 * @approach Maintain internal buffer and index to handle partial reads across calls
 * @complexity Time: O(n), Space: O(1)
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution final {
private:
    char buf4_[4] = {};
    int bufIdx_ = 0;
    int bufSize_ = 0;
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    [[nodiscard]] auto read(char* buf, int n) -> int {
        int totalRead = 0;
        
        while (totalRead < n) {
            if (bufIdx_ == bufSize_) {
                bufSize_ = read4(buf4_);
                bufIdx_ = 0;
                if (bufSize_ == 0) {
                    break;
                }
            }
            while (totalRead < n && bufIdx_ < bufSize_) {
                buf[totalRead++] = buf4_[bufIdx_++];
            }
        }
        
        return totalRead;
    }
};
