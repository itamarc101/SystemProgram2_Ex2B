#include "player.hpp"

namespace ariel
{
    Player::Player(string name): name(name), cardWinNum(0), wins(0), lost(0) {};

    string Player::getName()
    {
        return name;
    }

    int Player::stacksize()
    {
        return pStack.size();
    }

    int Player::cardesTaken()
    {
        return cardWinNum;
    }

    void Player::addCard(Card card)
    {
        pStack.push_back(card);
    }

    void Player::playerWin(int cardWinNum)
    {   
        this->cardWinNum += cardWinNum;
        // int numOfCards = 0;
        //numOfCards += cardWinNum;
        //cardWinNum += 1;
        wins += 1;
    }

    void Player::playerLose()
    {
        lost++;
    }

    int Player::getWins()
    {
        return wins;
    }

    Card Player::getCard()
    {  
        Card curCard = pStack.back();
        pStack.pop_back();
        return curCard;
        //return pStack.back();
    }

    void Player::numOfCards(int CardWinNum)
    {
        cardWinNum+=cardWinNum;
    }
}