#include"cScreen.h"
#include<iostream>
#pragma once


class MenuStart : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
	bool Running = true;
	int alpha = 0;
	int menu = 0;
	sf::Texture backgroundT;
	sf::Sprite background;
	sf::Event Event;
	sf::Text Main;
	sf::Text buttonPlayDescrib;
	sf::Text buttonScoreDescrib;
	sf::Text buttonExitDescrib;
	sf::Sprite buttonPlay;
	sf::Sprite buttonScore;
	sf::Sprite buttonExit;
	void calls();
	sf::Image icon;
public:
	~MenuStart();
	virtual int Run(sf::RenderWindow& App);
};

