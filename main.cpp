#include "LibraryHeader.h"
#include "Collision_System.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle_Collision");
    Collision_System test(&window,
                          {{100,10,5,1,1},
                               {100,200,15,2,2},
                               {200,300,10,-1,-1},
                               {400,400,5,-2,-2}});

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