#include<vector>
#include<utility>
#include"cScreen.h"
#include"MenuGameSel.h"
#include"Game.h"
#include"Dice.h"
#pragma once

using namespace std;

class MenuGame : public cScreen
{
private:
	sf::Texture gameMapT;
	sf::Sprite gameMap;
	sf::Text timerText;
	sf::Text diceInfo;
	void callsGame();
	void timer(bool isTiming, sf::Clock& clock);
	bool endGame(Game* G);
	bool nickFlag = true;
	bool timerFlag = true;
	sf::CircleShape circleRed1;
	sf::CircleShape circleRed2;
	sf::CircleShape circleRed3;
	sf::CircleShape circleRed4;
	sf::CircleShape circleBlue1;
	sf::CircleShape circleBlue2;
	sf::CircleShape circleBlue3;
	sf::CircleShape circleBlue4;
	sf::CircleShape circleGreen1;
	sf::CircleShape circleGreen2;
	sf::CircleShape circleGreen3;
	sf::CircleShape circleGreen4;
	sf::CircleShape circleYellow1;
	sf::CircleShape circleYellow2;
	sf::CircleShape circleYellow3;
	sf::CircleShape circleYellow4;
public:
	MenuGame(void);
	~MenuGame();
	virtual int Run(sf::RenderWindow& App);
	int winnerNumber;
};

MenuGame MG;

