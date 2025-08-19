#include "FIFOReplacement.h"

FIFOReplacement::FIFOReplacement(int cap) : capacity(cap) {}

void FIFOReplacement::accessPage(int pageNumber) {
    std::lock_guard<std::mutex> lock(mtx);
    // check if page is already in memory
    bool found = false;
    std::queue<int> temp = pages;
    while (!temp.empty()) {
        if (temp.front() == pageNumber) {
            found = true;
            break;
        }
        temp.pop();
    }

    if (found) {
        hits++;
        std::cout << "Page hit: " << pageNumber << std::endl;
        return;
    }

    // if not found, page miss
    misses++;
    if (pages.size() == capacity) {
        std::cout << "Evicting page: " << pages.front() << std::endl;
        pages.pop();
    }
    pages.push(pageNumber);
    std::cout << "Loaded page: " << pageNumber << std::endl;
}

void FIFOReplacement::printStats() const {
    std::lock_guard<std::mutex> lock(mtx);
    int total = hits + misses;
    double hitRate = total ? (hits * 100.0 / total) : 0.0;
    std::cout << "\n=== FIFO Stats ===\n";
    std::cout << "Hits: " << hits << ", Misses: " << misses
              << ", Hit Rate: " << hitRate << "%\n";
}
