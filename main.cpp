#include "LibraryHeader.h"
#include "Collision_System.h"

#define width 800
#define height 600

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Particle_Collision");
    Collision_System test(&window,
                          {{10,10,0.1,0.4,20},
                           {100,110,0.1,0.4,10},
                           {600,210,0.1,0.4,30},
                           {400,190,0.1,0.4,15}});

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        test.draw();
        test.move();
        window.display();
    }
    return 0;
}