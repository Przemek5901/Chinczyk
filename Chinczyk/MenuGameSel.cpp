#include "MenuGameSel.h"

void MenuGameSel::callsScore()
{
	playersChosing.loadFromFile("images/mapasel.png");
	SplayersChosing.setTexture(playersChosing);

	text.setFont(cScreen::getFont());
	text.setCharacterSize(60);
	text.setString("PODAJ NAZWE GRACZA \n ORAZ WYBIERZ KOLOR");
	text.setPosition(270, 10);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);

	rec1.setSize(sf::Vector2f(400, 50));
	rec2.setSize(sf::Vector2f(400, 50));
	rec3.setSize(sf::Vector2f(400, 50));
	rec4.setSize(sf::Vector2f(400, 50));

	rec1.setFillColor(sf::Color::White);
	rec2.setFillColor(sf::Color::White);
	rec3.setFillColor(sf::Color::White);
	rec4.setFillColor(sf::Color::White);

	rec1.setPosition(500, 230);
	rec2.setPosition(500, 330);
	rec3.setPosition(500, 430);
	rec4.setPosition(500, 530);

	rec1.setOutlineColor(sf::Color::Black);
	rec2.setOutlineColor(sf::Color::Black);
	rec3.setOutlineColor(sf::Color::Black);
	rec4.setOutlineColor(sf::Color::Black);

	rec1.setOutlineThickness(1.0f);
	rec2.setOutlineThickness(1.0f);
	rec3.setOutlineThickness(1.0f);
	rec4.setOutlineThickness(1.0f);

	error.setFillColor(sf::Color::Transparent);
	error.setFont(cScreen::getFont());
	error.setString("NIEPOPRAWNA NAZWA UZYTKOWNIKA!");
	error.setCharacterSize(40);
	error.setPosition(243, 705);

	buttonPlay.setTexture(cScreen::getButton());
	buttonPlay.setPosition(470, 755);

	checkedT.loadFromFile("images/checked.png");
	checkedTBlack.loadFromFile("images/checkedBlack.png");

	checkedRed.setTexture(checkedT);
	checkedRed.setPosition(930, 230);

	checkedBlue.setTexture(checkedT);
	checkedBlue.setPosition(930, 330);

	checkedGreen.setTexture(checkedT);
	checkedGreen.setPosition(930, 430);

	checkedYellow.setTexture(checkedT);
	checkedYellow.setPosition(930, 530);

	redPlayer.setFont(cScreen::getFont());
	redPlayer.setFillColor(sf::Color::Red);
	redPlayer.setCharacterSize(50);
	redPlayer.setPosition(215, 220);
	redPlayer.setString("GRACZ NR 1:");

	bluePlayer.setFont(cScreen::getFont());
	bluePlayer.setFillColor(sf::Color::Blue);
	bluePlayer.setCharacterSize(50);
	bluePlayer.setPosition(215, 320);
	bluePlayer.setString("GRACZ NR 2:");

	greenPlayer.setFont(cScreen::getFont());
	greenPlayer.setFillColor(sf::Color::Green);
	greenPlayer.setCharacterSize(50);
	greenPlayer.setPosition(215, 420);
	greenPlayer.setString("GRACZ NR 3:");

	yellowPlayer.setFont(cScreen::getFont());
	yellowPlayer.setFillColor(sf::Color::Yellow);
	yellowPlayer.setCharacterSize(50);
	yellowPlayer.setPosition(215, 520);
	yellowPlayer.setString("GRACZ NR 4:");

	Play.setFont(cScreen::getFont());
	Play.setFillColor(sf::Color::White);
	Play.setCharacterSize(90);
	Play.setPosition(500, 745);
	Play.setString("GRAJ");

	Info.setFont(cScreen::getFont());
	Info.setFillColor(sf::Color::Black);
	Info.setCharacterSize(30);
	Info.setPosition(200, 645);
	Info.setString("      PRAWIDLOWA NAZYWA UZYTKOWNIKA POWINNA \n ZACZYNAC SIE OD DUZEJ LITERY ORAZ POSIADAC CYFRE!");

}

MenuGameSel::~MenuGameSel()
{
}

MenuGameSel::MenuGameSel(void)
{
}

