#include <chrono>
#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
using namespace std;


void print123()
{
    condition_variable cv1, cv2, cv3;
    mutex mtx;
    int flag = 1;
    
    thread t1([&](){
        while(1)
        {
            unique_lock<mutex> lock(mtx);
            cv1.wait(lock, [&](){return flag == 1;});
            cout << flag << endl;
            flag = 2;
            this_thread::sleep_for(chrono::seconds(1));
            cv2.notify_all();
        }
    });
    thread t2([&](){
        while(1)
        {
            unique_lock<mutex> lock(mtx);
            cv2.wait(lock, [&](){ return flag == 2; });
            cout << flag << endl;
            flag = 3;
            this_thread::sleep_for(chrono::seconds(1));
            cv3.notify_all();
        }
    });
    thread t3([&](){
        while(1)
        {
            unique_lock<mutex> lock(mtx);
            cv3.wait(lock, [&](){return flag == 3;});
            cout << flag << endl;
            flag = 1;
            this_thread::sleep_for(chrono::seconds(1));
            cv1.notify_all();
        }
    });


    t1.join();
    t2.join();
    t3.join();
}

int main()
{
    print123();
    

    return 0;
}