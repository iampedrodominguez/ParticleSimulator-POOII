#include "Collision_System.h"

Double calculate_distance(Particle &a, Particle &b){
    return sqrt(pow((a.rx-b.rx),2) + pow((a.ry-b.ry), 2));
}

Double impulse_fx(Particle &a, Particle &b){

    Double dx = b.rx - a.rx;
    Double dy = b.ry - a.ry;
    Double dvx = b.vx - a.vx;
    Double dvy = b.vy - a.vy;
    Double dv_dr = dx*dvx + dy*dvy;
    Double distance = (calculate_distance(a, b));

    Double magnitude = 2 * a.mass * b.mass * dv_dr / (distance * (a.mass + b.mass));

    return magnitude * dx / distance;
}

Double impulse_fy(Particle &a, Particle &b){
    Double dx = b.rx - a.rx;
    Double dy = b.ry - a.ry;
    Double dvx = b.vx - a.vx;
    Double dvy = b.vy - a.vy;
    Double dv_dr = dx*dvx + dy*dvy;
    Double distance = (calculate_distance(a, b));

    Double magnitude = 2 * a.mass * b.mass * dv_dr / (distance * (a.mass + b.mass));

    return magnitude * dy / distance;
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
        for(int j = 0; j < size(particles); j++) {
            if (i != j) {
                if (ceil((calculate_distance(particles[i], particles[j]))) <= 2 * particles[i].radius) {
                    if (particles[i].last_collision != j) {
                        Double fx = impulse_fx(particles[i], particles[j]);
                        Double fy = impulse_fy(particles[i], particles[j]);
                        particles[i].vx += fx / particles[i].mass;
                        particles[i].vy += fy / particles[i].mass;
                        particles[j].vx -= fx / particles[j].mass;
                        particles[j].vy -= fy / particles[j].mass;

                        particles[i].last_collision = j;
                    }
                }
            }
        }

        if (particles[i].rx + particles[i].vx <= 0 || particles[i].rx + particles[i].vx >= 1000 - 2*particles[i].radius)
            particles[i].vx = -particles[i].vx;

        if (particles[i].ry + particles[i].vy <= 0 || particles[i].ry + particles[i].vy >= 700 - 2*particles[i].radius)
            particles[i].vy = -particles[i].vy;

        particles[i].rx += particles[i].vx;
        particles[i].ry += particles[i].vy;
    }
}