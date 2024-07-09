namespace yuy {
    char *strncpy(char *dest, const char *src, size_t n) {
        char *ret = dest;
        while(n && *src != '\0') {
            *dest = *src;
            dest++, src++;
            n--;
        }

        while(n) {
            *dest = '\0';
            dest++;
            n--;
        }

        return ret;
    }
}