int MenuGameSel::Run(sf::RenderWindow& App)
{
	Textbox textbox1(50, sf::Color::Black, false);
	Textbox textbox2(50, sf::Color::Black, false);
	Textbox textbox3(50, sf::Color::Black, false);
	Textbox textbox4(50, sf::Color::Black, false);

	textbox1.setFont(cScreen::getFont());
	textbox2.setFont(cScreen::getFont());
	textbox3.setFont(cScreen::getFont());
	textbox4.setFont(cScreen::getFont());

	textbox1.setPosition({ 530, 220 });
	textbox2.setPosition({ 530, 320 });
	textbox3.setPosition({ 530, 420 });
	textbox4.setPosition({ 530, 520 });

	callsScore();
	extern Players P;

	bool Running = true;

	while (Running)
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (rec1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec1.setOutlineThickness(4.0f);
					rec1.setOutlineColor(sf::Color::Blue);
					textbox1.setSelected(true);
				}
				if (rec2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec2.setOutlineThickness(4.0f);
					rec2.setOutlineColor(sf::Color::Blue);
					textbox1.setSelected(false);
					textbox2.setSelected(true);
				}
				if (rec3.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec3.setOutlineThickness(4.0f);
					rec3.setOutlineColor(sf::Color::Blue);
					textbox1.setSelected(false);
					textbox3.setSelected(true);
				}
				if (rec4.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					rec4.setOutlineThickness(4.0f);
					rec4.setOutlineColor(sf::Color::Blue);
					textbox1.setSelected(false);
					textbox4.setSelected(true);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				rec1.setOutlineThickness(1.0f);
				rec1.setOutlineColor(sf::Color::Black);
				rec2.setOutlineThickness(1.0f);
				rec2.setOutlineColor(sf::Color::Black);
				rec3.setOutlineThickness(1.0f);
				rec3.setOutlineColor(sf::Color::Black);
				rec4.setOutlineThickness(1.0f);
				rec4.setOutlineColor(sf::Color::Black);
				textbox1.setSelected(false);
				textbox2.setSelected(false);
				textbox3.setSelected(false);
				textbox4.setSelected(false);
			}

			if (event.type == sf::Event::TextEntered)
			{
				textbox1.typedOn(event);
				textbox2.typedOn(event);
				textbox3.typedOn(event);
				textbox4.typedOn(event);
			}
			if (checkedRed.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{

				if (regex_match(textbox1.getText(), rgx))
				{
					rec1.setOutlineThickness(1.0f);
					rec1.setOutlineColor(sf::Color::Black);
					P.Player1.first = textbox1.getText();
					P.Player1.second = "red";
					textbox1.setSelected(false);
					error.setFillColor(sf::Color::Transparent);
				}
				else
				{
					error.setFillColor(sf::Color::Red);
				}
			}
			if (checkedBlue.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if (regex_match(textbox2.getText(), rgx))
				{
					rec2.setOutlineThickness(1.0f);
					rec2.setOutlineColor(sf::Color::Black);
					P.Player2.first = textbox2.getText();
					P.Player2.second = "blue";
					textbox2.setSelected(false);
					error.setFillColor(sf::Color::Transparent);
				}
				else
				{
					error.setFillColor(sf::Color::Red);
				}
			}
			if (checkedGreen.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if (regex_match(textbox3.getText(), rgx))
				{
					rec3.setOutlineThickness(1.0f);
					rec3.setOutlineColor(sf::Color::Black);
					P.Player3.first = textbox3.getText();
					P.Player3.second = "green";
					textbox3.setSelected(false);
					error.setFillColor(sf::Color::Transparent);
				}
				else
				{
					error.setFillColor(sf::Color::Red);
				}
			}
			if (checkedYellow.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if (regex_match(textbox4.getText(), rgx))
				{
					rec4.setOutlineThickness(1.0f);
					rec4.setOutlineColor(sf::Color::Black);
					P.Player4.first = textbox4.getText();
					P.Player4.second = "yellow";
					textbox4.setSelected(false);
					error.setFillColor(sf::Color::Transparent);
				}
				else
				{
					error.setFillColor(sf::Color::Red);
				}
			}
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttonPlay.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					return 2;
				}
			}
			sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
			if (buttonPlay.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				Play.setFillColor(sf::Color::Black);
			}
			else
			{
				Play.setFillColor(sf::Color::White);
			}
			if (checkedRed.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				checkedRed.setTexture(checkedTBlack);
			}
			else
			{
				checkedRed.setTexture(checkedT);
			}

			if (checkedBlue.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				checkedBlue.setTexture(checkedTBlack);
			}
			else
			{
				checkedBlue.setTexture(checkedT);
			}

			if (checkedGreen.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				checkedGreen.setTexture(checkedTBlack);
			}
			else
			{
				checkedGreen.setTexture(checkedT);
			}

			if (checkedYellow.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				checkedYellow.setTexture(checkedTBlack);
			}
			else
			{
				checkedYellow.setTexture(checkedT);
			}


		}

		App.clear();
		App.draw(SplayersChosing);
		App.draw(text);
		App.draw(rec1);
		App.draw(rec2);
		App.draw(rec3);
		App.draw(rec4);
		App.draw(checkedRed);
		App.draw(checkedBlue);
		App.draw(checkedGreen);
		App.draw(checkedYellow);
		App.draw(redPlayer);
		App.draw(bluePlayer);
		App.draw(greenPlayer);
		App.draw(yellowPlayer);
		App.draw(error);
		App.draw(Info);
		App.draw(buttonPlay);
		App.draw(Play);
		textbox1.drawTo(App);
		textbox2.drawTo(App);
		textbox3.drawTo(App);
		textbox4.drawTo(App);
		App.display();
	}

	return -1;
}