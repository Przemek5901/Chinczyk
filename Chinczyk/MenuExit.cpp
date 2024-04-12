#include "MenuExit.h"

MenuExit::MenuExit()
{

}

MenuExit::~MenuExit()
{
}

string MenuExit::getLastPath()
{
	ifstream input("lastPath.txt");
	std::stringstream ss;
	ss << input.rdbuf();
	input.close();
	string lastPath = ss.str();
	return lastPath;

}

string MenuExit::removeQuotes(const string& word) {
	string result;
	for (char c : word) {
		if (c != '"') {
			result += c;
		}
	}
	return result;
}

void MenuExit::setLastPath(std::filesystem::path& path)
{
	std::ofstream LP("lastPath.txt");
	std::ostringstream oss;
	oss << path.string();
	LP << removeQuotes(oss.str());
	LP.close();;

}

void MenuExit::calls()
{
	backgroundT.loadFromFile("images/mapasel.png");
	background.setTexture(backgroundT);

	endInfo.setFont(cScreen::getFont());
	endInfo.setFillColor(sf::Color::Black);
	endInfo.setCharacterSize(100);

	endInfo.setString("KONIEC GRY!");
	endInfo.setStyle(sf::Text::Bold);
	sf::FloatRect bounds = endInfo.getLocalBounds();
	bounds.width = bounds.width / 2;
	endInfo.setPosition(600 - bounds.width, 10);

	winnerInfo.setFont(cScreen::getFont());
	winnerInfo.setCharacterSize(60);
	winnerInfo.setString("ZWYCIEZCA: ");
	winnerInfo.setStyle(sf::Text::Bold);
	winnerInfo.setFillColor(sf::Color::Black);
	sf::FloatRect boundsWinnerInfo = winnerInfo.getLocalBounds();
	boundsWinnerInfo.width = boundsWinnerInfo.width / 2;
	winnerInfo.setPosition(267, 110);

	winnerInfoNick.setCharacterSize(60);
	winnerInfoNick.setString(winnerNickname(P, MG, winnerInfoNick));
	winnerInfoNick.setFont(cScreen::getFont());
	winnerInfoNick.setCharacterSize(60);
	winnerInfoNick.setStyle(sf::Text::Bold);
	winnerInfoNick.setOutlineThickness(2);
	winnerInfoNick.setOutlineColor(sf::Color::Black);
	sf::FloatRect boundsWinnerInfoNick = winnerInfoNick.getLocalBounds();
	boundsWinnerInfoNick.width = boundsWinnerInfoNick.width / 2;
	winnerInfoNick.setPosition(770 - boundsWinnerInfoNick.width, 110);

	saveInfo.setFont(cScreen::getFont());
	saveInfo.setFillColor(sf::Color::Black);
	saveInfo.setCharacterSize(50);
	saveInfo.setString("Podaj lokalizacje do zapisu wynikow \n " R"(   Przykladowa lokalizacja  D:\\)");
	saveInfo.setStyle(sf::Text::Bold);
	sf::FloatRect boundsSaveInfo = saveInfo.getLocalBounds();
	boundsSaveInfo.width = boundsSaveInfo.width / 2;
	saveInfo.setPosition(600 - boundsSaveInfo.width, 190);

	rec1.setSize(sf::Vector2f(800, 50));
	rec1.setFillColor(sf::Color::White);
	rec1.setPosition(200, 320);
	rec1.setOutlineColor(sf::Color::Black);
	rec1.setOutlineThickness(1.0f);

	buttonSavePath.setTexture(cScreen::getButton());
	buttonSavePath.setPosition(464, 390);

	lastSaveInfo.setFont(cScreen::getFont());
	lastSaveInfo.setFillColor(sf::Color::Black);
	lastSaveInfo.setCharacterSize(50);
	lastSaveInfo.setString("Zapisz wyniki do ostatniej lokalizacji");
	lastSaveInfo.setStyle(sf::Text::Bold);
	sf::FloatRect boundslastSaveInfo = lastSaveInfo.getLocalBounds();
	boundslastSaveInfo.width = boundslastSaveInfo.width / 2;
	lastSaveInfo.setPosition(600 - boundslastSaveInfo.width, 525);

	buttonLastPath.setTexture(cScreen::getButton());
	buttonLastPath.setPosition(464, 600);

	buttonExit.setTexture(cScreen::getButton());
	buttonExit.setPosition(650, 750);

	buttonMenu.setTexture(cScreen::getButton());
	buttonMenu.setPosition(279, 750);

	buttonSavePathInfo.setFont(cScreen::getFont());
	buttonSavePathInfo.setFillColor(sf::Color::White);
	buttonSavePathInfo.setCharacterSize(79);
	buttonSavePathInfo.setString("ZAPISZ");
	buttonSavePathInfo.setStyle(sf::Text::Bold);
	buttonSavePathInfo.setPosition(479, 388);

	buttonLastPathInfo.setFont(cScreen::getFont());
	buttonLastPathInfo.setFillColor(sf::Color::White);
	buttonLastPathInfo.setCharacterSize(79);
	buttonLastPathInfo.setString("ZAPISZ");
	buttonLastPathInfo.setStyle(sf::Text::Bold);
	buttonLastPathInfo.setPosition(479, 597);

	buttonExitInfo.setFont(cScreen::getFont());
	buttonExitInfo.setFillColor(sf::Color::White);
	buttonExitInfo.setCharacterSize(65);
	buttonExitInfo.setString("WYJSCIE");
	buttonExitInfo.setStyle(sf::Text::Bold);
	buttonExitInfo.setPosition(665, 754);

	buttonMenuInfo.setFont(cScreen::getFont());
	buttonMenuInfo.setFillColor(sf::Color::White);
	buttonMenuInfo.setCharacterSize(50);
	buttonMenuInfo.setLineSpacing(0.8);
	buttonMenuInfo.setString("   MENU \n GLOWNE");
	buttonMenuInfo.setStyle(sf::Text::Bold);
	buttonMenuInfo.setPosition(293, 741);

}

