#include <iostream>
#include <semaphore>
#include <thread>

int numberOfSeats = 100;

std::counting_semaphore<1> readwriteSignal(0);
std::counting_semaphore<1> writeSignal(0);

void reserveASeat() 
{
    std::cout << "Writer: Waiting to write." << '\n';

    numberOfSeats--;
    std::cout << "Reserve a seat, remaining: " << numberOfSeats << '\n';

    readwriteSignal.release();
}

void readNumberOfSeats() 
{
    std::cout << "Reader: Waiting to read." << '\n';
    readwriteSignal.acquire();

    std::cout << "Number of seats available: " << numberOfSeats << '\n';
    std::cout << '\n';

}

int main() 
{
    std::thread t1(reserveASeat);               
    std::thread t2(readNumberOfSeats);          // 99
    std::thread t3(reserveASeat);
    std::thread t4(readNumberOfSeats);          // 98
    std::thread t5(reserveASeat);
    std::thread t6(reserveASeat);
    std::thread t7(readNumberOfSeats);          // 96
    std::thread t8(readNumberOfSeats);          // 96

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    std::cout << '\n';

}