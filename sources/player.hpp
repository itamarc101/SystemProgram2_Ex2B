#pragma once
#include <string>
#include <vector>
#include "card.hpp"
using namespace std;

namespace ariel
{
    class Player
    {
        private:
        string name;
        vector<Card> pStack;
        int cardWinNum;
        int wins;
        int lost;
        //int numOfCards;

        public:
        Player(string name);
        string getName();
        int stacksize();
        int cardesTaken();

        Card getCard();
    //    void popCard();
        void addCard(Card card);
        void numOfCards(int cardWinNum);
        void playerWin(int cardWinNum);
        void playerLose();
        int getWins();

    };
}