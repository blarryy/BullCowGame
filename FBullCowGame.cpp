#include "FBullCowGame.h"


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
    return BullCowCount;
}

void FBullCowGame::reset(){
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "ocean";
    myCurrentTry = 1;
    myMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    return;
}


bool FBullCowGame::isGameWon() const{
    return false;
}

bool FBullCowGame::checkGuessValidity (FString) const{
    return false;
}