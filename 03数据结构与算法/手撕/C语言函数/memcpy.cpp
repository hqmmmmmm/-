namespace yuy {  // 当源地址和目的地址重叠时，是未定义行为
    void *memcpy(void *dest, const void *src, size_t count) {
        char *dest_char = static_cast<char *>(dest);
        const char *src_char = static_cast<const char *>(src);

        for(size_t i = 0; i < count; ++i) {
            *(dest_char + i) = *(src_char + i);
        }

        return dest;
    }
}