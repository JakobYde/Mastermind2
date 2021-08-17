#include "code.h"
#include "console.h"
#include "game.h"
#include "user_input.h"
#include "color.h"

int main () 
{
	while (true)
	{
		std::shared_ptr<Console> console = std::make_shared<Console>();
		UserInput ui;
		std::vector<Color> secret_code;

		Gamemode gm = ui.GetGamemode();

		if (gm == Gamemode::kSingleplayer)
			secret_code = Code::GenerateCode();
		else if (gm == Gamemode::kMultiplayer)
			secret_code = ui.GetSecretCode();

		Game game(Code(secret_code), 10, console);

		console->Print();

		std::vector<Color> guess;
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