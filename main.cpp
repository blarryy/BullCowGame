/* This is the console executable, that makes use of the 
BullCow class. This acts as the view in a MVC pattern, and is
responsible for all user interaction. For game logic, see 
FBullGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;
//function prototype
// if a function is written below the main function,
//you need to write the funciton prototype above the 
//main function

void printIntro();
void playGame();
Ftext getGuess();
bool askToPlayAgain();
void printGameSummary();
FBullCowGame BCGame;


void printIntro(){
    // constexpr int32 WORD_LENGTH = 5;
    std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
		std::cout << std::endl;
		std::cout << "          }   {         ___ " << std::endl;
		std::cout << "          (o o)        (o o) " << std::endl;
		std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
		std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
		std::cout << " *  |-,--- |              |------|  * " << std::endl;
		std::cout << "    ^      ^              ^      ^ " << std::endl;
    std::cout << "\n\nWelcome to the bull cow game" << std::endl;
    std::cout << "Can you Guess the " 
    << BCGame.GetHiddenWordLength() << " letter lowercase isogram I'm thinking of? \n\n"; 
}

Ftext getValidGuess(){
    EWordStatus status = EWordStatus::Invalid;
    Ftext guess;
    do{
        int32 currentTry = BCGame.getCurrentTry();
        std::cout <<  "Try " << currentTry << " of " << BCGame.getMaxTries()
        << std::endl;
        guess = "";
        std::cout << "Enter your guess\n";
        std::getline(std::cin, guess);
        //std::getline read through space, and it discards
        //intout stream once it reaches new-line character
        // std::cout << "your guess was: " << guess << std::endl;
        status = BCGame.checkGuessValidity(guess);
        switch(status){
            case EWordStatus::Wrong_Length:
                std::cout << "Please enter a " << 
                BCGame.GetHiddenWordLength() << " letter word\n"
                << std::endl;
                break;
            case EWordStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n\n";
                break;
            case EWordStatus::Not_Lowercase:
                std::cout << "Please enter a word with all lower case.\n\n";
                break;
            default:
                return guess;
        }
    }while(status != EWordStatus::OK);
    
    return guess;
}

void playGame(){
    BCGame.reset();
// loop for the number of turns asking for guesses
    int32 MaxTries = BCGame.getMaxTries();
    while(!BCGame.isGameWon() && BCGame.getCurrentTry() <= MaxTries){
        Ftext guess = getValidGuess();
        //submit valid guess, and recieve counts
        BullCowCount BullCowCount = BCGame.SubmitGuess(guess);
        // std::cout << "your guess was: " << guess << std::endl;
        std::cout << "Bulls are: " << BullCowCount.Bulls;
        std::cout << ". Cows are: " << BullCowCount.Cows << "\n\n";
    }
    //TODO: GAME SUMMARY
    printGameSummary();
}
void printGameSummary(){
    if (BCGame.isGameWon()){
        std::cout << "Congratulations, you won!!\n\n";
    }else{
        std::cout << "Ops, that was your last try, better luck next time!!\n\n";
    }
}


bool askToPlayAgain(){
    std::cout << "Do you wanna play again?";
    Ftext response = "";
    std::getline(std::cin, response);
    return (response[0] == 'y' || response[0] == 'Y');
}
//TODO: Game Summary

//don't change this int to int32
int main(){
    do{
        BCGame.reset();
        printIntro();
        playGame();
    }while(askToPlayAgain());
    
    return 0;
}

