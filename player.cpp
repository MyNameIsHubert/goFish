//
// Created by Hubert ECE on 11/6/2018.
//
#include <iostream>
#include <string>
#include "player.h"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

Player::Player(){
    myName = "";
}

void Player::addCard(Card c)
{
    myHand.push_back(c);

}//adds a card to the hand
void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2)
{
    for(int i =0; i< getHandSize(); i++){

        for(int j = i+1; j< getHandSize(); j++){
            if(myHand[i].getRank() == myHand[j].getRank())
            {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }

    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2)
{
    for(int i =0; i< getHandSize(); i++){

        for(int j = i+1; j< getHandSize(); j++){
            if(myHand[i].getRank() == myHand[j].getRank())
            {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }

    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c