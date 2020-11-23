#include "Collision_System.h"

Collision_System::Collision_System() = default;

Collision_System::Collision_System(sf::RenderWindow* wnd, initializer_list<Particle> list):
                                    window{wnd}, particles{list}{}

void Collision_System::draw() {
    for (auto &p : particles) {
        sf::CircleShape shape(p.radius);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(p.rx, p.ry);
        window->draw(shape);
    }
}

void Collision_System:: move(){
    for(auto &p : particles) {
        if (p.rx + p.vx >= 0 && p.rx + p.vx <= 800)
            p.rx += p.vx;
        if (p.ry + p.vy >= 0 && p.ry + p.vy <= 600)
            p.ry += p.vy;
        if (p.rx + p.vx <= 0 || p.rx + p.vx >= 800 - 2*p.radius)
            p.vx = -p.vx;
        if (p.ry + p.vy <= 0 || p.ry + p.vy >= 600 - 2*p.radius)
            p.vy = -p.vy;
    }
}