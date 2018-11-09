// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides ofs and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    ofstream ofs;
    ofs.open ("goFish.txt", std::ofstream::out | std::ofstream::app);
    
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    ofs << p1.getName() <<" has : " << p1.showHand() << endl;
    ofs << p2.getName() <<" has : " << p2.showHand() << endl;
    ofs<<endl;

    Card joeChoose;
    Card janeChoose;
    Card joeRemove;
    Card janeRemove;
    Card joeBook1, joeBook2;
    Card janeBook1, janeBook2;
    int ct;
    int joeR = 0;
    int janeR = 0;

    while(p1.checkHandForBook(joeBook1, joeBook2))
    {
        ofs << "Joe is booking: " << joeBook1.toString() << " and " << joeBook2.toString() << endl;
        p1.bookCards(joeBook1, joeBook2);
        p1.removeCardFromHand(joeBook1);
        p1.removeCardFromHand(joeBook2);
        ofs << "Joe's book is currently: " << p1.showBooks() << endl;

    }
    ofs<<endl;
    while(p2.checkHandForBook(janeBook1, janeBook2))
    {
        ofs << "Jane is booking: " << janeBook1.toString() << " and " << janeBook2.toString() << endl;
        p2.bookCards(janeBook1,janeBook2);
        p2.removeCardFromHand(janeBook1);
        p2.removeCardFromHand(janeBook2);
        ofs << "Jane's book is currently: " << p2.showBooks() << endl;
    }

    ofs<<endl;


    /*////////////////////////////////////////////Game begins///////////////////////////////////////////////*/



    while(d.size() != 0){

        ofs<<endl;
        ofs <<"------------------------------------------------------Player One's Turn--------------------------------------------" << endl;
        ofs<<endl;

        ct = 1; //current turn

        ofs << p1.getName() <<" currently has : " << p1.showHand() << endl;
        ofs << p2.getName() <<" currently has : " << p2.showHand() << endl;

        ofs<<endl;
        ofs<<endl;


        joeChoose = p1.chooseCardFromHand();
        joeR = joeChoose.getRank();


        //Joe's Turn
        if(p1.getHandSize() != 0) {

            ofs << "Joe: Do you have any " << p1.chooseCardFromHand().rankString(joeR) << "s" << endl;

            while (p2.cardInHand(joeChoose)) {
                ofs << "Jane: Yes." << endl;
                janeRemove = p2.removeCardFromHand(joeChoose);

                p1.addCard(janeRemove);
                if (p1.checkHandForBook(joeBook1, joeBook2)) {
                    ofs << "Joe is booking: " << joeBook1.toString() << " and " << joeBook2.toString() << endl;
                    p1.bookCards(joeBook1, joeBook2);
                    p1.removeCardFromHand(joeBook1);
                    p1.removeCardFromHand(joeBook2);
                    ofs << "Joe's book is currently: " << p1.showBooks() << endl;
                    ofs << endl;

                }



                if(p1.getHandSize() !=0) {
                    joeChoose = p1.chooseCardFromHand();
                    joeR = joeChoose.getRank();
                    ofs << "Joe: Do you have any " << p1.chooseCardFromHand().rankString(joeR) << "s" << endl;
                }
            }

            if(p1.getHandSize() != 0)
            ofs << "Jane: No. Go Fish." << endl;
            ct = 2;
        }
        ofs << endl;

        if(d.size() !=0) {
            dealHand(d, p1, 1);  //add a card to p1 hand (Joe)
            ofs << "Joe is drawing a card from the deck." << endl;
        }
        else
        {
            ofs << "Joe attempts to draw, but there are no more cards in the deck." << endl;
        }

        if(p1.checkHandForBook(joeBook1, joeBook2))
        {
            ofs << "Joe is booking: " << joeBook1.toString() << " and " << joeBook2.toString() << endl;
            p1.bookCards(joeBook1,joeBook2);
            p1.removeCardFromHand(joeBook1);
            p1.removeCardFromHand(joeBook2);
            ofs << "Joe's book is currently: " << p1.showBooks() << endl;
            ofs<<endl;

        }


        ofs<<endl;
        ofs <<"------------------------------------------------------Player Two's Turn-------------------------------------------" << endl;
        ofs<<endl;

        ct = 2; //current turn

        ofs << p1.getName() <<" currently has : " << p1.showHand() << endl;
        ofs << p2.getName() <<" currently has : " << p2.showHand() << endl;

        janeChoose = p2.chooseCardFromHand();
        janeR = janeChoose.getRank();

        ofs<<endl;
        ofs<<endl;



        //Jane's Turn
        if(p2.getHandSize() != 0) {

            ofs << "Jane: Do you have any " << p2.chooseCardFromHand().rankString(janeR) << "s" << endl;

            while (p1.cardInHand(janeChoose)) {
                ofs << "Joe: Yes." << endl;
                joeRemove = p1.removeCardFromHand(janeChoose);
                p2.addCard(joeRemove);
                if (p2.checkHandForBook(janeBook1, janeBook2)) {
                    ofs << "Jane is booking: " << janeBook1.toString() << " and " << janeBook2.toString() << endl;
                    p2.bookCards(janeBook1, janeBook2);
                    p2.removeCardFromHand(janeBook1);
                    p2.removeCardFromHand(janeBook2);
                    ofs << "Jane's book is currently: " << p2.showBooks() << endl;
                    ofs << endl;

                }

                if(p2.getHandSize() !=0) {
                    janeChoose = p2.chooseCardFromHand();
                    janeR = janeChoose.getRank();
                    ofs << "Jane: Do you have any " << p2.chooseCardFromHand().rankString(janeR) << "s" << endl;
                }
            }

            if(p2.getHandSize() !=0)
            ofs << "Joe: No. Go Fish." << endl;
            ct = 1;
        }
        ofs<<endl;
        if(d.size() !=0) {
            dealHand(d, p2, 1);  //add a card to p1 hand (Joe)
            ofs << "Jane is drawing a card from the deck." << endl;
        }
        else
        {
            ofs << "Jane attempts to draw from the deck, but there are no more cards in the deck." << endl;
        }


        if(p2.checkHandForBook(janeBook1, janeBook2))
        {
            ofs << "Jane is booking: " << janeBook1.toString() << " and " << janeBook2.toString() << endl;
            p2.bookCards(janeBook1,janeBook2);
            p2.removeCardFromHand(janeBook1);
            p2.removeCardFromHand(janeBook2);
            ofs << "Jane's book is currently: " << p2.showBooks() << endl;
            ofs<<endl;

        }
    }

    //last turn

    if(p1.getHandSize() == 0 && p2.getHandSize() == 0)
    {
        ofs<< "--------------------------------------------------WINNER--------------------------------------" << endl;
        if(p1.getBookSize() > p2.getBookSize())
            ofs << p1.getName() <<" is the winner." << endl;
        else if(p1.getBookSize() < p2.getBookSize())
            ofs << p2.getName() << " is the winner." << endl;
        else
            ofs << "It is a tie. " << endl;

        ofs.close();
        return EXIT_SUCCESS;

    }




    while( p1.getHandSize() !=0 && p2.getHandSize() !=0) {
        if (ct == 1) {
            ofs << "------------------------------------------------------Player One's Turn-------------------------------------------" << endl;
            ofs << endl;
            ofs << p1.getName() <<" currently has : " << p1.showHand() << endl;
            ofs << p2.getName() <<" currently has : " << p2.showHand() << endl;
            ofs << endl;
            joeChoose = p1.chooseCardFromHand();
            joeR = joeChoose.getRank();

            ofs << "Joe: Do you have any " << p1.chooseCardFromHand().rankString(joeR) << "s" << endl;


            //Joe's Turn
            if (p1.getHandSize() != 0) {
                while (p2.cardInHand(joeChoose)) {
                    ofs << "Jane: Yes." << endl;
                    janeRemove = p2.removeCardFromHand(joeChoose);

                    p1.addCard(janeRemove);
                    if (p1.checkHandForBook(joeBook1, joeBook2)) {
                        ofs << "Joe is booking: " << joeBook1.toString() << " and " << joeBook2.toString() << endl;
                        p1.bookCards(joeBook1, joeBook2);
                        p1.removeCardFromHand(joeBook1);
                        p1.removeCardFromHand(joeBook2);
                        ofs << "Joe's book is currently: " << p1.showBooks() << endl;
                        ofs << endl;

                    }


                    if (p1.getHandSize() != 0) {
                        joeChoose = p1.chooseCardFromHand();
                        joeR = joeChoose.getRank();
                        ofs << "Joe: Do you have any " << p1.chooseCardFromHand().rankString(joeR) << "s" << endl;
                    }
                }

                if (p1.getHandSize() != 0)
                    ofs << "Jane: No. Go Fish." << endl;


            }
        } else {

            ofs << "------------------------------------------------------Player Two's Turn-------------------------------------------" << endl;
            ofs << endl;
            ofs << p1.getName() <<" currently has : " << p1.showHand() << endl;
            ofs << p2.getName() <<" currently has : " << p2.showHand() << endl;
            ofs << endl;
            janeChoose = p2.chooseCardFromHand();
            janeR = janeChoose.getRank();

            ofs << endl;
            ofs << endl;

            ofs << "Jane: Do you have any " << p2.chooseCardFromHand().rankString(janeR) << "s" << endl;

            //Jane's Turn
            if (p2.getHandSize() != 0) {
                while (p1.cardInHand(janeChoose)) {
                    ofs << "Joe: Yes." << endl;
                    joeRemove = p1.removeCardFromHand(janeChoose);
                    p2.addCard(joeRemove);
                    if (p2.checkHandForBook(janeBook1, janeBook2)) {
                        ofs << "Jane is booking: " << janeBook1.toString() << " and " << janeBook2.toString() << endl;
                        p2.bookCards(janeBook1, janeBook2);
                        p2.removeCardFromHand(janeBook1);
                        p2.removeCardFromHand(janeBook2);
                        ofs << "Jane's book is currently: " << p2.showBooks() << endl;
                        ofs << endl;

                    }

                    if (p2.getHandSize() != 0) {
                        janeChoose = p2.chooseCardFromHand();
                        janeR = janeChoose.getRank();
                        ofs << "Jane: Do you have any " << p2.chooseCardFromHand().rankString(janeR) << "s" << endl;
                    }
                }

                if (p2.getHandSize() != 0)
                    ofs << "Joe: No. Go Fish." << endl;

            }
        }
    }

    if(p1.getHandSize() == 0 && p2.getHandSize() == 0)
    {
        ofs<< "--------------------------------------------------WINNER--------------------------------------" << endl;
        if(p1.getBookSize() > p2.getBookSize())
            ofs << p1.getName() <<" is the winner." << endl;
        else if(p1.getBookSize() < p2.getBookSize())
            ofs << p2.getName() << " is the winner." << endl;
        else
            ofs << "It is a tie." << endl;

        ofs.close();
        return EXIT_SUCCESS;

    }

    ofs.close();
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



