#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "game_state.h"
#include "card.h"

using namespace std;

void clearTerminal();

void buildDeck(vector<Card*>& deck);

void shuffleDeck(vector<Card*>&);

void drawCards(vector<Card*>& deck, vector<Card*>& target, int);

void populateHands(vector<Card*>& deck, vector<vector<Card*>>& hands);

void renderHand(vector<Card*> hand);

void renderDiscard(vector<Card*>);

void takeTurn(vector<Card*>& deck, vector<Card*>& hand, vector<Card*>& discard, GameState& gameState);

int main(){
    srand(time(0));
    int numPlayers;
    const int NUM_PLAYERS = 4;
   // const int NUM_ReverseCard = 5;
    
    
    vector<Card*> deck;
    vector<Card*> discard;
    buildDeck(deck);
    shuffleDeck(deck);
    drawCards(deck, discard, 1);
    
    
    cout << "How many players would you like to include in the game? (Minimum 2 and maximum 10)" << endl;
    cout << "For default number ("<< NUM_PLAYERS <<") of players enter 0." << endl;
    do {
    cin>>numPlayers;
    if (numPlayers != 0){
       numPlayers = numPlayers;
    } else {
        numPlayers = NUM_PLAYERS;
    }
    if (numPlayers < 0 || numPlayers == 1 || numPlayers > 10){
    cout << "Wrong value, please enter a valid number of players. \n (i.e) Minimum 2 and Maximum 10 or Zero for default." << endl;
    }
    } while (numPlayers < 0 || numPlayers == 1 || numPlayers > 10);


    GameState gameState(numPlayers);
    vector<vector<Card*>> hands(numPlayers);
    populateHands(deck, hands);
    
    while(1/*hands.at(gameState.currentPlayerIndex).size( ) != 0*/){
        takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState);
        int temp;
        if (gameState.turnDirection == LEFT){
            temp = gameState.currentPlayerIndex - 1;
            if (temp == -1)
                temp = numPlayers - 1; 
        } else {
             temp = gameState.currentPlayerIndex + 1;
            if (temp == numPlayers)
                temp = 0;
       
        }
        if (hands.at(temp).size( ) == 0){
            cout << "Player " << temp << " wins and says UNO!!!!!!!!!!!";
            break;
        }
        if(deck.size() == 0){
            //deck = discard;
            //discard.erase(discard.begin(), dicsard.end()-1);
            //for (int i = 0; i < discard.size() - 1; i++){
            while(discard.size() >  1){
                deck.push_back(discard.at(0));
                discard.erase(discard.begin());
            }
            shuffleDeck(deck);
        }
        cout << "Deck " << deck.size() << " discard " << discard.size() << endl;
        
    }

    //cout << "Player " << gameState.currentPlayerIndex - 1 << " wins and says UNO!!!!!!!!!!!";
  
               /*if (gameState.currentPlayerIndex - 1 == 0 || gameState.currentPlayerIndex + 1 == 0 ){
        break;}*/ 
        
    return 0;
}

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

void buildDeck(vector<Card*> &deck){

    for(int c = RED; c < NUM_COLORS; c++){
        for(int n = 0; n < 10; n++){
            Card* temp = new NumberCard((Color)c, n);
            deck.push_back(temp);
            deck.push_back(temp);
        }
    }
    //(part for defining cards for main)
     for(int c = RED; c < NUM_COLORS; c++){
        //for(int i = 0; i < 5; i++){
            Card* temp = new ReverseCard((Color)c);
            deck.push_back(temp);
        //}
    }
   
    for(int c = RED; c < NUM_COLORS; c++){
        //for(int i = 0; i < 5; i++){
            Card* temp = new SkipCard((Color)c);
            deck.push_back(temp);
        //}
    }
    
   for(int c = RED; c < NUM_COLORS; c++){
        //for(int i = 0; i < 5; i++){
            Card* temp = new Draw2Card((Color)c);
            deck.push_back(temp);
       // }
    }
    
    
    for(int c = RED; c < NUM_COLORS; c++){
        // for(int i = 0; i < 10; i++){
            Card* temp = new WildCard((Color)c);
            deck.push_back(temp);
       // }
    }
    
   // for(int c = RED; c < NUM_COLORS; c++){
      // for(int i = 0; i < 20; i++){
        Card* temp = new Draw4Card((Color)0);
        deck.push_back(temp);
       // }
   // }
    
    }
    

void shuffleDeck(vector<Card*> &deck){
    for(int i = 0; i < 1000; i++){
        int idx1 = rand() % deck.size();
        int idx2 = rand() % deck.size();
        Card* temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}

void drawCards(vector<Card*> &deck, vector<Card*> &target, int numToDraw){
    for(int i = 0; i < numToDraw; i++){
        if(deck.size() > 0){
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back();
        } else {
            cout << "WARNING: Deck out of cards" << endl;
        }
    }
}

void populateHands(vector<Card*> &deck, vector<vector<Card*>> &hands){
    for(int i = 0; i < hands.size(); i++){
        drawCards(deck, hands.at(i), 7);
    }
}

void renderHand(vector<Card*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand.at(j)->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void renderDiscard(vector<Card*> discard){
    for(int i = 0; i <= 7; i++){
        cout << discard.at(discard.size() - 1)->render(i) << endl;
    }
}

void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameState &gameState){
    clearTerminal();
    renderDiscard(discard);
    cout << "Player " << gameState.currentPlayerIndex << "'s turn." << endl;
    
    // TODO: Draw cards if necessary (draw 2 card)
    drawCards(deck, hand, gameState.numCardsToDraw);
    gameState.numCardsToDraw = 0; 
    
    renderHand(hand);
    
    if(!gameState.skipTurn){
        // Collect user input
        cout << "What would you like to do?" << endl;
        int i;
        for(i = 0; i < hand.size(); i++){
            cout << i << ": Play Card" << endl;
        }
        cout << i << ": Draw a Card" << endl;
        int input;
        cin >> input;
        
        if(input < i){
           
            if(hand.at(input)->play(discard.at(discard.size()-1), gameState)){
                Card* temp;
                temp = hand.at(input);
                discard.push_back(temp);
                hand.erase(hand.begin() + input); // Remove card in hand at position "input"
            } else {
                cout << "Improper choice" << endl;
                takeTurn(deck, hand, discard, gameState);
                return;
            }
        }else if(input == i){
            drawCards(deck, hand, 1);
        }
    }else{
        gameState.skipTurn = false;
    }
    
    gameState.nextTurn();
}
