#include "FBullCowGame.h"


using int32 = int;
//convention: put getters at the top
//const behind a member/class function decleration means 
// this function can't change any variables inside the class
int32 FBullCowGame::getMaxTries() const{return myMaxTries;}
int32 FBullCowGame::getCurrentTry() const {return myCurrentTry;}

FBullCowGame::FBullCowGame(){
     reset();
}

void FBullCowGame::reset(){
    constexpr int32 MAX_TRIES = 8;
    myCurrentTry = 1;
    myMaxTries = MAX_TRIES;
    return;
}


bool FBullCowGame::isGameWon() const{
    return false;
}

bool FBullCowGame::checkGuessValidity(FString){
    return false;
}