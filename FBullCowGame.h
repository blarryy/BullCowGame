#include <string>

class FBullCowGame{
public:
    //constructor
    FBullCowGame();
    void reset(); // TODO make a richer return value
    int getMaxTries() const;
    int getCurrentTry() const;
    bool isGameWon() const;
    bool checkGuessValidity(std::string);
    //provide a method for counting bulls & cows, and
    //increase turn num

private:
    int myCurrentTry;
    int myMaxTries;
};