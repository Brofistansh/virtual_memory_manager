#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;
// Simple Page Frame
struct PageFrame {
    int pageNumber;
};

// FIFO page replacement as an example
class VirtualMemoryManager {
    int capacity;
    queue<int> pages;
    mutex mtx;

public:
    VirtualMemoryManager(int cap) : capacity(cap) {}

    void accessPage(int pageNumber) {
        lock_guard<mutex> lock(mtx);
        if (pages.size() == capacity) {
            cout << "Evicting page: " << pages.front() << endl;
            pages.pop();
        }
        pages.push(pageNumber);
        cout << "Accessed page: " << pageNumber << endl;
    }
};

void simulate(VirtualMemoryManager &vmm) {
    for (int i = 0; i < 10; i++) {
        vmm.accessPage(i);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    VirtualMemoryManager vmm(3); // capacity = 3 frames
    thread t1(simulate, ref(vmm));
    thread t2(simulate, ref(vmm));

    t1.join();
    t2.join();
    return 0;
}
