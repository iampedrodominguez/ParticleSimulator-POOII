#include "LibraryHeader.h"
#include "Collision_System.h"

#define width 1000
#define height 700

int main()
{

    srand(time(nullptr));

    Float rad = 5, x_ = 28, y_ = 100, row = width/x_, column = height/y_;

    vector<Particle> temp;
    for(int j = 0; j < column; j++) {
        for (int i = 0; i < row; i++) {
            temp.push_back({i * x_, j * y_, double((rand()%10%3 + 1)), double((rand()%10%3 + 1)), rad});
        }
    }

    sf::RenderWindow window(sf::VideoMode(width, height), "Particle_Collision");
    Collision_System test(&window,temp);

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