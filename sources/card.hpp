#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel 
{
    enum class Sign
    {
        Clubs = 1,
        Diamonds,
        Hearts,
        Spades
    };

    enum class Value
    {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    class Card {
        private:
        Value value;
        Sign sign;

        public:
        Card(Value value, Sign sign);

        Value getValue() const { return value; }

        Sign getSign() const { return sign; }

        string toString() const;
    };

}
