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
	// standard input and return it as a vector of colors.
	std::vector<Color> GetGuess();
	
	// This will request a code from the user via. the 
	// standard input and return it as a vector of colors.
	std::vector<Color> GetSecretCode();

	// This will request a gamemode from the user via. the 
	//   standard input and return it as a Gamemode.
	Gamemode GetGamemode() const;

	void GameIsOver(bool solved, std::vector<Color> code);

private:
	bool validGuess(std::vector<char>& split);
	std::vector<char> splitInput(std::string& str, const std::string& delimiter);
	bool validChar(const char& color);

	// Helper function for GetGuess and GetSecretCode
	std::vector<Color> GetCode();
};
#endif USER_INPUT_