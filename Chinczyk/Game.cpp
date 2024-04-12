#include "Game.h"



void Game::playersNicknames(Players& P)
{

	redNick.setFont(cScreen::getFont());
	redNick.setCharacterSize(55);
	redNick.setFillColor(sf::Color::Black);
	redNick.setOutlineThickness(2);
	redNick.setOutlineColor(sf::Color::Black);
	redNick.setString(P.Player1.first);
	sf::FloatRect boundsRed = redNick.getLocalBounds();
	boundsRed.width = boundsRed.width / 2;
	redNick.setPosition(363 - boundsRed.width, 300);

	blueNick.setFont(cScreen::getFont());
	blueNick.setCharacterSize(55);
	blueNick.setFillColor(sf::Color::Black);
	blueNick.setOutlineThickness(2);
	blueNick.setOutlineColor(sf::Color::Black);
	blueNick.setString(P.Player2.first);
	sf::FloatRect boundsBlue = blueNick.getLocalBounds();
	boundsBlue.width = boundsBlue.width / 2;
	blueNick.setPosition(833 - boundsBlue.width, 300);


	greenNick.setFont(cScreen::getFont());
	greenNick.setCharacterSize(55);
	greenNick.setFillColor(sf::Color::Black);
	greenNick.setOutlineThickness(2);
	greenNick.setOutlineColor(sf::Color::Black);
	greenNick.setString(P.Player3.first);
	sf::FloatRect boundsGreen = greenNick.getLocalBounds();
	boundsGreen.width = boundsGreen.width / 2;
	greenNick.setPosition(833 - boundsGreen.width, 650);


	yellowNick.setFont(cScreen::getFont());
	yellowNick.setCharacterSize(55);
	yellowNick.setFillColor(sf::Color::Black);
	yellowNick.setOutlineThickness(2);
	yellowNick.setOutlineColor(sf::Color::Black);
	yellowNick.setString(P.Player4.first);
	sf::FloatRect boundsYellow = yellowNick.getLocalBounds();
	boundsYellow.width = boundsYellow.width / 2;
	yellowNick.setPosition(363 - boundsYellow.width, 650);

	if (nicknamesFlag)
	{
		if (currentIndex == 0 && P.Player1.second == "red")
		{
			redNick.setFillColor(sf::Color::Red);
		}
		else if (currentIndex == 0 && P.Player2.second == "blue")
		{
			blueNick.setFillColor(sf::Color::Blue);
		}
		else if (currentIndex == 0 && P.Player3.second == "green")
		{
			greenNick.setFillColor(sf::Color::Green);
		}
		else if (currentIndex == 0 && P.Player4.second == "yellow")
		{
			yellowNick.setFillColor(sf::Color::Yellow);
		}
		nicknamesFlag = false;
	}

	if (redPlaying && playerPawnPairs[currentIndex][0].first.getFillColor() == sf::Color(82, 18, 29))
	{
		redNick.setFillColor(sf::Color::Red);
		blueNick.setFillColor(sf::Color::Black);
		greenNick.setFillColor(sf::Color::Black);
		yellowNick.setFillColor(sf::Color::Black);
	}
	if (bluePlaying && playerPawnPairs[currentIndex][0].first.getFillColor() == sf::Color(18, 57, 82))
	{
		redNick.setFillColor(sf::Color::Black);
		blueNick.setFillColor(sf::Color::Blue);
		greenNick.setFillColor(sf::Color::Black);
		yellowNick.setFillColor(sf::Color::Black);
	}
	if (greenPlaying && playerPawnPairs[currentIndex][0].first.getFillColor() == sf::Color(16, 51, 13))
	{
		redNick.setFillColor(sf::Color::Black);
		blueNick.setFillColor(sf::Color::Black);
		greenNick.setFillColor(sf::Color::Green);
		yellowNick.setFillColor(sf::Color::Black);
	}
	if (yellowPlaying && playerPawnPairs[currentIndex][0].first.getFillColor() == sf::Color(139, 139, 25))
	{
		redNick.setFillColor(sf::Color::Black);
		blueNick.setFillColor(sf::Color::Black);
		greenNick.setFillColor(sf::Color::Black);
		yellowNick.setFillColor(sf::Color::Yellow);
	}
}

