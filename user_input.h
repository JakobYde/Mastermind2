#ifndef USER_INPUT_
#define USER_INPUT_

#include <string>
#include <vector>
#include <conio.h>

#include "color.h"
#include "code.h"
#include "game.h"

class UserInput {
public:
	UserInput() {};
	~UserInput() {};

	// This will request a guess from the user via. the 
	// standard input and return it as a Code object.
	Code GetGuess();
	
	// This will request a code from the user via. the 
	// standard input and return it as a Code object.
	Code GetSecretCode();

	// This will request a gamemode from the user via. the 
	//   standard input and return it as a Gamemode.
	Gamemode GetGamemode() const;

	// This should be called when the game is over,
	// it asks the player to press Enter for a new game.
	void GameIsOver(bool solved, Code code);

private:
	bool ValidGuess(std::vector<char>& split);
	std::vector<char> SplitInput(std::string& str, const std::string& delimiter);
	bool ValidChar(const char& color);

	// Helper function for GetGuess and GetSecretCode
	Code GetCode();
};
#endif USER_INPUT_