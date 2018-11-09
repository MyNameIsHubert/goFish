// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include <random>
#include "time.h"

using namespace std;


class Player
{
public:
    Player();//default constructor

    Player(string name) { //constructor with a name parameter to name a player
        myName = name;
    }

    //input param: N/A
    //output: N/A
    //returns players name
    string getName() const {
        return myName;
    }
    //input param: N/A
    //output: N/A
    //adds card to players hand
    void addCard(Card c);
    //input param: N/A
    //output: N/A
    //adds card to players book
    void bookCards(Card c1, Card c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?

    bool rankInHand(Card c) const
    {
        for(int i=0; i<getHandSize(); i++){
            if(myHand[i].getRank() == c.getRank())
                return true;
        }

        return false;
    }

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    //input param: N/A
    //output: a card
    //returns the first card in the hand, to eliminate in order
    Card chooseCardFromHand() const
    {
        return myHand[0];
    }

    //Does the player have the card c in her hand?
    //input param: card c
    //output: a card
    //returns a T/F to see if card is in hand or not
    bool cardInHand(Card c) const
    {
        for(int i=0; i<getHandSize(); i++){
            if(myHand[i].getRank() == c.getRank())
                return true;
        }

        return false;
    }

    //Remove the card c from the hand and return it to the caller
    //input param: card C
    //output: a card
    //returns the removed card from the hand
    Card removeCardFromHand(Card c)
    {
        Card temp, removed;
        if(getHandSize() != 1)
        {
            for(int i =0; i<getHandSize(); i++){

                for(int j = i+1; j < getHandSize(); j++) {

                    if (myHand[i].getRank() == c.getRank()) {
                    temp = myHand[i];
                    myHand[i] = myHand[j];
                    myHand[j] = temp;
                    }
                }
            }

        }

       removed = myHand[getHandSize()-1];
       myHand.pop_back();

       return removed;


    }

    //input param: N/A
    //output: a string of the hand
    //returns a string spelling out all the cards in a players hand
    string showHand() const
    {

        string hand;
        for(int i =0; i<getHandSize(); i++){
            hand += myHand[i].toString() + ", ";
        }

        return hand;
    }
    //input param: N/A
    //output: a string of the book
    //returns a string spelling out all the cards in a players book
    string showBooks() const
    {
        string book;
        for(int i =0; i<getBookSize(); i++){
            book += myBook[i].toString() + ", ";
        }

        return book;
    }

    //input param: N/A
    //output: an int
    //returns an int representing the size of a players hand
    int getHandSize() const
    {
        return myHand.size();
    }
    //input param: N/A
    //output: an int
    //returns an int representing the size of a players book
    int getBookSize() const
    {
        return myBook.size();
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    //bool sameRankInHand(Card c) const;






private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif