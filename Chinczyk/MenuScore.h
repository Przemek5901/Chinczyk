#include<iostream>
#include<map>
#include<iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include"cScreen.h"
#include"Textbox.h"
#include"MenuExit.h"

#pragma once

using namespace std;

class MenuScore: public cScreen
{
private:
	bool Running = true;
	sf::Sprite background;
	sf::Sprite loadFromLastLocS;
	sf::Sprite loadFromNewLocS;
	sf::Sprite exitButton;
	sf::Sprite menuButton;
	sf::Texture backgroundT;
	sf::Text score;
	sf::Text loadFromLastLoc;
	sf::Text loadFromNewLoc;
	sf::Text loadFromLastLocDesc;
	sf::Text loadFromNewLocDesc;
	sf::Text recDarkGreyDesc;
	sf::Text exitButtonDesc;
	sf::Text menuButtonDesc;
	sf::Text playersResults;
	sf::Text playersResultsInt;
	sf::RectangleShape rec1;
	sf::RectangleShape recWhite;
	sf::RectangleShape recDarkGrey;
	sf::RectangleShape rec1Grey;
	sf::RectangleShape rec2Grey;
	sf::RectangleShape rec3Grey;
	sf::RectangleShape rec4Grey;
	fs::path lastPath;
	fs::path newPath;
	void calls();
	void inputResults(std::filesystem::path& path);
public:
	~MenuScore();
	MenuScore(void);
	virtual int Run(sf::RenderWindow& App);
};
