#include <string>


using FString = std::string;
using int32 = int;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus 
{
    Invalid,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase,
    Hint
};


class FBullCowGame
{
public:
    //constructor
    FBullCowGame();
    void resetAfterWin();  
    void resetAfterLose();
    int32 getMaxTries() const;
    int32 getCurrentTry() const;
    int32 GetHiddenWordLength() const;
    void setToPrevHiddenWord();
    bool isGameWon() const;
    char getFirstLetter() const;
    EWordStatus checkGuessValidity(FString) const;
    BullCowCount SubmitGuess(FString);

private:
    int32 myCurrentTry;
    int32 myMaxTries;
    FString MyHiddenWord;
    FString prevHiddenWord = "";
    FString words[10] = {"glow", "lamp", "blue", "ocean", "sin", "gin", "vodka", "goal", "fly", "god"};
    bool bGameIsWon;
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};