#include "MenuStart.h"

void MenuStart::calls()
{

	backgroundT.loadFromFile("images/mapastart.png");

	buttonPlay.setTexture(cScreen::getButton());
	buttonPlay.setPosition(464, 300);

	buttonScore.setTexture(cScreen::getButton());
	buttonScore.setPosition(464, 470);

	buttonExit.setTexture(cScreen::getButton());
	buttonExit.setPosition(464, 625);

	background.setTexture(backgroundT);

	buttonPlayDescrib.setFont(cScreen::getFont());
	buttonPlayDescrib.setCharacterSize(85);
	buttonPlayDescrib.setString("GRAJ");
	buttonPlayDescrib.setPosition(500, 290);
	buttonPlayDescrib.setStyle(sf::Text::Bold);


	buttonScoreDescrib.setFont(cScreen::getFont());
	buttonScoreDescrib.setCharacterSize(74);
	buttonScoreDescrib.setString("WYNIKI");
	buttonScoreDescrib.setPosition(477, 469);
	buttonScoreDescrib.setStyle(sf::Text::Bold);


	buttonExitDescrib.setFont(cScreen::getFont());
	buttonExitDescrib.setCharacterSize(65);
	buttonExitDescrib.setString("WYJSCIE");
	buttonExitDescrib.setPosition(479, 630);
	buttonExitDescrib.setStyle(sf::Text::Bold);


	Main.setFont(cScreen::getFont());
	Main.setCharacterSize(100);
	Main.setString("GRA CHINCZYK");
	Main.setStyle(sf::Text::Bold);
	sf::FloatRect boundsMain = Main.getLocalBounds();
	boundsMain.width = boundsMain.width / 2;
	Main.setPosition(600 - boundsMain.width, 50);
}

MenuStart::~MenuStart()
{
}

int MenuStart::Run(sf::RenderWindow& App)
{
	icon.loadFromFile("images/icon.png");
	App.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	calls();
	while (Running)
	{
		while (App.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					if (buttonPlay.getGlobalBounds().contains(sf::Vector2f(Event.mouseButton.x, Event.mouseButton.y)))
					{
						return (1);
					}
					if (buttonScore.getGlobalBounds().contains(sf::Vector2f(Event.mouseButton.x, Event.mouseButton.y)))
					{
						return (4);
					}
					if (buttonExit.getGlobalBounds().contains(sf::Vector2f(Event.mouseButton.x, Event.mouseButton.y)))
					{
						return (-1);
					}
				}
			}
			sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
			if (buttonPlay.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonPlayDescrib.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonPlayDescrib.setFillColor(sf::Color::White);
			}
			if (buttonScore.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonScoreDescrib.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonScoreDescrib.setFillColor(sf::Color::White);
			}
			if (buttonExit.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
			{
				buttonExitDescrib.setFillColor(sf::Color::Black);
			}
			else
			{
				buttonExitDescrib.setFillColor(sf::Color::White);
			}

		}
		App.clear();
		App.draw(background);
		App.draw(Main);
		App.draw(buttonPlay);
		App.draw(buttonPlayDescrib);
		App.draw(buttonScore);
		App.draw(buttonScoreDescrib);
		App.draw(buttonExit);
		App.draw(buttonExitDescrib);
		App.display();
	}

	return (-1);
}

