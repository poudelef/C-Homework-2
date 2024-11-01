#include "SidePile.h"
#include <stdexcept>

void SidePile::push(int card)
{
    if (pile.size() < max_capacity)
    {
        pile.push(card);
    }
    else
    {
        throw std::overflow_error("Side pile is full.");
    }
}

int SidePile::pop()
{
    if (pile.empty())
        return -1;
    int card = pile.top();
    pile.pop();
    return card;
}

int SidePile::size() const
{
    return pile.size();
}
