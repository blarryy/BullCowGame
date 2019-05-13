#include <string>


using FString = std::string;
using int32 = int;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame
{
public:
    //constructor
    FBullCowGame();
    void reset();  
    int32 getMaxTries() const;
    int32 getCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool isGameWon() const;
    bool checkGuessValidity(FString) const;
    BullCowCount SubmitGuess(FString);

private:
    int32 myCurrentTry;
    int32 myMaxTries;
    FString MyHiddenWord;
};