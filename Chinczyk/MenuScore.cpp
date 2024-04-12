#include "MenuScore.h"


MenuScore::~MenuScore()
{
}

MenuScore::MenuScore()
{

}

void MenuScore::calls()
{
	backgroundT.loadFromFile("images/mapasel.png");
	background.setTexture(backgroundT);

	score.setFont(cScreen::getFont());
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(90);
	score.setString("WYNIKI");
	score.setStyle(sf::Text::Bold);
	sf::FloatRect boundsScore = score.getLocalBounds();
	boundsScore.width = boundsScore.width / 2;
	score.setPosition(600 - boundsScore.width, 5);

	loadFromNewLoc.setFont(cScreen::getFont());
	loadFromNewLoc.setFillColor(sf::Color::Black);
	loadFromNewLoc.setCharacterSize(45);
	loadFromNewLoc.setString("Zaladuj z nowej lokalizacji ");
	loadFromNewLoc.setStyle(sf::Text::Bold);
	sf::FloatRect boundsloadFromNewLoc = loadFromNewLoc.getLocalBounds();
	boundsloadFromNewLoc.width = boundsloadFromNewLoc.width / 2;
	loadFromNewLoc.setPosition(600 - boundsloadFromNewLoc.width, 110);

	rec1.setSize(sf::Vector2f(550, 50));
	rec1.setFillColor(sf::Color::White);
	rec1.setPosition(250, 185);
	rec1.setOutlineColor(sf::Color::Black);
	rec1.setOutlineThickness(1.0f);

	loadFromNewLocS.setTexture(cScreen::getButtonS());
	loadFromNewLocS.setPosition(815, 177);

	loadFromLastLoc.setFont(cScreen::getFont());
	loadFromLastLoc.setFillColor(sf::Color::Black);
	loadFromLastLoc.setCharacterSize(45);
	loadFromLastLoc.setString("Zaladuj z ostatniej lokalizacji ");
	loadFromLastLoc.setStyle(sf::Text::Bold);
	loadFromLastLoc.setPosition(243, 270);

	loadFromLastLocS.setTexture(cScreen::getButtonS());
	loadFromLastLocS.setPosition(815, 270);

	loadFromNewLocDesc.setFont(cScreen::getFont());
	loadFromNewLocDesc.setFillColor(sf::Color::White);
	loadFromNewLocDesc.setCharacterSize(28);
	loadFromNewLocDesc.setString("ZALADUJ");
	loadFromNewLocDesc.setStyle(sf::Text::Bold);
	loadFromNewLocDesc.setPosition(822, 183);

	loadFromLastLocDesc.setFont(cScreen::getFont());
	loadFromLastLocDesc.setFillColor(sf::Color::White);
	loadFromLastLocDesc.setCharacterSize(28);
	loadFromLastLocDesc.setString("ZALADUJ");
	loadFromLastLocDesc.setStyle(sf::Text::Bold);
	loadFromLastLocDesc.setPosition(822, 276);


	recWhite.setSize(sf::Vector2f(700, 450));
	recWhite.setFillColor(sf::Color::White);
	recWhite.setPosition(250, 350);
	recWhite.setOutlineColor(sf::Color::Black);
	recWhite.setOutlineThickness(2.0f);

	recDarkGrey.setSize(sf::Vector2f(700, 50));
	recDarkGrey.setFillColor(sf::Color(64, 64, 64));
	recDarkGrey.setPosition(250, 350);
	recDarkGrey.setOutlineColor(sf::Color::Black);
	recDarkGrey.setOutlineThickness(2.0f);

	recDarkGreyDesc.setFont(cScreen::getFont());
	recDarkGreyDesc.setFillColor(sf::Color::White);
	recDarkGreyDesc.setCharacterSize(38);
	recDarkGreyDesc.setString("LP.	Nazwa Gracza	Ilosc zwyciestw");
	recDarkGreyDesc.setStyle(sf::Text::Bold);
	recDarkGreyDesc.setPosition(270, 350);

	rec1Grey.setSize(sf::Vector2f(700, 50));
	rec1Grey.setFillColor(sf::Color(192, 192, 192));
	rec1Grey.setPosition(250, 450);
	rec1Grey.setOutlineColor(sf::Color::Black);
	rec1Grey.setOutlineThickness(1.0f);

	rec2Grey.setSize(sf::Vector2f(700, 50));
	rec2Grey.setFillColor(sf::Color(192, 192, 192));
	rec2Grey.setPosition(250, 550);
	rec2Grey.setOutlineColor(sf::Color::Black);
	rec2Grey.setOutlineThickness(1.0f);

	rec3Grey.setSize(sf::Vector2f(700, 50));
	rec3Grey.setFillColor(sf::Color(192, 192, 192));
	rec3Grey.setPosition(250, 650);
	rec3Grey.setOutlineColor(sf::Color::Black);
	rec3Grey.setOutlineThickness(1.0f);

	rec4Grey.setSize(sf::Vector2f(700, 50));
	rec4Grey.setFillColor(sf::Color(192, 192, 192));
	rec4Grey.setPosition(250, 750);
	rec4Grey.setOutlineColor(sf::Color::Black);
	rec4Grey.setOutlineThickness(1.0f);

	menuButton.setTexture(cScreen::getButtonS());
	menuButton.setPosition(429, 820);

	exitButton.setTexture(cScreen::getButtonS());
	exitButton.setPosition(635, 820);

	menuButtonDesc.setFont(cScreen::getFont());
	menuButtonDesc.setFillColor(sf::Color::White);
	menuButtonDesc.setCharacterSize(26);
	menuButtonDesc.setString("    MENU \n GLOWNE");
	menuButtonDesc.setStyle(sf::Text::Bold);
	menuButtonDesc.setPosition(430, 815);
	menuButtonDesc.setLineSpacing(0.8);

	exitButtonDesc.setFont(cScreen::getFont());
	exitButtonDesc.setFillColor(sf::Color::White);
	exitButtonDesc.setCharacterSize(32);
	exitButtonDesc.setString("WYJSCIE");
	exitButtonDesc.setStyle(sf::Text::Bold);
	exitButtonDesc.setPosition(640, 825);

	playersResults.setFont(cScreen::getFont());
	playersResults.setFillColor(sf::Color::Transparent);
	playersResults.setCharacterSize(32);
	playersResults.setStyle(sf::Text::Bold);
	playersResults.setPosition(270, 405);
	playersResults.setLineSpacing(1.43);

	playersResultsInt.setFont(cScreen::getFont());
	playersResultsInt.setFillColor(sf::Color::Transparent);
	playersResultsInt.setCharacterSize(32);
	playersResultsInt.setStyle(sf::Text::Bold);
	playersResultsInt.setPosition(770, 405);
	playersResultsInt.setLineSpacing(1.43);

}

