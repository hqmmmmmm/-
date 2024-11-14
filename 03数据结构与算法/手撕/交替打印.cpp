// 3个线程交替打印ABC

#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
char cur = 'A';

// 这个c表示希望打印的字符
void print_c(char c) {
    while(1) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [c](){ return cur == c; });

        std::cout << c << std::endl;
        cur = 'A' + (c - 'A' + 1) % 3;

        std::this_thread::sleep_for(std::chrono::seconds(1)); // 方便观察结果

        cv.notify_all();
    }
}

int main() {
    std::vector<std::thread> pool;

    for(int i = 0; i < 3; ++i)
        pool.emplace_back(std::thread(print_c, 'A' + i));

    for(auto &t : pool)
        t.join();

    return 0;
}