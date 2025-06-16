#include <SFML/Graphics.hpp>
#include "main_menu.hpp"
#include <iostream>

using namespace sf;

int main()
{
    RenderWindow menuWindow(VideoMode(960, 720), "Tower Defense", Style::Default);
    MainMenu mainMenu(menuWindow.getSize().x, menuWindow.getSize().y);

    // Menu Background
    RectangleShape background(Vector2f(960, 720));
    Texture mainTexture;
    if (!mainTexture.loadFromFile("Texture/Main_background.jpg")) {
        std::cerr << "Error while loading Main_background.jpg" << std::endl;
    }
    background.setTexture(&mainTexture);

    // Play Background
    RectangleShape playBackground(Vector2f(960, 720));
    Texture playTexture;
    if (!playTexture.loadFromFile("Texture/Play_background.jpg")) {
        std::cerr << "Error while loading Play_background.jpg" << std::endl;
    }
    playBackground.setTexture(&playTexture);

    // Options Background
    RectangleShape optionBackground(Vector2f(960, 720));
    Texture optionTexture;
    if (!optionTexture.loadFromFile("Texture/Main_background.jpg")) {
        std::cerr << "Error while loading Main_background.jpg for options" << std::endl;
    }
    optionBackground.setTexture(&optionTexture);

    // About Background
    RectangleShape aboutBackground(Vector2f(960, 720));
    Texture aboutTexture;
    if (!aboutTexture.loadFromFile("Texture/Main_background.jpg")) {
        std::cerr << "Error while loading Main_background.jpg for about" << std::endl;
    }
    aboutBackground.setTexture(&aboutTexture);

    // Main loop
    while (menuWindow.isOpen())
    {
        Event event;
        while (menuWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                menuWindow.close();

            else if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                    mainMenu.MoveUp();
                else if (event.key.code == Keyboard::Down)
                    mainMenu.MoveDown();
                else if (event.key.code == Keyboard::Return)
                {
                    int selection = mainMenu.MainMenuPressed();

                    if (selection == 0) // Play
                    {
                        RenderWindow playWindow(VideoMode(960, 720), "Tower Defense");
                        while (playWindow.isOpen())
                        {
                            Event e;
                            while (playWindow.pollEvent(e))
                            {
                                if (e.type == Event::Closed || 
                                    (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape))
                                    playWindow.close();
                            }
                            playWindow.clear();
                            playWindow.draw(playBackground);
                            playWindow.display();
                        }
                    }

                    else if (selection == 1) // Options
                    {
                        RenderWindow optionsWindow(VideoMode(960, 720), "Tower Defense");
                        while (optionsWindow.isOpen())
                        {
                            Event e;
                            while (optionsWindow.pollEvent(e))
                            {
                                if (e.type == Event::Closed || 
                                    (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape))
                                    optionsWindow.close();
                            }
                            optionsWindow.clear();
                            optionsWindow.draw(optionBackground);
                            optionsWindow.display();
                        }
                    }

                    else if (selection == 2) // About
                    {
                        RenderWindow aboutWindow(VideoMode(960, 720), "About");
                        while (aboutWindow.isOpen())
                        {
                            Event e;
                            while (aboutWindow.pollEvent(e))
                            {
                                if (e.type == Event::Closed || 
                                    (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape))
                                    aboutWindow.close();
                            }
                            aboutWindow.clear();
                            aboutWindow.draw(aboutBackground);
                            aboutWindow.display();
                        }
                    }

                    else if (selection == 3) // Exit
                    {
                        menuWindow.close();
                    }
                }
            }
        }

        menuWindow.clear();
        menuWindow.draw(background);
        mainMenu.draw(menuWindow);
        menuWindow.display();
    }

    return 0;
}
