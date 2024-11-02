#ifndef SIDEPILE_H
#define SIDEPILE_H

#include <stack>

// Sidepile class representing a side pile of cards. The pile can only hold a maximum of 5 cards.
class SidePile
{
private:
    std::stack<int> pile;
    static const int max_capacity = 5;

public:
    void push(int card);
    int pop();
    int size() const;
    bool is_empty() const; 

};

#endif
