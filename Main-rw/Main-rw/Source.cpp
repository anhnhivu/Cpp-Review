#include <iostream>
#include <thread>
#include <shared_mutex>

std::shared_mutex mutex;
int numberOfSeats = 100;

void readNumberOfSeats(int& numberOfSeatsToRead)
{
    std::shared_lock<std::shared_mutex> lock(mutex);
    numberOfSeatsToRead = numberOfSeats;
}

void reserveASeat()
{
    std::lock_guard<std::shared_mutex> lock(mutex);
    numberOfSeats--;
}

int main() {
    int read1;
    int read2;
    int read3;
    int read4;
    int read5;
    int read6;

    std::thread t1(readNumberOfSeats, std::ref(read1));
    std::thread t2(readNumberOfSeats, std::ref(read2));
    std::thread t3(reserveASeat);
    std::thread t4(readNumberOfSeats, std::ref(read3));
    std::thread t5(reserveASeat);
    std::thread t6(readNumberOfSeats, std::ref(read4));
    std::thread t7(reserveASeat);
    std::thread t8(readNumberOfSeats, std::ref(read5));
    std::thread t9(reserveASeat);
    std::thread t10(readNumberOfSeats, std::ref(read6));
    std::thread t11(reserveASeat);
    std::thread t12(reserveASeat);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();

    std::cout << read1 << "\n"; // 100
    std::cout << read2 << "\n"; // 100
    std::cout << read3 << "\n";
    std::cout << read4 << "\n";
    std::cout << read5 << "\n";
    std::cout << read6 << "\n";
    std::cout << numberOfSeats << "\n";
}
