#include <string>


using FString = std::string;
using int32 = int;
class FBullCowGame{
public:
    //constructor
    FBullCowGame();
    void reset(); // TODO make a richer return value
    int32 getMaxTries() const;
    int32 getCurrentTry() const;
    bool isGameWon() const;
    bool checkGuessValidity(FString);
    //provide a method for counting bulls & cows, and
    //increase turn num

private:
    int32 myCurrentTry;
    int32 myMaxTries;
};