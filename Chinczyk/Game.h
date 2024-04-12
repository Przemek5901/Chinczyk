#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"cScreen.h"
#include"Dice.h"
#include"Players.h"
#include<sstream>
#include<iostream>
#include<utility>
#include<vector>
#include<iomanip>
#pragma once

using namespace std;



class Game 
{
public:
	bool redPlaying;
	bool bluePlaying;
	bool greenPlaying;
	bool yellowPlaying;
	bool diceFlag = true;
	vector<pair<sf::CircleShape, int>> redPawns;
	vector<pair<sf::CircleShape, int>> bluePawns;
	vector<pair<sf::CircleShape, int>> greenPawns;
	vector<pair<sf::CircleShape, int>> yellowPawns;
	vector<vector<pair<sf::CircleShape, int>>> playerPawnPairs;
	vector<pair<bool, bool>> areRedPawnsInMeta =
	{   {false, false},
		{false, false},
		{false, false},
		{false, false}
	};
	vector<pair<bool,bool>> areBluePawnsInMeta =
	{ {false, false},
		{false, false},
		{false, false},
		{false, false}
	};
	vector<pair<bool, bool>> areGreenPawnsInMeta =
	{ {false, false},
		{false, false},
		{false, false},
		{false, false}
	};
	vector<pair<bool, bool>> areYellowPawnsInMeta =
	{ {false, false},
		{false, false},
		{false, false},
		{false, false}
	};
	sf::Text redNick;
	sf::Text blueNick;
	sf::Text greenNick;
	sf::Text yellowNick;
	void playersNicknames(Players& P);
	void pawnMove(sf::Event& event, int& pointer, int diceNumber);
	void playersMovement(int randomNumber, int pawnIndex);
	~Game();
private:
	bool soundFlag = true;

	bool nicknamesFlag = true;
	bool once = true;
	void playersStatus(Players& P);
	void pawnsPosOnBoard(int pawnIndex, int randomNumber);
	void killingPawns(int pawnIndex);
	void activePlayers();
	void metaEnter(int indexV1, int indexV2, bool& retflag);
	void position(int indexV1, int indexV2, int  randomNumber);
	int currentIndex = 0;

};

Game G;