void Game::playersStatus(Players& P)
{
	if (P.Player1.first == "" && P.Player1.second == "")
	{
		redPlaying = false;
	}
	else
	{
		redPlaying = true;
	}

	if (P.Player2.first == "" && P.Player2.second == "")
	{
		bluePlaying = false;
	}
	else
	{
		bluePlaying = true;
	}

	if (P.Player3.first == "" && P.Player3.second == "")
	{
		greenPlaying = false;
	}
	else
	{
		greenPlaying = true;
	}

	if (P.Player4.first == "" && P.Player4.second == "")
	{
		yellowPlaying = false;
	}
	else
	{
		yellowPlaying = true;
	}
}

void Game::activePlayers()
{
	extern Players P;
	playersStatus(P);
	vector<bool> temp =
	{ { redPlaying },
		{ bluePlaying },
		{ greenPlaying },
		{ yellowPlaying }
	};

	playerPawnPairs.push_back(redPawns);
	playerPawnPairs.push_back(bluePawns);
	playerPawnPairs.push_back(greenPawns);
	playerPawnPairs.push_back(yellowPawns);

	for (int i = 3; i >= 0; i--)
	{
		if (temp[i] == false)
		{
			playerPawnPairs.erase(playerPawnPairs.begin() + i);
		}
	}
}

void Game::metaEnter(int indexV1, int indexV2, bool& retflag)
{
	retflag = true;
	if (playerPawnPairs[indexV1][indexV2].first.getFillColor() == sf::Color(82, 18, 29))
	{
		if (playerPawnPairs[indexV1][indexV2].second == 44 && !areRedPawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(511, 487);
			areRedPawnsInMeta[0].first = true;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 43 && !areRedPawnsInMeta[1].first && areRedPawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(441, 487);
			areRedPawnsInMeta[1].first = true;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 42 && !areRedPawnsInMeta[2].first && areRedPawnsInMeta[0].first && areRedPawnsInMeta[1].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(371, 487);
			areRedPawnsInMeta[2].first = true;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 41 && !areRedPawnsInMeta[3].first && areRedPawnsInMeta[0].first && areRedPawnsInMeta[1].first && areRedPawnsInMeta[2].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(301, 487);
			areRedPawnsInMeta[3].first = true;
		}
	}
	if (playerPawnPairs[indexV1][indexV2].first.getFillColor() == sf::Color(18, 57, 82) && areBluePawnsInMeta[indexV2].second == true)
	{
		if (playerPawnPairs[indexV1][indexV2].second == 14 && !areBluePawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 417);
			areBluePawnsInMeta[0].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 13 && !areBluePawnsInMeta[1].first && areBluePawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 347);
			areBluePawnsInMeta[1].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 12 && !areBluePawnsInMeta[2].first && areBluePawnsInMeta[0].first && areBluePawnsInMeta[1].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 277);
			areBluePawnsInMeta[2].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 11 && !areBluePawnsInMeta[3].first && areBluePawnsInMeta[0].first && areBluePawnsInMeta[1].first && areBluePawnsInMeta[2].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 207);
			areBluePawnsInMeta[3].first = true;
			return;
		}
	}

	if (playerPawnPairs[indexV1][indexV2].first.getFillColor() == sf::Color(16, 51, 13) && areGreenPawnsInMeta[indexV2].second == true)
	{
		if (playerPawnPairs[indexV1][indexV2].second == 24 && !areGreenPawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(651, 487);
			areGreenPawnsInMeta[0].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 23 && !areGreenPawnsInMeta[1].first && areGreenPawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(721, 487);
			areGreenPawnsInMeta[1].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 22 && !areGreenPawnsInMeta[2].first && areGreenPawnsInMeta[0].first && areGreenPawnsInMeta[1].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(791, 487);
			areGreenPawnsInMeta[2].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 21 && !areGreenPawnsInMeta[3].first && areGreenPawnsInMeta[0].first && areGreenPawnsInMeta[1].first && areGreenPawnsInMeta[2].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(861, 487);
			areGreenPawnsInMeta[3].first = true;
			return;
		}
	}

	if (playerPawnPairs[indexV1][indexV2].first.getFillColor() == sf::Color(139, 139, 25) && areYellowPawnsInMeta[indexV2].second == true)
	{
		if (playerPawnPairs[indexV1][indexV2].second == 34 && !areYellowPawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 557);
			areYellowPawnsInMeta[0].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 33 && !areYellowPawnsInMeta[1].first && areYellowPawnsInMeta[0].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 627);
			areYellowPawnsInMeta[1].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 32 && !areYellowPawnsInMeta[2].first && areYellowPawnsInMeta[0].first && areYellowPawnsInMeta[1].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 697);
			areYellowPawnsInMeta[2].first = true;
			return;
		}
		else if (playerPawnPairs[indexV1][indexV2].second == 31 && !areYellowPawnsInMeta[3].first && areYellowPawnsInMeta[0].first && areYellowPawnsInMeta[1].first && areYellowPawnsInMeta[2].first)
		{
			playerPawnPairs[indexV1][indexV2].first.setPosition(581, 767);
			areYellowPawnsInMeta[3].first = true;
			return;
		}
	}
	retflag = false;
}

void Game::position(int indexV1, int indexV2, int randomNumber)
{
	bool retflag;
	metaEnter(indexV1, indexV2, retflag);
	if (retflag) return;

	if (playerPawnPairs[indexV1][indexV2].second == 1)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(231, 417);
	}
	if (playerPawnPairs[indexV1][indexV2].second == 2)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(301, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 3)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(371, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 4)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(441, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 5)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 6)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 347);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 7)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 277);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 8)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 207);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 9)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 137);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 10)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(581, 137);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 11)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 137);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 12)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 207);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 13)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 277);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 14)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 347);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 15)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 16)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(721, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 17)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(791, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 18)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(861, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 19)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(931, 417);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 20)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(931, 487);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 21)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(931, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 22)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(861, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 23)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(791, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 24)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(721, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 25)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 26)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 627);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 27)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 697);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 28)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 767);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 29)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(651, 837);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 30)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(581, 837);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 31)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 837);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 32)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 767);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 33)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 697);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 34)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 627);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 35)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(511, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 36)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(441, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 37)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(371, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 38)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(301, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 39)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(231, 557);
	}
	else if (playerPawnPairs[indexV1][indexV2].second == 40)
	{
		playerPawnPairs[indexV1][indexV2].first.setPosition(231, 487);
	}



}

Game::~Game()
{
}

void Game::pawnMove(sf::Event& event, int& pointer, int diceNumber)
{
	extern Players P;

	if (playerPawnPairs.size() != 0)
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (playerPawnPairs[currentIndex][0].first.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				pointer = 0;
				playersMovement(diceNumber, pointer);
				playersNicknames(P);
				diceFlag = true;

			}
			else if (playerPawnPairs[currentIndex][1].first.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				pointer = 1;
				playersMovement(diceNumber, pointer);
				playersNicknames(P);
				diceFlag = true;

			}
			else if (playerPawnPairs[currentIndex][2].first.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				pointer = 2;
				playersMovement(diceNumber, pointer);
				playersNicknames(P);
				diceFlag = true;
			}
			else if (playerPawnPairs[currentIndex][3].first.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				pointer = 3;
				playersMovement(diceNumber, pointer);
				playersNicknames(P);
				diceFlag = true;
			}
		}
	}

}

void Game::pawnsPosOnBoard(int pawnIndex, int randomNumber)
{
	int numtemp = 44;
	for (int i = 0; i < 4; i++)
	{
		if (areRedPawnsInMeta[i].first == true)
			numtemp--;
	}
	if ((playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(82, 18, 29) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 40) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(82, 18, 29) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber == numtemp))
	{
		playerPawnPairs[currentIndex][pawnIndex].second += randomNumber;
		position(currentIndex, pawnIndex, randomNumber);
	}


	int numtempBlue = 14;
	for (int i = 0; i < 4; i++)
	{
		if (areBluePawnsInMeta[i].first)
			numtempBlue--;
	}
	if (playerPawnPairs[currentIndex][pawnIndex].second + randomNumber > 40 && (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(18, 57, 82)))
	{
		playerPawnPairs[currentIndex][pawnIndex].second -= 40;
		areBluePawnsInMeta[pawnIndex].second = true;
	}
	if ((playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(18, 57, 82) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 40 && areBluePawnsInMeta[pawnIndex].second == false) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(18, 57, 82) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 10 && areBluePawnsInMeta[pawnIndex].second == true) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(18, 57, 82) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber == numtempBlue && areBluePawnsInMeta[pawnIndex].second == true))
	{
		playerPawnPairs[currentIndex][pawnIndex].second += randomNumber;
		position(currentIndex, pawnIndex, randomNumber);
	}

	int numtempGreen = 24;
	for (int i = 0; i < 4; i++)
	{
		if (areGreenPawnsInMeta[i].first)
			numtempGreen--;
	}
	if (playerPawnPairs[currentIndex][pawnIndex].second + randomNumber > 40 && (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(16, 51, 13)))
	{
		playerPawnPairs[currentIndex][pawnIndex].second -= 40;
		areGreenPawnsInMeta[pawnIndex].second = true;
	}
	if ((playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(16, 51, 13) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 40 && areGreenPawnsInMeta[pawnIndex].second == false) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(16, 51, 13) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 20 && areGreenPawnsInMeta[pawnIndex].second == true) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(16, 51, 13) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber == numtempGreen && areGreenPawnsInMeta[pawnIndex].second == true))
	{
		playerPawnPairs[currentIndex][pawnIndex].second += randomNumber;
		position(currentIndex, pawnIndex, 5);
	}

	int numtempYellow = 34;
	for (int i = 0; i < 4; i++)
	{
		if (areYellowPawnsInMeta[i].first)
			numtempYellow--;
	}
	if (playerPawnPairs[currentIndex][pawnIndex].second + randomNumber > 40 && (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(139, 139, 25)))
	{
		playerPawnPairs[currentIndex][pawnIndex].second -= 40;
		areYellowPawnsInMeta[pawnIndex].second = true;
	}
	if ((playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(139, 139, 25) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 40 && areYellowPawnsInMeta[pawnIndex].second == false) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(139, 139, 25) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber <= 30 && areYellowPawnsInMeta[pawnIndex].second == true) ||
		(playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(139, 139, 25) && playerPawnPairs[currentIndex][pawnIndex].second + randomNumber == numtempYellow && areYellowPawnsInMeta[pawnIndex].second == true))
	{
		playerPawnPairs[currentIndex][pawnIndex].second += randomNumber;
		position(currentIndex, pawnIndex, 5);
	}
}

