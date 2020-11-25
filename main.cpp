#include "LibraryHeader.h"
#include "Collision_System.h"

#define width 1000
#define height 700

int main()
{

    srand(time(nullptr));

/*    Float rad = 5, x_ = 28, y_ = 100, row = width/x_, column = height/y_;

    vector<Particle> temp;
    for(int j = 0; j < column; j++) {
        for (int i = 0; i < row; i++) {
            temp.push_back({i * x_, j * y_, double((rand()%10%3 + 1))*pow(-1,i), double((rand()%10%3 + 1))*pow(-1,i), rad,1});
        }
    }*/

    vector<Particle> temp = {{0,0,1,1,30,0.5},
                             {800,600,1,1,30,0.5},
                             {100,0,1,1,30,0.5},
                             {300,600,1,1,30,0.5},
                             {0,400,1,1,30,0.5},
                             {0,600,1,1,30,0.5},
                             {200,100,1,1,30,0.5},
                             {200,400,1,1,30,0.5},
                             {500,500,1,1,30,0.5},
                             {500,100,1,1,30,0.5}};

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