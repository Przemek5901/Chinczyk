#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"cScreen.h"
#include"MenuStart.h"
#include"MenuGameSel.h"
#include"MenuGame.h"
#include "MenuExit.h"
#include "MenuScore.h"


int main()
{
    std::vector<cScreen*> Screens;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Music music;
    music.openFromFile("music.wav");
    music.play();
    music.setLoop(true);
    music.setVolume(20.f);
    sf::RenderWindow App(sf::VideoMode(1200, 900, 32), "Gra Chinczyk - Przemyslaw Bednarz", sf::Style::Default, settings);
    int screen = 0;
    MenuStart m0;
    Screens.push_back(&m0);
    MenuGameSel m1;
    Screens.push_back(&m1);
    MenuGame m2;
    Screens.push_back(&m2);
    MenuExit m3;
    Screens.push_back(&m3);
    MenuScore m4;
    Screens.push_back(&m4);
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(App);
    }
    return 0;
}