void Game::killingPawns(int pawnIndex)
{
	sf::Vector2f pos = playerPawnPairs[currentIndex][pawnIndex].first.getPosition();
	if ((pos.x == 231 && pos.y == 417) ||
		(pos.x == 651 && pos.y == 137) ||
		(pos.x == 931 && pos.y == 557) ||
		(pos.x == 511 && pos.y == 837))
	{
		return;
	}
	for (int i = 0; i < playerPawnPairs.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (playerPawnPairs[currentIndex][pawnIndex].first.getPosition() == playerPawnPairs[i][j].first.getPosition() &&
				playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() != playerPawnPairs[i][j].first.getFillColor())
			{
				playerPawnPairs[i][j].second = 0;
				if (playerPawnPairs[i][j].first.getFillColor() == sf::Color(82, 18, 29))
				{
					if (j == 0)
					{
						playerPawnPairs[i][j].first.setPosition(231, 207);
					}
					else if (j == 1)
					{
						playerPawnPairs[i][j].first.setPosition(301, 207);
					}
					else if (j == 2)
					{
						playerPawnPairs[i][j].first.setPosition(231, 137);
					}
					else if (j == 3)
					{
						playerPawnPairs[i][j].first.setPosition(301, 137);
					}
				}
				else if (playerPawnPairs[i][j].first.getFillColor() == sf::Color(18, 57, 82))
				{

					if (j == 0)
					{
						playerPawnPairs[i][j].first.setPosition(861, 137);
						areBluePawnsInMeta[j].second = false;
					}
					else if (j == 1)
					{
						playerPawnPairs[i][j].first.setPosition(861, 207);
						areBluePawnsInMeta[j].second = false;
					}
					else if (j == 2)
					{
						playerPawnPairs[i][j].first.setPosition(931, 137);
						areBluePawnsInMeta[j].second = false;
					}
					else if (j == 3)
					{
						playerPawnPairs[i][j].first.setPosition(931, 207);
						areBluePawnsInMeta[j].second = false;
					}
				}
				else if (playerPawnPairs[i][j].first.getFillColor() == sf::Color(16, 51, 13))
				{
					
					if (j == 0)
					{
						playerPawnPairs[i][j].first.setPosition(931, 767);
						areGreenPawnsInMeta[j].second = false;
					}
					else if (j == 1)
					{
						playerPawnPairs[i][j].first.setPosition(861, 767);
						areGreenPawnsInMeta[j].second = false;
					}
					else if (j == 2)
					{
						playerPawnPairs[i][j].first.setPosition(931, 837);
						areGreenPawnsInMeta[j].second = false;
					}
					else if (j == 3)
					{
						playerPawnPairs[i][j].first.setPosition(931, 837);
						areGreenPawnsInMeta[j].second = false;
					}
				}
				else if (playerPawnPairs[i][j].first.getFillColor() == sf::Color(139, 139, 25))
				{
					areYellowPawnsInMeta[pawnIndex].second = false;
					if (j == 0)
					{
						playerPawnPairs[i][j].first.setPosition(301, 837);
						areYellowPawnsInMeta[j].second = false;
					}
					else if (j == 1)
					{
						playerPawnPairs[i][j].first.setPosition(301, 767);
						areYellowPawnsInMeta[j].second = false;
					}
					else if (j == 2)
					{
						playerPawnPairs[i][j].first.setPosition(231, 837);
						areYellowPawnsInMeta[j].second = false;
					}
					else if (j == 3)
					{
						playerPawnPairs[i][j].first.setPosition(231, 767);
						areYellowPawnsInMeta[j].second = false;
					}
				}
			}
		}

	}
}

void Game::playersMovement(int randomNumber, int pawnIndex)
{

	if (once)
	{
		activePlayers();
		once = false;
	}

	if (pawnIndex == -1)
	{
		return;
	}

	if (randomNumber == 6 && playerPawnPairs[currentIndex][pawnIndex].second == 0)
	{
		if (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(82, 18, 29))
		{
			playerPawnPairs[currentIndex][pawnIndex].first.setPosition(231, 417);
			playerPawnPairs[currentIndex][pawnIndex].second = 1;

		}
		else if (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(18, 57, 82))
		{
			playerPawnPairs[currentIndex][pawnIndex].first.setPosition(651, 137);
			playerPawnPairs[currentIndex][pawnIndex].second = 11;

		}
		else if (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(16, 51, 13))
		{
			playerPawnPairs[currentIndex][pawnIndex].first.setPosition(931, 557);
			playerPawnPairs[currentIndex][pawnIndex].second = 21;

		}
		else if (playerPawnPairs[currentIndex][pawnIndex].first.getFillColor() == sf::Color(139, 139, 25))
		{
			playerPawnPairs[currentIndex][pawnIndex].first.setPosition(511, 837);
			playerPawnPairs[currentIndex][pawnIndex].second = 31;

		}
	}
	else if (playerPawnPairs[currentIndex][pawnIndex].second != 0)
	{
		pawnsPosOnBoard(pawnIndex, randomNumber);
		killingPawns(pawnIndex);

		if (randomNumber == 6)
			return;
	}



	currentIndex = (currentIndex + 1) % playerPawnPairs.size();

}

