#include "console.h"

void Console::UpdateGuess(const Code & guess, int number_of_guess, int correct_placement, int correct_color)
{
	std::string & row = board_[14 - number_of_guess - 1];

	for (Color c : guess.code()) {
		size_t idx = row.find('X');
		row[idx] = toupper(kColors[static_cast<int>(c)]);
	}

	for (size_t i = 0; i < correct_placement; i++) 
		row += 'R';
	for (size_t i = 0; i < correct_color; i++) 
		row += 'W';
	for (size_t i = 0; i < 4 - correct_placement - correct_color; i++)
		row += '-';
}

void Console::UpdateFinished(const Code& code)
{
	std::string & row = board_[1];
	for (Color c : code.code()) {
		size_t idx = row.find('H');
		row[idx] = toupper(kColors[static_cast<int>(c)]);
	}
}

void Console::Print() const
{
	system("CLS");
	std::cout << "Available colors are red, green, blue, yellow, purple, orange, cyan, white" << std::endl;
	std::cout << "Input should be given using the first letter of the color - Example: [r b g r] (without brackets)" << std::endl;

	for (std::string line : board_) {
		std::cout << line << std::endl;
	}
}