#ifndef PARTICLE_COLLISIONER_PARTICLES_H
#define PARTICLE_COLLISIONER_PARTICLES_H

#include "Particle.h"

class Particles{
    int nParticles;
    vector<Particle> particles;

public:
    //Constructor and particles' generator
    Particles(int number);
    void random_generator();
    void one_particle();
    void ten_particles();

    //Particles' drawing on screen
    void draw(sf::RenderWindow* window);

    //Particles' movement N²
    void move();

    //Particles' movement NlogN
    void move_optimal();
};


#endif