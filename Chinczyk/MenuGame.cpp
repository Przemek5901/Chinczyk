#include "MenuGame.h"


void MenuGame::callsGame()
{
	gameMapT.loadFromFile("images/mapagame.png");
	gameMap.setTexture(gameMapT);

	circleRed1.setRadius(21);
	circleRed1.setFillColor(sf::Color(82, 18, 29));
	circleRed1.setOutlineThickness(3);
	circleRed1.setOutlineColor(sf::Color::Black);
	circleRed1.setPosition(231, 207);

	circleRed2.setRadius(21);
	circleRed2.setFillColor(sf::Color(82, 18, 29));
	circleRed2.setOutlineThickness(3);
	circleRed2.setOutlineColor(sf::Color::Black);
	circleRed2.setPosition(301, 207);

	circleRed3.setRadius(21);
	circleRed3.setFillColor(sf::Color(82, 18, 29));
	circleRed3.setOutlineThickness(3);
	circleRed3.setOutlineColor(sf::Color::Black);
	circleRed3.setPosition(231, 137);

	circleRed4.setRadius(21);
	circleRed4.setFillColor(sf::Color(82, 18, 29));
	circleRed4.setOutlineThickness(3);
	circleRed4.setOutlineColor(sf::Color::Black);
	circleRed4.setPosition(301, 137);

	circleBlue1.setRadius(21);
	circleBlue1.setFillColor(sf::Color(18, 57, 82));
	circleBlue1.setOutlineThickness(3);
	circleBlue1.setOutlineColor(sf::Color::Black);
	circleBlue1.setPosition(861, 137);

	circleBlue2.setRadius(21);
	circleBlue2.setFillColor(sf::Color(18, 57, 82));
	circleBlue2.setOutlineThickness(3);
	circleBlue2.setOutlineColor(sf::Color::Black);
	circleBlue2.setPosition(861, 207);

	circleBlue3.setRadius(21);
	circleBlue3.setFillColor(sf::Color(18, 57, 82));
	circleBlue3.setOutlineThickness(3);
	circleBlue3.setOutlineColor(sf::Color::Black);
	circleBlue3.setPosition(931, 137);

	circleBlue4.setRadius(21);
	circleBlue4.setFillColor(sf::Color(18, 57, 82));
	circleBlue4.setOutlineThickness(3);
	circleBlue4.setOutlineColor(sf::Color::Black);
	circleBlue4.setPosition(931, 207);

	circleGreen1.setRadius(21);
	circleGreen1.setFillColor(sf::Color(16, 51, 13));
	circleGreen1.setOutlineThickness(3);
	circleGreen1.setOutlineColor(sf::Color::Black);
	circleGreen1.setPosition(931, 767);

	circleGreen2.setRadius(21);
	circleGreen2.setFillColor(sf::Color(16, 51, 13));
	circleGreen2.setOutlineThickness(3);
	circleGreen2.setOutlineColor(sf::Color::Black);
	circleGreen2.setPosition(861, 767);

	circleGreen3.setRadius(21);
	circleGreen3.setFillColor(sf::Color(16, 51, 13));
	circleGreen3.setOutlineThickness(3);
	circleGreen3.setOutlineColor(sf::Color::Black);
	circleGreen3.setPosition(931, 837);

	circleGreen4.setRadius(21);
	circleGreen4.setFillColor(sf::Color(16, 51, 13));
	circleGreen4.setOutlineThickness(3);
	circleGreen4.setOutlineColor(sf::Color::Black);
	circleGreen4.setPosition(861, 837);

	circleYellow1.setRadius(21);
	circleYellow1.setFillColor(sf::Color(139, 139, 25)); 
	circleYellow1.setOutlineThickness(3);
	circleYellow1.setOutlineColor(sf::Color::Black);
	circleYellow1.setPosition(301, 837);

	circleYellow2.setRadius(21);
	circleYellow2.setFillColor(sf::Color(139, 139, 25)); 
	circleYellow2.setOutlineThickness(3);
	circleYellow2.setOutlineColor(sf::Color::Black);
	circleYellow2.setPosition(301, 767);

	circleYellow3.setRadius(21);
	circleYellow3.setFillColor(sf::Color(139, 139, 25)); 
	circleYellow3.setOutlineThickness(3);
	circleYellow3.setOutlineColor(sf::Color::Black);
	circleYellow3.setPosition(231, 837);

	circleYellow4.setRadius(21);
	circleYellow4.setFillColor(sf::Color(139, 139, 25)); 
	circleYellow4.setOutlineThickness(3);
	circleYellow4.setOutlineColor(sf::Color::Black);
	circleYellow4.setPosition(231, 767);
}


