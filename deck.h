// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck will randomize whatever cards are in the deck
// Do not shuffle if you have less than 2 cards
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck

    //input param: N/A
    //output: N/A
    // shuffle the cards in the current deck
    void shuffle();

    //input param: N/A
    //output: returns a card
    // get a card, after 52 are dealt, fail
    Card dealCard();

    //input param: N/A
    //output: size of deck
    // return size of deck
    int size() const
    {
        return SIZE - myIndex;
    }// # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif