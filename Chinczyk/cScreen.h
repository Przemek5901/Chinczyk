#include<SFML/Graphics.hpp>

using namespace std;
#pragma once
class cScreen
{
public:
    virtual int Run(sf::RenderWindow& App) = 0;
    static sf::Font& getFont()
    {
        static sf::Font Font;
        Font.loadFromFile("images/BRLNSR.ttf");
        return Font;
    }
    static sf::Texture& getButton()
    {
        static sf::Texture button;
        button.loadFromFile("images/button.png");
        return button;
    }
    static sf::Texture& getButtonS()
    {
        static sf::Texture button;
        button.loadFromFile("images/buttonsmall.png");
        return button;
    }
    ~cScreen() {};
};