MenuGame::~MenuGame()
{
}

MenuGame::MenuGame()
{
};



bool MenuGame::endGame(Game* G)
{
	MG.winnerNumber = 0;
	vector<vector<pair<bool, bool>>> vectors = { G->areRedPawnsInMeta,G->areBluePawnsInMeta,G->areGreenPawnsInMeta, G->areYellowPawnsInMeta };
	for (const auto vec : vectors)
	{
		bool allTrue = true;
		for (const auto value : vec)
		{
			if (!value.first)
			{
				allTrue = false;
				MG.winnerNumber++;
				break;
			}
		}
		if (allTrue)
		{
			return true;
		}
	}
	return false;
}
void MenuGame::timer(bool isTiming, sf::Clock& clock)
{
	timerText.setFont(cScreen::getFont());
	timerText.setCharacterSize(55);
	timerText.setFillColor(sf::Color::Black);
	timerText.setPosition(170, 30);
	diceInfo.setFont(cScreen::getFont());
	diceInfo.setCharacterSize(55);
	diceInfo.setFillColor(sf::Color::Black);
	diceInfo.setPosition(570, 30);
	diceInfo.setString("Rzuc kostka:");
	sf::Time elapsedTime;
	if (isTiming)
	{
		elapsedTime = clock.getElapsedTime();
	}

	int minutes = elapsedTime.asSeconds() / 60;
	int seconds = (int)(elapsedTime.asSeconds()) % 60;
	stringstream ss;
	ss << setfill('0') << setw(2) << minutes << ":" << setw(2) << seconds;
	string timeString = ss.str();
	timerText.setString("Czas gry: " + timeString);
}
int MenuGame::Run(sf::RenderWindow& App)
{
	callsGame();
	Game* G = new Game;
	Dice* D = new Dice;
	D->loadDice();

	G->redPawns =
	{
	{ circleRed1 , 0 },
	{ circleRed2 , 0 },
	{ circleRed3 , 0 },
	{ circleRed4 , 0 }
	};


	G->bluePawns =
	{
	{ circleBlue1 , 0 },
	{ circleBlue2 , 0 },
	{ circleBlue3 , 0 },
	{ circleBlue4 , 0 }
	};


	G->greenPawns =
	{
	{ circleGreen1 , 0 },
	{ circleGreen2 , 0 },
	{ circleGreen3 , 0 },
	{ circleGreen4 , 0 }
	};


	G->yellowPawns =
	{
	{ circleYellow1 , 0 },
	{ circleYellow2 , 0 },
	{ circleYellow3 , 0 },
	{ circleYellow4 , 0 }
	};


	extern Players P;
	int pointer = -1;
	int diceNumber = 1;
	bool isTiming = false;
	bool Running = true;

	while (Running)
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{

				if (D->dice.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					//if (G->diceFlag)
					{
						diceNumber = D->rollDice();
						D->setTexture(diceNumber);
						G->diceFlag = false;
					}
					G->playersMovement(diceNumber, -1);
					if (!isTiming)
					{
						D->clock.restart();
						isTiming = true;
					}

				}
				G->pawnMove(event, pointer, diceNumber);

			}
			if (endGame(G))
			{
				delete D;
				delete G;
				return 3;
			}
		}

		if (nickFlag)
		{
			G->playersNicknames(P);
			nickFlag = false;
		}
		timer(isTiming, D->clock);

		App.clear();
		App.draw(gameMap);
		App.draw(D->dice);
		App.draw(timerText);
		App.draw(diceInfo);

		for (const auto& Players : G->playerPawnPairs)
		{
			for (const auto& Pawns : Players)
			{
				App.draw(Pawns.first);

			}
		}

		App.draw(G->redNick);
		App.draw(G->blueNick);
		App.draw(G->greenNick);
		App.draw(G->yellowNick);
		App.display();

	}

	return -1;
}

