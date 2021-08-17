#include "game.h"

void Game::MakeGuess(const Code& guess)
{
    guess_history_.push_back(guess);

    int correct_place = code_.CountCorrectPlacement(guess);
    int correct_color = code_.CountCorrectColor(guess);

    console_->UpdateGuess(guess, guess_history_.size(), 
                          correct_place, correct_color);

    solved_ = (correct_place == 4);

    if (solved_ || AllGuessesUsed())
        console_->UpdateFinished(code_);
}

bool Game::IsSolved() const
{
    return solved_;
}

bool Game::AllGuessesUsed() const
{
    return (guess_history_.size() == max_number_of_guesses_);
}
