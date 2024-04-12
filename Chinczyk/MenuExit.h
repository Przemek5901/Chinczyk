#include<vector>
#include<utility>
#include<filesystem>
#include"cScreen.h"
#include"MenuGameSel.h"
#include"Game.h"
#include"MenuGame.h"
#include"Dice.h"
#include"Players.h"
#include"Textbox.h"
#include<fstream>
#include<sstream>
#pragma once

using namespace std;
namespace fs = filesystem;

class MenuExit:public cScreen
{
private:
	bool Running = true;
	sf::Texture backgroundT;
	sf::Sprite background;
	sf::Text endInfo;
	sf::Text winnerInfo;
	sf::Text winnerInfoNick;
	sf::Text saveInfo;
	sf::Text lastSaveInfo;
	sf::RectangleShape rec1;
	sf::Sprite buttonSavePath;
	sf::Sprite buttonLastPath;
	sf::Sprite buttonExit;
	sf::Sprite buttonMenu;
	sf::Text buttonSavePathInfo;
	sf::Text buttonLastPathInfo;
	sf::Text buttonExitInfo;
	sf::Text buttonMenuInfo;
	string winnerNickname(Players& P, MenuGame& MG, sf::Text& text);
	void saveToFile(std::filesystem::path& toSave);
	void calls();
	void setLastPath(std::filesystem::path& path);
	string removeQuotes(const string& word);
	fs::path toSave;
	fs::path lastPath;
public:
	string getLastPath();
	MenuExit(void);
	~MenuExit();
	virtual int Run(sf::RenderWindow& App);
};

