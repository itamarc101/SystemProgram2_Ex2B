#include <string>
#include <iostream>
using namespace std;
#include "card.hpp"

namespace ariel {
    Card::Card(Value value, Sign sign): value(value), sign(sign) {};
    
    string Card::toString() const {
        string valueStr, signStr;
        Value value = this->getValue();
        Sign sign = this->getSign();

        switch (value) {
            case Value::Ace: valueStr = "Ace"; break;
            case Value::Two: valueStr = "2"; break;
            case Value::Three: valueStr = "3"; break;
            case Value::Four: valueStr = "4"; break;
            case Value::Five: valueStr = "5"; break;
            case Value::Six: valueStr = "6"; break;
            case Value::Seven: valueStr = "7"; break;
            case Value::Eight: valueStr = "8"; break;
            case Value::Nine: valueStr = "9"; break;
            case Value::Ten: valueStr = "10"; break;
            case Value::Jack: valueStr = "Jack"; break;
            case Value::Queen: valueStr = "Queen"; break;
            case Value::King: valueStr = "King"; break;
        }

        switch (sign) {
            case Sign::Clubs: signStr = "Clubs"; break;
            case Sign::Diamonds: signStr = "Diamonds"; break;
            case Sign::Hearts: signStr = "Hearts"; break;
            case Sign::Spades: signStr = "Spades"; break;
        }

        return valueStr + " of " + signStr;
    }


}