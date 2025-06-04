#include <SFML/Graphics.hpp>

int main()
{
    // Crée une fenêtre de 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test SFML");

    // Crée un cercle rouge
    sf::CircleShape cercle(50.f);
    cercle.setFillColor(sf::Color::Red);
    cercle.setPosition(375, 275); // centré

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Fermer la fenêtre si on clique sur la croix
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();             // Efface l'écran
        window.draw(cercle);        // Dessine le cercle
        window.display();           // Affiche le rendu
    }

    return 0;
}