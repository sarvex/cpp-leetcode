/**
 * @brief Read n characters using read4 API
 * @intuition Repeatedly call read4 until we have n chars or EOF
 * @approach Buffer read4 results and copy to output until n reached
 * @complexity Time: O(n), Space: O(1)
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution final {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    [[nodiscard]] auto read(char* buf, int n) -> int {
        char buf4[4];
        int totalRead = 0;
        int charsFromRead4 = 4;
        
        while (charsFromRead4 >= 4) {
            charsFromRead4 = read4(buf4);
            for (int j = 0; j < charsFromRead4; ++j) {
                buf[totalRead++] = buf4[j];
                if (totalRead >= n) {
                    return n;
                }
            }
        }
        
        return totalRead;
    }
};
