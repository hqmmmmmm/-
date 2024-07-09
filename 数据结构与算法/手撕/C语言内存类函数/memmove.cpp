namespace yuy {  // memmove可以处理源地址和目的地址重叠的情况
    void *memmove(void *dest, const void *src, size_t num) {
        char *d = static_cast<char *>(dest);
        const char *s = static_cast<const char *>(src);

        if(d <= s || d >= s + num) {
            for(size_t i = 0; i < num; ++i) {
                *(d + i) = *(s + i);
            }
        } else {
            for(size_t i = num - 1; i >= 0; --i) {
                *(d + i) = *(s + i);
            }
        }

        return dest;
    }
}