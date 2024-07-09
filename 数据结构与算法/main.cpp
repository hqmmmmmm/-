#include <iostream>
#include <vector>
using namespace std;

namespace yuy
{
    class shared_ptr
    {
    public:
        shared_ptr() : a_(0) {}
        shared_ptr(int a) : a_(a) {}

    private:
        int a_;
    };
}
namespace yuy {
    void *memcpy(void *dest, const void *src, size_t count) {
        char *dest_char = static_cast<char *>(dest);
        const char *src_char = static_cast<const char *>(src);

        for(size_t i = 0; i < count; ++i) {
            *(dest_char + i) = *(src_char + i);
        }

        return dest;
    }
}


int main() {
    char str[] = "hello world";
    yuy::memcpy(str, str + 6, 5); // 将 "world" 复制到 "hello " 的位置
    printf("%s\n", str); // 输出 "worldo"


    return 0;
}