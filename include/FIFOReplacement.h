#ifndef FIFO_REPLACEMENT_H
#define FIFO_REPLACEMENT_H

#include "ReplacementPolicy.h"
#include <queue>
#include <mutex>
#include <iostream>

class FIFOReplacement : public ReplacementPolicy {
    int capacity;
    std::queue<int> pages;
    mutable std::mutex mtx;
    int hits = 0, misses = 0;

public:
    FIFOReplacement(int cap);
    void accessPage(int pageNumber) override;
    void printStats() const override;
};

#endif
