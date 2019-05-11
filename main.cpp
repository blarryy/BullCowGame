#include <iostream>
#include <string>
#include "FBullCowGame.h"

//function prototype
// if a function is written below the main function,
//you need to write the funciton prototype above the 
//main function

void printIntro();
void playGame();
std::string getGuess();
bool askToPlayAgain();
FBullCowGame BCGame;


void printIntro(){
    constexpr int WORD_LENGTH = 5;
    std::cout << "Can you Guess " << WORD_LENGTH 
    << " letter isogram I'm thinking of? \n"; 
}

std::string getGuess(){
    std::string guess = "";
    std::cout << "Enter your guess\n";
    std::getline(std::cin, guess);
    //std::getline read through space, and it discards
    //intout stream once it reaches new-line character
    // std::cout << "your guess was: " << guess << std::endl;
    return guess;
}

void playGame(){
    BCGame.reset();
// loop for the number of turns asking for guesses
    int currentTry = BCGame.getCurrentTry();
    std::cout <<  "Try " << currentTry << "." << std::endl;
    constexpr int NUMBER_OF_TURNS = 5;
    for (int count = 1; count <= NUMBER_OF_TURNS; count++){
        std::string guess = getGuess();
        //TODO check if guess is valid

        //submit valid guess to game
        //print num of bulls and cows
        std::cout << "your guess was: " << guess << std::endl;
    }
    //TODO: GAME SUMMARY
}

bool askToPlayAgain(){
    std::cout << "Do you wanna play again?";
    std::string response = "";
    std::getline(std::cin, response);
    return (response[0] == 'y' || response[0] == 'Y');
}
//TODO: Game Summary


int main(){
    std::cout << BCGame.getCurrentTry() << std::endl;
    std::cout << BCGame.getMaxTries() << std::endl;
    do{
        printIntro();
        playGame();
    }while(askToPlayAgain());
    
    return 0;
}

