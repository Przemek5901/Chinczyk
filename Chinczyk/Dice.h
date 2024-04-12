#include<SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#pragma once
class Dice
{
public:
	void loadDice();
	int rollDice();
	void setTexture(int randomNumber);
	sf::Sprite dice;
	sf::Clock clock;
	~Dice();
private:
	sf::Texture dice1T;
	sf::Texture dice2T;
	sf::Texture dice3T;
	sf::Texture dice4T;
	sf::Texture dice5T;
	sf::Texture dice6T;
	sf::Texture diceStart;
};

