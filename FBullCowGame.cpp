#include "FBullCowGame.h"

//convention: put getters at the top
//const behind a member/class function decleration means 
// this function can't change any variables inside the class
int FBullCowGame::getMaxTries() const{return myMaxTries;}
int FBullCowGame::getCurrentTry() const {return myCurrentTry;}

FBullCowGame::FBullCowGame(){
     reset();
}

void FBullCowGame::reset(){
    constexpr MAX_TRIES = 8;
    myCurrentTry = 1;
    myMaxTries = MAX_TRIES;
    return;
}


bool FBullCowGame::isGameWon() const{
    return false;
}

bool FBullCowGame::checkGuessValidity(std::string s){
    return false;
}