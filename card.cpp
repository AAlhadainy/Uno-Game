#include "card.h"
#include <iostream>

using namespace std;

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

ReverseCard::ReverseCard(Color c) {
    setColor(c);
    setNumber(20);
}

SkipCard::SkipCard(Color c) {
    setColor(c);
    setNumber(30);
}

Draw2Card::Draw2Card(Color c) {
    setColor(c);
    setNumber(40);
}

WildCard::WildCard(Color c) {
    setColor(c);
    setNumber(50);
}

Draw4Card::Draw4Card(Color c) {
    setColor(c);
    setNumber(60);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
    
    
}

string ReverseCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|  REVERSE  |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
    
    
}

string SkipCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   SKIP    |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

    
string Draw2Card::render(int line) const{
        stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   DRAW 2  |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
    
    
}

string WildCard::render(int line) const{
        stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   WILD    |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
    
    string Draw4Card::render(int line) const{
        stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   DRAW 4  |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
    
    
    
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}
    
bool ReverseCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
       if(gameState.turnDirection == LEFT){
       gameState.turnDirection = RIGHT;
    } 
    /*else if(gameState.turnDirection == RIGHT){
       gameState.turnDirection = LEFT;
    }*/ else {
         gameState.turnDirection = LEFT;
    }
        return true;
    } else {
        return false;
    }
}
    
    bool SkipCard::play(Card* discard, GameState &gameState) {
        if(color == discard->getColor() || number == discard->getNumber()){
        gameState.skipTurn = true;
        return true;
    } else {
        return false;
    }
    }
    
    bool Draw2Card::play(Card* discard, GameState &gameState) {
      if(color == discard->getColor() || number == discard->getNumber()){
        gameState.numCardsToDraw = 2;
        return true;
    } else {
        return false;
    }
    }
   
    bool WildCard::play(Card* discard, GameState &gameState) {
       cout << "What color would you like to use?\n0: RED, 1: BLUE, 2: GREEN, 3: YELLOW." << endl;
       int newColor;
       do{
       cin >> newColor;
       if (newColor < 0 || newColor > 3){
           cout << "Wrong value, please make sure to enter: 0: RED, 1: BLUE, 2: GREEN, 3: YELLOW." << endl;
       }
       } while(newColor < 0 || newColor > 3);
       setColor((Color)newColor);
       //cout << "**" <<  getColor() << endl;
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
    }

   
    bool Draw4Card::play(Card* discard, GameState &gameState) {
        cout << "What color would you like to use?\n0: RED, 1: BLUE, 2: GREEN, 3: YELLOW." << endl;
        int newColor;
        do{
            cin >> newColor;
            if (newColor < 0 || newColor > 3){
                cout << "Wrong value, please make sure to enter: 0: RED, 1: BLUE, 2: GREEN, 3: YELLOW." << endl;
            }
       } while(newColor < 0 || newColor > 3);
        setColor((Color)newColor);
        if(color == discard->getColor() || number == discard->getNumber()){
        gameState.skipTurn = true;
        gameState.numCardsToDraw = 4;
        return true;
    } else {
        return false;
    }
    }