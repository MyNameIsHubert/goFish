
//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:


    enum Suit {spades, hearts, diamonds, clubs};

    Card();          // default, ace of spades

    //input param: int rank, suit s
    //output: N/A
    //constructs a card class
    Card(int rank, Suit s);

    //input param: N/A
    //output: a string
    //converts a card to a string for printout
    string toString() const
    {
        string cardtype;
        cardtype = rankString(myRank) + suitString(mySuit);
        return cardtype;
    }// return string version e.g. Ac 4h Js


    //input param: Card c
    //output: bool t/f
    //check if the suit of a card is the same;
    bool sameSuitAs(const Card& c) const
    {
        if( this->suitString(mySuit) == c.suitString(mySuit))
            return true;
        else
            return false;
    }// true if suit same as c

    //input param: N/A
    //output: int rank
    //returns rank of a card
    int  getRank()const
    {
        return myRank;
    }// return rank, 1..13

    //input param: suit s
    //output: string suitS
    //returns a string representing the suit of the card
    string suitString(Suit s) const
    {
        if(s == spades)
            return "s";
        else if (s == hearts)
            return "h";
        else if (s == clubs)
            return "c";
        else //diamonds
            return "d";
    }// return "s", "h",...

    //input param: int ra
    //output: string rank
    //returns a string representing the rank of the card
    string rankString(int r) const
    {
         if(r == 1)
             return "A";
         else if( r == 11)
             return "J";
         else if( r == 12)
             return "Q";
         else if( r == 13)
             return "K";
         else if( r == 2)
             return "2";
         else if ( r == 3)
             return "3";
         else if (r == 4)
             return "4";
         else if (r == 5)
             return "5";
         else if ( r == 6)
             return "6";
         else if (r == 7)
             return "7";
         else if (r == 8)
             return "8";
         else if (r == 9)
             return "9";
         else
             return "10";

    }// return "A", "2", ..."Q"


    //  input param: card RHS
    //  output: N/A
    //  operators that check for equality and inequality
    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;



private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);



#endif