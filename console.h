#ifndef CONSOLE_
#define CONSOLE_

#include <iostream>
#include <vector>
#include <string>

#include "code.h"

class Console {
public:
	Console() {};

	// Make the class non-copyable and non-movable as it is not needed and
	// might be used erroneously.
	Console(const Console&) = delete;
	Console& operator=(const Console&) = delete;

	// This will request a guess from the user in the standard 
	//   input and return it as a Code object.
	void UpdateGuess(const Code & guess, int number_of_guess, int correct_placement, int correct_color);

	void UpdateFinished(const Code& code);

	void Print() const;

private:
	// This is not pretty, but generating it isn't either. This does, however,
	// require a maximum of 10 allowed guesses.
	std::vector<std::string> board_ = 
		{ "          --------------------- ",
		  "Answer:   |   H   H   H   H   | ",
	   	  "          --------------------- ",
		  "Guess 10: |   X   X   X   X   | ",
		  "Guess 9:  |   X   X   X   X   | ",
		  "Guess 8:  |   X   X   X   X   | ",
		  "Guess 7:  |   X   X   X   X   | ",
		  "Guess 6:  |   X   X   X   X   | ",
		  "Guess 5:  |   X   X   X   X   | ",
		  "Guess 4:  |   X   X   X   X   | ",
		  "Guess 3:  |   X   X   X   X   | ",
		  "Guess 2:  |   X   X   X   X   | ",
		  "Guess 1:  |   X   X   X   X   | ",
		  "          --------------------- "}; 
};
#endif CONSOLE_