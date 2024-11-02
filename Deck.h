#ifndef DECK_H
#define DECK_H

#include "Node.h"
// Deck class
class Deck
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Deck();
    ~Deck();
    void add(int card);
    int draw();
    int remaining_cards() const;
};

#endif
