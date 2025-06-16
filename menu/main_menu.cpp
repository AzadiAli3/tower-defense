#include "main_menu.hpp"
#include <iostream>

MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile("Fonts/arial.ttf")) {  // Fonts
        std::cout << "No font found!" << std::endl;
    }

    std::string menuItems[Max_main_menu] = { "Play", "About", "Options", "Exit" };

    for (int i = 0; i < Max_main_menu; ++i) {
        mainMenu[i].setFont(font);
        mainMenu[i].setString(menuItems[i]);
        mainMenu[i].setCharacterSize(50);
        mainMenu[i].setPosition(width / 2 - 100, height / 2 + i * 80);
        mainMenu[i].setFillColor(i == 0 ? sf::Color::Blue : sf::Color::White); // Highlight 
    }

    MainMenuSelected = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < Max_main_menu; ++i) {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp()
{
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected--;
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Yellow);
    }
}

void MainMenu::MoveDown()
{
    if (MainMenuSelected + 1 < Max_main_menu) {
        mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected++;
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Yellow);
    }
}
