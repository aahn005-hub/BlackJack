/*
Arnold Ahn
CIS7 Project
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){

    string name;
    int bet, input;
    int first_total;
    
    

    // prompts user to enter name and wager. starts the game
    cout << "Welcome to BlackJack!\n"; 
    cout << "What is your name?\n";
    cin  >> name;
    cout << "Hello " << name <<", how much are you wagering? ";
    cin  >> bet;
    cout << "You are betting $" << bet << "! Let us begin!\n";
    cout << endl;

    //random seed generator for card drawn
    srand((unsigned)time(0));
    
    // declares suits and randomizes it when they are played by dealer and player
    const string NUM_OF_SUITS[4] = {"Heart", "Club", "Diamond", "Spades"};
    string suits = NUM_OF_SUITS[rand() % 4];
    string suits1 = NUM_OF_SUITS[rand() % 4];
    string suits2 = NUM_OF_SUITS[rand() % 4];
    string suits3 = NUM_OF_SUITS[rand() % 4];
    string suits4 = NUM_OF_SUITS[rand() % 4];
    string suits5 = NUM_OF_SUITS[rand() % 4];
    
    //for cards drawn, 2-10, ace, jack, queen, king
    // 1 = ace, 11 = jack, 12 = queen, 13 = king
    int dealer_card_1 = rand() % 13 + 1;
    
    cout << "The dealer has drawn: "; 

    // switch statement for the non number cards. default if 
    // card is neither face cards
    switch(dealer_card_1){

        case 1:
        cout << "Ace of " << suits << " and ";
        break;
       
        case 11:
        cout << "Jack of " << suits << " and ";
        break;

        case 12:
        cout << "Queen of " << suits << " and ";
        break;
        
        case 13:
        cout << "King of "<< suits << " and ";
        break;

        default:
        cout << dealer_card_1 << " of " << suits << " and ";
        break;
    }
    cout << "a [Hidden Card]";

    cout << endl;

    // declaring player cards
    int player_card_1 = rand() % 13 + 1;
    int player_card_2 = rand() % 13 + 1;   
    cout << "You have drawn: ";  

    // same switch statement as the dealer cards but for both player cards
    switch(player_card_1){

        case 1:
        cout << "Ace of " << suits1 << " and ";
        break;
       
        case 11:
        cout << "Jack of " << suits1 << " and ";
        break;

        case 12:
        cout << "Queen of " << suits1 << " and ";
        break;
        
        case 13:
        cout << "King of "<< suits1 << " and ";
        break;

        default:
        cout << player_card_1 << " of " << suits1 << " and ";
        break;
    }
    switch(player_card_2){

        case 1:
        cout << "Ace of " << suits2 << ".";
        break;
       
        case 11:
        cout << "Jack of " << suits2 << ".";
        break;

        case 12:
        cout << "Queen of " << suits2 << ".";
        break;
        
        case 13:
        cout << "King of "<< suits2 << ".";
        break;

        default:
        cout << player_card_2 << " of " << suits2 << ".";
        break;
    }
    cout << endl;
    cout << endl;
    
    // if a card is a JQK card, change value to 10
    if(player_card_1 >= 11){
        player_card_1 = 10;
    } else if (player_card_2 >= 11){
        player_card_2 = 10;
    }

    int blackjack = 21;
    int lucky = blackjack - (player_card_1 + player_card_2); // 21 - (10 + 4) = 7
    
    // if user obtains an ace and a JQK, blackjack occurs and wins
    // Show user probability of winning for each player hand
    if(player_card_1 == 1 && player_card_2 >= 10) {
        cout << "Blackjack! you win $" << bet << "!.\n";
        return 0;
    } else if (player_card_1 >=10 && player_card_2 == 1){
        cout << "Blackjack! you win $" << bet << "!.\n";
        return 0;
    } else if (dealer_card_1 == lucky){
        cout << "Probability of getting blackjack from next hit: 5.7%" << endl;   
    } else if (player_card_1 == lucky){
        cout << "Probability of getting blackjack from next hit: 5.7%" << endl;     
    } else if (player_card_2 == lucky){
        cout << "Probability of getting blackjack from next hit: 5.7%" << endl;   
    } else if (dealer_card_1 == lucky && player_card_1 == lucky){
        cout << "Probability of getting blackjack from next hit: 3.9%" << endl;
    } else if (dealer_card_1 == lucky && player_card_2 == lucky){
        cout << "Probability of getting blackjack from next hit: 3.9%" << endl;
    } else if (lucky == 10 && dealer_card_1 != 10 && player_card_2 != 10 && dealer_card_1 != 10){
        cout << "Probability of getting blackjack from next hit: 23%" << endl;    
    } else if (lucky == 10 && dealer_card_1 == 10 && player_card_2 != 10 && dealer_card_1 != 10){
        cout << "Probability of getting blackjack from next hit: 21%" << endl;    
    } else if (lucky == 10 && dealer_card_1 != 10 && player_card_2 == 10 && dealer_card_1 != 10){
        cout << "Probability of getting blackjack from next hit: 21%" << endl;  
    } else if (lucky == 10 && dealer_card_1 != 10 && player_card_2 != 10 && dealer_card_1 == 10){
        cout << "Probability of getting blackjack from next hit: 21%" << endl;
    } else {
        cout << "Probability of getting blackjack from next hit: 7.7%" << endl;
    }
    
    //prompt user if they want to hit, stay, or quit
    cout << "Would you like to\n";
    cout << "1. Hit\n";
    cout << "2. Stay\n";
    cout << "3. Quit\n";
    
    cin  >> input;
    
    // if user hits, gets new card
    if (input == 1) {
        int input1;
        int total = player_card_1 + player_card_2;
        int hit_total = 0;  // total number that player has. needs to be greater than dealer's total 
                        // while below 21 to win

        // gets a new card until user stays or quits.
        do {
            // new random card
    
            int player_card_hit = rand() % 13 + 1;
            string suits_hit = NUM_OF_SUITS[rand() % 4];

            cout << "You have chosen to hit. Your next card is a ";
            
            // same switch statement as the other one
            switch(player_card_hit){
                case 1:
            cout << "Ace of " << suits_hit << ". ";
            break;
       
            case 11:
            cout << "Jack of " << suits_hit << ". ";
            break;

            case 12:
            cout << "Queen of " << suits_hit << ". ";
            break;
        
            case 13:
            cout << "King of "<< suits_hit << ". ";
            break;

            default:
            cout << player_card_hit << " of " << suits_hit << ". ";
            break;
            }
            
            // if hit card is JQK, value is 10
            if(player_card_hit >= 11){
                player_card_hit = 10;
            }
            
            hit_total += player_card_hit;
        
            // bust if player cards is higher than 21
            if (total + hit_total > 21){
                cout << "BUST! You lose $" << bet << "!\n";
                cout << "Thank you for playing.";
                break;
            } else if (total + hit_total == 21){                    // if cards + hit = 21
                cout << "Blackjack! you win $" << bet << "!.\n";
                return 0;
            } else if (total == 10 || hit_total == 1){              // if first two cards = 1 and hit is a JQK, blackjack  
                cout << "Blackjack! you win $" << bet << "!.\n";
                return 0;
            }
            cout << endl;
            // set probability of getting black jack for each hit
            int player_luck = lucky - (player_card_1 + player_card_2 + player_card_hit);
            
            if (dealer_card_1 == player_luck){
                cout << "Probability of getting blackjack from next hit: 5.7%" << endl;   
            } else if (player_card_1 == player_luck){
                cout << "Probability of getting blackjack from next hit: 5.7%" << endl;     
            } else if (player_card_2 == player_luck){
                cout << "Probability of getting blackjack from next hit: 5.7%" << endl;   
            } else if (player_card_hit == player_luck){
                cout << "Probability of getting blackjack from next hit: 5.7%" << endl;   
            } else if (dealer_card_1 == lucky && player_card_1 == player_luck){
                cout << "Probability of getting blackjack from next hit: 3.9%" << endl;
            } else if (dealer_card_1 == lucky && player_card_2 == player_luck){
                cout << "Probability of getting blackjack from next hit: 3.9%" << endl;
            } else if (player_luck == 10 && dealer_card_1 != 10 && player_card_2 != 10 && dealer_card_1 != 10){
                cout << "Probability of getting blackjack from next hit: 23%" << endl;    
            } else if (player_luck == 10 && dealer_card_1 == 10 && player_card_2 != 10 && dealer_card_1 != 10){
                cout << "Probability of getting blackjack from next hit: 21%" << endl;    
            } else if (player_luck == 10 && dealer_card_1 != 10 && player_card_2 == 10 && dealer_card_1 != 10){
                cout << "Probability of getting blackjack from next hit: 21%" << endl;  
            } else if (player_luck == 10 && dealer_card_1 != 10 && player_card_2 != 10 && dealer_card_1 == 10){
                cout << "Probability of getting blackjack from next hit: 21%" << endl;
            } else {
                cout << "Probability of getting blackjack from next hit: 7.7%" << endl;
            }

            cout << "Would you like to\n";
            cout << "1. Hit\n";
            cout << "2. Stay\n";
            cout << "3. Quit\n";
            cin  >> input1;
            
        }
        while (input1 == 1);
        

        if(input1 == 2){
            int dealer_card_2 = rand() % 13 + 1;
    
            cout << "The dealer's [Hidden Card] is a: "; 

            // switch statement for the non number cards. default if 
            // card is neither face cards
            switch(dealer_card_2){

                case 1:
                cout << "Ace of " << suits3 << ".";
                break;
       
                case 11:
                cout << "Jack of " << suits3 << ".";
                break;

                case 12:
                cout << "Queen of " << suits3 << ".";
                break;
        
                case 13:
                cout << "King of "<< suits3 << ".";
                break;

                default:
                cout << dealer_card_2 << " of " << suits3 << ".";
                break;
            }
            cout << endl;

            int dealer_total = dealer_card_1 + dealer_card_2;
        
            // dealer hits on 16 or less. stays on 17 or more. 
            if(dealer_total <= 16){
            cout << "Dealer hits! Draws a ";

                do {
 
                    int dealer_hit = rand() % 13 + 1;
                    string suits_hit_dealer = NUM_OF_SUITS[rand() % 4];

                    switch(dealer_hit){

                        case 1:
                        cout << "Ace of " << suits_hit_dealer << ".";
                        break;
       
                        case 11:
                        cout << "Jack of " << suits_hit_dealer << ".";
                        break;

                        case 12:
                        cout << "Queen of " << suits_hit_dealer << ".";
                        break;
        
                        case 13:
                        cout << "King of "<< suits_hit_dealer << ".";
                        break;

                        default:
                        cout << dealer_hit << " of " << suits_hit_dealer << ".";
                        break;
                    }
                    if(dealer_hit >= 11){
                        dealer_hit = 10;
                    }
                    dealer_total += dealer_hit;
                    if(dealer_total < 21){
                        cout << "\n Dealer Busts! You win $" << bet << "!\n";
                        return 0;
                    }
                    cout << endl;
    
                }
                while (dealer_total <= 16);

            } if (dealer_total >= 17 && dealer_total < 21){
                cout << "\nDealer Stays!\n";
            } else {
                cout << "\n Dealer Busts! You win $" << bet << "!\n";
                return 0;
            }
            first_total = player_card_1 + player_card_2 + hit_total;
            
            // determine whether player ties, wins, or loses
            if (first_total > dealer_total) {
                cout << "You win! You gain $" << bet << "!\n"; 
            } else if (first_total < dealer_total) {
                cout << "You lose! You lose $" << bet << "!\n";
            } else if (first_total == dealer_total){
                cout << "You Tie! you win and lose nothing!\n";
            }
            
        }
        if (input1 == 3){
            cout << "You lose $" << bet << "!\n";
            cout << "Thanks for playing!";
        }
    // After player stays, dealer hits
    }   else if (input == 2){
        
        int dealer_card_2 = rand() % 13 + 1;
    
        cout << "The dealer's [Hidden Card] is a: "; 

        // switch statement for the non number cards. default if 
        // card is neither face cards
        switch(dealer_card_2){

            case 1:
            cout << "Ace of " << suits3 << ".";
            break;
       
            case 11:
            cout << "Jack of " << suits3 << ".";
            break;

            case 12:
            cout << "Queen of " << suits3 << ".";
            break;
        
            case 13:
            cout << "King of "<< suits3 << ".";
            break;

            default:
            cout << dealer_card_2 << " of " << suits3 << ".";
            break;
        }
        cout << endl;

        if (dealer_card_1 >= 11){
            dealer_card_1 = 10;
        } else if (dealer_card_2 >=11){
            dealer_card_2 = 10;
        }

        int dealer_total = dealer_card_1 + dealer_card_2;
             
        // dealer hits on 16 or less. stays on 17 or more. 
        if(dealer_total <= 16){
            cout << "Dealer hits! Draws a ";

            do {
 
                int dealer_hit = rand() % 13 + 1;
                string suits_hit_dealer = NUM_OF_SUITS[rand() % 4];
                cout << "Draws a ";
                

                switch(dealer_hit){

                    case 1:
                    cout << "Ace of " << suits_hit_dealer << ".";
                    break;
       
                    case 11:
                    cout << "Jack of " << suits_hit_dealer << ".";
                    break;

                    case 12:
                    cout << "Queen of " << suits_hit_dealer << ".";
                    break;
        
                    case 13:
                    cout << "King of "<< suits_hit_dealer << ".";
                    break;

                    default:
                    cout << dealer_hit << " of " << suits_hit_dealer << ".";
                    break;
                }
                if(dealer_hit >= 11){
                    dealer_hit = 10;
                }
                dealer_total += dealer_hit;
                cout << endl;
    
            }
            while (dealer_total <= 16);

        } if (dealer_total >= 17 && dealer_total <= 21){
            cout << "\nDealer Stays!\n";
        } else if (dealer_total == 21){
            cout << "Dealer gets BlackJack! You lose $" << bet << "!\n";
            return 0;
        } else if (dealer_card_1 == 1 && dealer_card_2 == 10 || dealer_card_1 == 10 && dealer_card_1 == 1){
            cout << "Dealer gets BlackJack! You lose $" << bet << "!\n";
            return 0;
        } else {
            cout << "Dealer Bust! You win $" << bet << "!\n";
            return 0;
        }
        
        first_total = player_card_1 + player_card_2;
        
        // determine whether player ties, wins, or loses
        if (first_total > dealer_total) {
            cout << "You win! You gain $" << bet << "!\n"; 
        } else if (first_total < dealer_total) {
            cout << "You lose! You lose $" << bet << "!\n";
        } else if (first_total == dealer_total){
            cout << "You Tie! you win and lose nothing!\n";
        }       
    // if user does not press 1 or 2, game ends
    } else {
        cout << "Thanks for playing!";
    }
    return 0;
}