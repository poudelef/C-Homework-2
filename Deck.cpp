#include "Deck.h"
#include <iostream>

Deck::Deck() : front(nullptr), rear(nullptr), size(0) {}

Deck::~Deck()
{
    while (front)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

void Deck::add(int card)
{
    Node *newNode = new Node(card);
    if (rear)
    {
        rear->next = newNode;
    }
    rear = newNode;
    if (!front)
    {
        front = rear;
    }
    size++;
}

int Deck::draw()
{
    if (!front)
        return -1;
    int card = front->value;
    Node *temp = front;
    front = front->next;
    if (!front)
        rear = nullptr;
    delete temp;
    size--;
    return card;
}

int Deck::remaining_cards() const
{
    return size;
}