void MenuScore::inputResults(std::filesystem::path& path)
{
	ifstream input(path / "wyniki.txt");
	string nick;
	int points;
	vector<pair<string, string>> results;
	int i = 0;
	while (input >> nick >> points)
	{
		results.resize(i+1);
		string pointsS = to_string(points);
		results[i].first = nick;
		results[i].second = pointsS;
		i++;
	}
	input.close();

	sort(results.begin(), results.end(), [](const pair<string, string>& a, const pair<string, string>& b)
	{
		return stoi(a.second) > stoi(b.second);
	});

	string playerNicknames, playerPoints;
	
	for (i = 0; i < results.size(); ++i)
	{
		playerNicknames += " " + to_string(i + 1) + ".\t\t\t" + results[i].first + "\n";
		if (i == 7)
			break;
	}

	playersResults.setString(playerNicknames);

	for (i = 0; i < results.size(); ++i)
	{
		playerPoints +=  results[i].second + "\n";
		if (i == 7)
			break;
	}
	playersResultsInt.setString(playerPoints);

}

int MenuScore::Run(sf::RenderWindow& App)
{
	calls();
	Textbox textbox1(50, sf::Color::Black, false);
	textbox1.setFont(cScreen::getFont());
	textbox1.setPosition({ 270, 177 });

	MenuExit MX;
	lastPath = MX.getLastPath();
	while (Running)
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			//cout << sf::Mouse::getPosition().x << "," << sf::Mouse::getPosition().y << endl;
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (rec1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec1.setOutlineThickness(4.0f);
					rec1.setOutlineColor(sf::Color::Blue);
					textbox1.setSelected(true);
				}
				if (exitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					return -1;
				}
				if (menuButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					return 0;
				}
				if (loadFromLastLocS.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					inputResults(lastPath);
					playersResults.setFillColor(sf::Color::Black);
					playersResultsInt.setFillColor(sf::Color::Black);
				}
				if (loadFromNewLocS.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					newPath = textbox1.getText();
					inputResults(newPath);
					playersResults.setFillColor(sf::Color::Black);
					playersResultsInt.setFillColor(sf::Color::Black);
					rec1.setOutlineThickness(2.0f);
					rec1.setOutlineColor(sf::Color::Black);
					textbox1.setSelected(false);
				}

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				rec1.setOutlineThickness(1.0f);
				rec1.setOutlineColor(sf::Color::Black);
				textbox1.setSelected(false);

			}
			if (event.type == sf::Event::TextEntered)
			{
				textbox1.typedOn(event);
			}

			sf::Vector2i mousePosition = sf::Mouse::getPosition(App);

			if (loadFromNewLocS.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				loadFromNewLocDesc.setFillColor(sf::Color::Black);
			}
			else
			{
				loadFromNewLocDesc.setFillColor(sf::Color::White);
			}

			if (loadFromLastLocS.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				loadFromLastLocDesc.setFillColor(sf::Color::Black);
			}
			else
			{
				loadFromLastLocDesc.setFillColor(sf::Color::White);
			}

			if (menuButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				menuButtonDesc.setFillColor(sf::Color::Black);
			}
			else
			{
				menuButtonDesc.setFillColor(sf::Color::White);
			}

			if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				exitButtonDesc.setFillColor(sf::Color::Black);
			}
			else
			{
				exitButtonDesc.setFillColor(sf::Color::White);
			}


		}
		App.clear();
		App.draw(background);
		App.draw(score);
		App.draw(loadFromLastLoc);
		App.draw(loadFromLastLocS);
		App.draw(loadFromNewLoc);
		App.draw(loadFromNewLocS);
		App.draw(recWhite);
		App.draw(recDarkGrey);
		App.draw(recDarkGreyDesc);
		App.draw(rec1);
		App.draw(rec1Grey);
		App.draw(rec2Grey);
		App.draw(rec3Grey);
		App.draw(rec4Grey);
		App.draw(menuButton);
		App.draw(exitButton);
		App.draw(menuButtonDesc);
		App.draw(exitButtonDesc);
		App.draw(playersResults);
		App.draw(playersResultsInt);
		textbox1.drawTo(App);
		App.draw(loadFromNewLocDesc);
		App.draw(loadFromLastLocDesc);
		App.display();
	}
}
