//
// Created by Hubert ECE on 11/6/2018.
//

#include <iostream>
#include "card.h"

using namespace std;

Card::Card()
{
    myRank = 1;
    mySuit = spades;

}

Card::Card(int rank, Suit s)
{
    myRank = rank;
    mySuit = s;

}


bool Card::operator == (const Card& rhs) const
{
        return (myRank == rhs.myRank && mySuit == rhs.mySuit);
}
bool Card::operator != (const Card& rhs) const
{
    return (myRank != rhs.myRank || mySuit != rhs.mySuit);
}



