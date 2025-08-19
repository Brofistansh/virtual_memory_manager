#include "FIFOReplacement.h"
#include <thread>
#include <chrono>

void simulate(ReplacementPolicy &policy) {
    for (int i = 0; i < 10; i++) {
        policy.accessPage(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    FIFOReplacement fifo(3);
    std::thread t1(simulate, std::ref(fifo));
    std::thread t2(simulate, std::ref(fifo));

    t1.join();
    t2.join();

    fifo.printStats();
    return 0;
}