string MenuExit::winnerNickname(Players& P, MenuGame& MG, sf::Text& text)
{

	if (MG.winnerNumber == 0)
	{
		text.setFillColor(sf::Color::Red);
		return P.Player1.first;
	}
	if (MG.winnerNumber == 1)
	{
		text.setFillColor(sf::Color::Blue);
		return P.Player2.first;
	}
	if (MG.winnerNumber == 2)
	{
		text.setFillColor(sf::Color::Green);
		return P.Player3.first;
	}
	if (MG.winnerNumber == 3)
	{
		text.setFillColor(sf::Color::Yellow);
		return P.Player4.first;
	}

}

void MenuExit::saveToFile(std::filesystem::path& toSave)
{
	ifstream input(toSave / R"(wyniki.txt)");
	string nick;
	int points;
	vector<string> results;
	bool flag = true;

	while (input >> nick >> points)
	{
		if (nick == winnerNickname(P, MG, winnerInfoNick))
		{
			points++;
			flag = false;
		}
		string pointsS = to_string(points);
		results.push_back(nick + " " + pointsS);
	}
	input.close();

	if (flag)
	{
		results.push_back(winnerNickname(P, MG, winnerInfoNick) + " 1");
	}

	ofstream output(toSave / R"(wyniki.txt)");
	for (int i = 0; i < results.size(); i++)
	{
		output << results[i] << endl;
	}

	output.close();
}

int MenuExit::Run(sf::RenderWindow& App)
{
	calls();
	extern MenuGame MG;
	extern Players P;

	Textbox textbox1(50, sf::Color::Black, false);
	textbox1.setFont(cScreen::getFont());
	textbox1.setPosition({ 220, 313 });



	while (Running)
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//cout << sf::Mouse::getPosition().x << "," << sf::Mouse::getPosition().y << endl;
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (rec1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec1.setOutlineThickness(4.0f);
					rec1.setOutlineColor(sf::Color::Blue);
					textbox1.setSelected(true);
				}
				if (buttonExit.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					return (-1);
				}
				if (buttonMenu.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					return (0);
				}
				if (buttonSavePath.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec1.setOutlineThickness(1.0f);
					rec1.setOutlineColor(sf::Color::Black);
					toSave = textbox1.getText();
					saveToFile(toSave);
					setLastPath(toSave);

				}
				if (buttonLastPath.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					lastPath = getLastPath();
					saveToFile(lastPath);
					setLastPath(lastPath);
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
			if (buttonSavePath.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonSavePathInfo.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonSavePathInfo.setFillColor(sf::Color::White);
			}

			if (buttonLastPath.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonLastPathInfo.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonLastPathInfo.setFillColor(sf::Color::White);
			}

			if (buttonMenu.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonMenuInfo.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonMenuInfo.setFillColor(sf::Color::White);
			}

			if (buttonExit.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonExitInfo.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonExitInfo.setFillColor(sf::Color::White);
			}

		}
		App.clear();
		App.draw(background);
		App.draw(winnerInfo);
		App.draw(winnerInfoNick);
		App.draw(endInfo);
		App.draw(saveInfo);
		App.draw(lastSaveInfo);
		App.draw(rec1);
		App.draw(buttonSavePath);
		App.draw(buttonLastPath);
		App.draw(buttonExit);
		App.draw(buttonMenu);
		App.draw(buttonSavePathInfo);
		App.draw(buttonLastPathInfo);
		App.draw(buttonExitInfo);
		App.draw(buttonMenuInfo);
		textbox1.drawTo(App);
		App.display();
	}
	return -1;
}
