#include "Collision_System.h"

Double calculate_distance(Double ax,Double ay,Double bx, Double by){
    return pow((ax-bx),2) + pow((ay-by), 2);
}

Collision_System::Collision_System() = default;

Collision_System::Collision_System(sf::RenderWindow* wnd, vector<Particle> &list):
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
    for(int i = 0; i < size(particles); i ++) {

        if (particles[i].rx + particles[i].vx >= 0 && particles[i].rx + particles[i].vx <= 1000)
            particles[i].rx += particles[i].vx;

        if (particles[i].ry + particles[i].vy >= 0 && particles[i].ry + particles[i].vy <= 700)
            particles[i].ry += particles[i].vy;

        if (particles[i].rx + particles[i].vx <= 0 || particles[i].rx + particles[i].vx >= 1000 - 2*particles[i].radius)
            particles[i].vx = -particles[i].vx;

        if (particles[i].ry + particles[i].vy <= 0 || particles[i].ry + particles[i].vy >= 700 - 2*particles[i].radius)
            particles[i].vy = -particles[i].vy;

        for(int j = 0; j < size(particles); j++)
            if (i != j) {
                if (calculate_distance(particles[i].rx, particles[i].ry, particles[j].rx, particles[j].ry) <=
                    pow((2 * particles[i].radius), 2)) {

                    particles[i].vx = -particles[i].vx;
                    particles[i].vy = -particles[i].vy;
                    particles[j].vx = -particles[j].vx;
                    particles[j].vy = -particles[j].vy;
                }
            }
    }
}