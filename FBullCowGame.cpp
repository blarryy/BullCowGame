#include "FBullCowGame.h"
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define TMap std::map
// define and using is similar
using int32 = int;
//convention: put getters at the top
//const behind a member/class function decleration means 
// this function can't change any variables inside the class
int32 FBullCowGame::getMaxTries() const{return myMaxTries;}
int32 FBullCowGame::getCurrentTry() const {return myCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}
FBullCowGame::FBullCowGame(){
     reset();
}
//recieves a VALID guess, increments turn and return counts
BullCowCount FBullCowGame::SubmitGuess(FString Guess){
    // increment the turn number
    int32 HiddenWordLength = MyHiddenWord.length();
    myCurrentTry++;
    BullCowCount BullCowCount;
    for (int32 i = 0; i < HiddenWordLength; i++){
        for (int32 j = 0; j < HiddenWordLength; j++){
            if (Guess[i] == MyHiddenWord[j] && i == j){
                BullCowCount.Bulls++;
            }
            else if (Guess[i] == MyHiddenWord[j]){
                BullCowCount.Cows++;
            }
        }
    }
    if (BullCowCount.Bulls == HiddenWordLength)
        bGameIsWon = true;
    return BullCowCount;
}

void FBullCowGame::reset(){
    constexpr int32 MAX_TRIES = 8;
    srand (time(NULL));
    const FString HIDDEN_WORD = words[rand() % 5];
    myCurrentTry = 1;
    myMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    bGameIsWon = false;
    return;
}


bool FBullCowGame::isGameWon() const{
    return bGameIsWon;
}

EWordStatus FBullCowGame::checkGuessValidity (FString guess) const
{
    if (!IsIsogram(guess)){
        return EWordStatus::Not_Isogram;
    }else if (!IsLowercase(guess)){
        return EWordStatus::Not_Lowercase;
    }else if (guess.length() !=  GetHiddenWordLength()){
        return EWordStatus::Wrong_Length;
    }
    return EWordStatus::OK; //TODO
}

bool FBullCowGame::IsIsogram(FString guess) const
{   
    TMap<char, bool> LetterSeen;
    if (guess.length() <= 1)
        return true;
    for (auto Letter : guess){
        Letter = tolower(Letter);
        if(LetterSeen[Letter]) 
        {
            return false;
        }
        else
        {
            LetterSeen[Letter] = true;
        }
    }
    return true;
}

bool FBullCowGame::IsLowercase(FString guess) const{
    for (auto letter : guess){
        if (!islower(letter))
            return false;
    }
    return true;
}