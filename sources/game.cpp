#include "game.hpp"
#include "card.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

namespace ariel
{
    Game::Game(Player& player1, Player& player2): player1(player1), player2(player2), drawCount(0), turnsCount(0), p1Win(0), p2Win(0)
    {
        for(int i = 1; i <= 13; i++)
        {
            sstack.push_back(Card((Value)i, Sign::Clubs));
            sstack.push_back(Card((Value)i, Sign::Diamonds));
            sstack.push_back(Card((Value)i, Sign::Hearts));
            sstack.push_back(Card((Value)i, Sign::Spades));
        }

        // SHUFFLE
        srand(time(NULL));
        for(int i = 52; i > 0; i--)
        {
            int j = rand() % 52;
            Card temp = sstack[(unsigned int) i];
            sstack[(unsigned int) i] = sstack[(unsigned int) j];
            sstack[(unsigned int) j] = temp;
        }

        //DEAL CARDS
        for(int i = 0; i < 52; i++)
        {
            if (i % 2 == 0) player1.addCard(sstack[(unsigned int) i]);
            else player2.addCard(sstack[(unsigned int) i]);
        }
    }


    void Game::playTurn()
    {
        turnsCount++;
        if(player1.stacksize() == 0 || player2.stacksize() == 0) 
            throw runtime_error("Player has no cards ERROR!");
        if(&player1 == &player2) 
            throw runtime_error("One Player ERROR! ");
        if(turnsCount > 26)
            throw runtime_error("Game is only to be played up to 26 turns ERROR!");
        
        int cardsOnRound = 0;
        
        vector<Card> currentStack;
        Card player1C = player1.getCard();
        Card player2C = player2.getCard();
        currentStack.push_back(player1C);
        currentStack.push_back(player2C);
        cardsOnRound += 2;

        string warToString = player1.getName() + " Played " + player1C.toString() + " ---" + player2.getName() + " Played " + player2C.toString() + ". ";

        

        while(player1C.getValue() == player2C.getValue())     // DRAW!
        {
            drawCount++;
            warToString += "Draw. ";
            lastTrun = "Draw. ";
            if(player1.stacksize() <= 1 || player2.stacksize() <= 1)
            {
                if(player1.stacksize() == 1 && player2.stacksize() == 1){
                    //cardsOnRound += 2;
                    player1C = player1.getCard();
                    player2C = player2.getCard();
                    currentStack.push_back(player1C);
                    currentStack.push_back(player2C);
                }
                Card second1 = player1.getCard();
                Card second2 = player2.getCard();
                while (!currentStack.empty())
                {
                currentStack.push_back(second1);
                currentStack.push_back(second2);
                }
                player1.playerWin(cardsOnRound/2);
                player2.playerWin(cardsOnRound/2);
                break;
            }
            else
            {   
                cardsOnRound += 2;
                player1C = player1.getCard();
                player2C = player2.getCard();
                currentStack.push_back(player1C);
                currentStack.push_back(player2C);
            }

        }
        //cardsOnRound += 2;
        if((player1C.getValue() == (Value)1 && player2C.getValue() != (Value)2) || player1C.getValue() > player2C.getValue())
        { //player 1 wins
        
            lastTrun = player1.getName() + " wins! ";
            warToString += player1.getName() + " wins!";
            player1.playerWin(cardsOnRound);
            p1Win++;
            player2.playerLose();
        }
        else if((player2C.getValue() == (Value)1 && player1C.getValue() != (Value)2) || player2C.getValue() > player1C.getValue())
        { //player2 wins
            lastTrun = player2.getName() + " wins! ";
            warToString += player2.getName() + " wins!";
            player2.playerWin(cardsOnRound);
            p2Win++;
            player1.playerLose();
        }


    }

    void Game::updateLog(string warToString)
    {
        log.push_back(warToString);
    }

    void Game::printLastTurn()
    {
        cout << lastTrun << endl;
    }

    void Game::playAll()
    {
        while(player1.stacksize() > 0 || player2.stacksize() > 0 )
        {
            playTurn();
        }
    }

    void Game::printWiner()
    {
        if(player1.cardesTaken() == player2.cardesTaken()) cout << "Draw! " << endl;
        else if (player1.cardesTaken() > player2.cardesTaken()) cout << "The Winner is! - " <<  player1.getName() << endl;
        else if (player1.cardesTaken() < player2.cardesTaken()) cout << "The Winner is! - " <<  player2.getName() << endl;
    }

    void Game::printLog()
    {
        for(int i = 0; i < log.size(); i++)
        {
            cout << log[(unsigned int) i] << endl;
        }
    }

    void Game::printStats()
    {
        cout << player1.getName() << " win rate: " << (double)(((double)player1.getWins()/(double)turnsCount)*100) << endl;
        cout << player1.getName() << " cards won: " << player1.cardesTaken() << endl;

        cout << player2.getName() << " win rate: " << (double)(((double)p2Win/(double)turnsCount)*100) << endl;
        cout << player2.getName() << " cards won: " << player2.cardesTaken() << endl;

        cout << "Draws: " << (double)(((double)drawCount/(double)turnsCount)*100) << endl;
    }

}









        // {
        //     drawCount++;
        //     warToString += "Draw. ";
            

        //     if(player1.stacksize() <= 1 || player2.stacksize() <= 1)
        //     {
        //         break;
        //     }
        //     else if (player1.stacksize() > 1 || player2.stacksize() > 1)
        //     {
        //         break;
        //     }

        //     player1.getCard();
        //     player2.getCard();

        //     warToString += player1.getName() + " played " + 
        // }



    
