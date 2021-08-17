#include "code.h"
#include "console.h"
#include "game.h"
#include "user_input.h"
#include "color.h"

int main () 
{
	const int available_attempts = 10;

	while (true)
	{
		std::shared_ptr<Console> console = std::make_shared<Console>();
		UserInput ui;
		Gamemode gm = ui.GetGamemode();

		Code secret_code = Code::GenerateCode();

		if (gm == Gamemode::kMultiplayer)
			secret_code = ui.GetSecretCode();

		Game game(secret_code, available_attempts, console);

		console->Print();

		Code guess;
		while (!game.IsSolved() && !game.AllGuessesUsed())
		{
			guess = ui.GetGuess();

			game.MakeGuess(Code(guess));

			console->Print();
		}

		ui.GameIsOver(game.IsSolved(), secret_code);
	}

	return 0;
}