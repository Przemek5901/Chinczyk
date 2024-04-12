#include "Dice.h"

void Dice::loadDice()
{
	dice1T.loadFromFile("images/dice1.png");
	dice2T.loadFromFile("images/dice2.png");
	dice3T.loadFromFile("images/dice3.png");
	dice4T.loadFromFile("images/dice4.png");
	dice5T.loadFromFile("images/dice5.png");
	dice6T.loadFromFile("images/dice6.png");
	diceStart.loadFromFile("images/diceStart.png");


	dice.setTexture(diceStart);


	dice.setPosition(863, 10);
}

int Dice::rollDice()
{
	srand(static_cast<unsigned int>(time(0)));
	return rand() % 6 + 1;
}

void Dice::setTexture(int randomNumber)
{
	randomNumber = rollDice();
	if (randomNumber == 1)
	{
		dice.setTexture(dice1T);
	}
	else if (randomNumber == 2)
	{
		dice.setTexture(dice2T);
	}
	else if (randomNumber == 3)
	{
		dice.setTexture(dice3T);
	}
	else if (randomNumber == 4)
	{
		dice.setTexture(dice4T);
	}
	else if (randomNumber == 5)
	{
		dice.setTexture(dice5T);
	}
	else if (randomNumber == 6)
	{
		dice.setTexture(dice6T);
	}


}

Dice::~Dice()
{
}
