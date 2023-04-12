#pragma once
#include "card.hpp"
#include "player.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    class Game
    {
        private:
        Player& player1;
        Player& player2;
        vector<Card> sstack;
        vector<string> log;
        int drawCount;
        int turnsCount;
        string lastTrun;
        int p1Win;
        int p2Win;

        public:
        Game(Player& player1, Player& player2);
        void playAll();
        void printWiner();
        void printLog();
        void playTurn();
        void printStats();
        void printLastTurn();

        void updateLog(string warLog);
    };
}