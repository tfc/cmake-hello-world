#include <future>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    auto a1 = std::async([]() {
        std::cout << "a1 begin\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "a1 end\n";
        return 1;
    });

    auto a2 = std::async([]() {
        std::cout << "a2 begin\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "a2 end\n";
        return 2;
    });

    auto a3 = std::async([]() {
        std::cout << "a3 begin\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "a3 end\n";
        return 3;
    });

    auto a4 = std::async([&a1, &a2]() {
        return a1.get() + a2.get();
    });
    
    auto summe = a3.get() + a4.get();

    std::cout << summe << '\n';

}