#include "Collision_System.h"

Collision_System::Collision_System(sf::RenderWindow* wnd, int num): window(wnd){

    Particles particles(num);
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        particles.draw(window);
        particles.move();
        window->display();
    }
}