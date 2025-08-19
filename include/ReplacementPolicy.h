#ifndef REPLACEMENT_POLICY_H
#define REPLACEMENT_POLICY_H

class ReplacementPolicy {
public:
    virtual void accessPage(int pageNumber) = 0;
    virtual void printStats() const = 0;
    virtual ~ReplacementPolicy() = default;
};

#endif
