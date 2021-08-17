#include "user_input.h"

std::vector<Color> UserInput::GetGuess()
{
	std::cout << "Please enter your guess (use space as separator): ";
	return GetCode();
}

std::vector<Color> UserInput::GetSecretCode()
{
	std::cout << "Player 1 please enter the code (use space as separator): ";
	return GetCode();
}

std::vector<Color> UserInput::GetCode()
{
	std::string input;

	getline(std::cin, input);

	std::vector<char> split = splitInput(input, " ");

	// Validate input
	while (!validGuess(split)) {
		std::cout << "Invalid input, please try again: ";
		getline(std::cin, input);
		split = splitInput(input, " ");
	}

	std::vector<Color> colors;
	for (char c : split)
		colors.push_back(static_cast<Color>(
			std::distance(kColors.begin(), 
				find(kColors.begin(), kColors.end(), c))));
	
	return colors;
}

Gamemode UserInput::GetGamemode() const
{
	std::cout << "Please press 'S' for single player or 'M' for multiplayer" << std::endl;
	char mode;
	while ((mode = tolower(_getch())) != 's' and mode != 'm'); // Waiting for input
	return static_cast<Gamemode>(mode);
}

void UserInput::GameIsOver(bool solved, std::vector<Color> code)
{
	if (solved)
		std::cout << "You have guessed the code, congratulations! The code was: ";
	else
		std::cout << "You have run out of attempts, the code was: ";

	for (Color c : code) std::cout << kColors[static_cast<int>(c)] << " ";

	std::cout << std::endl << "Press Enter to play again...";

	// Wait for Enter
	while (!(_getch() == 13));
	system("CLS"); // Clear console
}

bool UserInput::validGuess(std::vector<char> & split)
{
	if (split.size() != 4) // Check number of input colors
		return false;

	for (char s : split) {
		if (!validChar(s))
			return false;
	}
	return true;
}

std::vector<char> UserInput::splitInput(std::string & str, const std::string & delimiter)
{
	size_t idx;
	std::vector<char> vec;

	// Convert string to lowercase
	for (char& c : str)
		c = tolower(c);

	// Split string into vector according to the delimiter.
	while ((idx = str.find(delimiter)) != str.npos) {
		if (idx > 0)
			vec.push_back(str[idx - 1]);
		str.erase(0, idx + delimiter.size());
	}
	vec.push_back(str[0]);

	return vec;
}

bool UserInput::validChar(const char & color)
{
	if (std::count(kColors.begin(), kColors.end(), color))
		return true;
	else
		return false;
}
