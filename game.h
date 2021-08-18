#ifndef GAME_
#define GAME_

#include <vector>

#include "code.h"
#include "console.h"

enum class Gamemode { kSingleplayer = 's', kMultiplayer = 'm'};

class Game {
public:
	// Make the class non-copyable and non-movable as it is not needed and
	// might be used erroneously.
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	Game(const Code& code, const int& number_of_guesses, 
		const std::shared_ptr<Console> console) :
		code_(code), max_number_of_guesses_(number_of_guesses),
		console_(console) {};
	~Game() {};

	// Updates game logic
	void MakeGuess(const Code& guess);

	// Returns True if the code is guessed.
	bool IsSolved() const;

	// Returns true if all attempts	have been used.
	bool AllGuessesUsed() const;

private:
	const std::shared_ptr<Console> console_;
	const Code code_;
	int max_number_of_guesses_;
	bool solved_ = false;
	std::vector<Code> guess_history_;
};
#endif GAME_