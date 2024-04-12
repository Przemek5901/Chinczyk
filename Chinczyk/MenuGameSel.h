#include"cScreen.h"
#include"Textbox.h"
#include"Players.h"
#include"Game.h"
#include<sstream>
#include<iostream>
#include<utility>
#include<regex>
#pragma once

using namespace std;

regex rgx("^[A-Z](?=.*[0-9])[A-Za-z0-9]{0,7}$");


class MenuGameSel : public cScreen
{
private:
	sf::Texture playersChosing;
	sf::Sprite SplayersChosing;
	sf::Event Event;
	sf::Text text;
	sf::Text error;
	sf::Sprite buttonPlay;
	sf::Texture checkedT;
	sf::Texture checkedTBlack;
	sf::Sprite checkedRed;
	sf::Sprite checkedBlue;
	sf::Sprite checkedGreen;
	sf::Sprite checkedYellow;
	sf::Text redPlayer;
	sf::Text bluePlayer;
	sf::Text greenPlayer;
	sf::Text yellowPlayer;
	sf::Text Play;
	sf::Text Info;
	sf::RectangleShape rec1;
	sf::RectangleShape rec2;
	sf::RectangleShape rec3;
	sf::RectangleShape rec4;
	void callsScore();
public:
	~MenuGameSel();
	MenuGameSel(void);

	virtual int Run(sf::RenderWindow& App);
};

