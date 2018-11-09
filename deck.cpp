//
// Created by Hubert ECE on 11/6/2018.
//
#include <iostream>
#include <string>
#include "deck.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include "time.h"

using namespace std;

Deck::Deck()
{

    myIndex = 0;
    int i =0;
    int crank = 1;
    bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
    while(i < 52)
    {
        for(int j = i; j< i+4; j++)
        {
            if(flag1)
            {
                myCards[j] = Card(crank, Card::spades);
                flag1 = false;
                continue;
            }
            else if(flag2) {
                myCards[j] = Card(crank, Card::hearts);
                flag2 = false;
                continue;
            }
            else if(flag3)
            {
                myCards[j] = Card(crank, Card::diamonds);
                flag3 = false;
                continue;
            }
            else if(flag4)
            {
                myCards[j] = Card(crank, Card::clubs);
                flag4 = false;
                continue;
            }
        }
        i+=4;
        crank++;
        flag1 = true, flag2 = true, flag3 = true, flag4 = true;

    }


}

void Deck::shuffle(){

    srand(time(NULL));
    int x =0;
    Card tempholder;

    for(int i=0; i<size(); i++)
    {
        x = rand()%size();
        tempholder = myCards[i];
        myCards[i] = myCards[x];
        myCards[x] = tempholder;
    }

}

Card Deck::dealCard(){

    Card dealtc;

    if(size() != 1 || size() != 0) {

       dealtc = myCards[myIndex];
       myIndex++;
    }

    return dealtc;

}
