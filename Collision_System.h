#ifndef PARTICLE_COLLISIONER_COLLISION_SYSTEM_H
#define PARTICLE_COLLISIONER_COLLISION_SYSTEM_H

#include "Particle.h"

class Collision_System {

    sf::RenderWindow* window{};
    vector<Particle> particles;

public:

    Collision_System() = default;
    Collision_System(sf::RenderWindow* wnd, initializer_list<Particle> list): window{wnd}, particles{list}{}

    void draw() {
        for (auto &p : particles) {
            sf::CircleShape shape(p.radius);
            shape.setFillColor(sf::Color::Red);
            shape.setPosition(p.rx, p.ry);
            window->draw(shape);
        }
    }

    void move(){
        for(auto &p : particles) {
            if (p.rx + p.vx >= 0 && p.rx + p.vx <= 790)
                p.rx += p.vx;
            if (p.ry + p.vy >= 0 && p.ry + p.vy <= 590)
                p.ry += p.vy;
            if (p.rx == 790 || p.rx == 0)
                p.vx *= -1;
            if (p.ry == 590 || p.ry == 0)
                p.vy *= -1;
        }
    }
};

#endif