#ifndef PARTICLE_COLLISIONER_COLLISION_SYSTEM_H
#define PARTICLE_COLLISIONER_COLLISION_SYSTEM_H

#include "Particle.h"

class Collision_System {

    sf::RenderWindow* window{};
    Double t = 0;
    vector<Particle> particles;

public:

    Collision_System();
    Collision_System(sf::RenderWindow* wnd, initializer_list<Particle> list);

    void draw();
    void move();
};

#endif