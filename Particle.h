#ifndef PARTICLE_COLLISIONER_PARTICLE_H
#define PARTICLE_COLLISIONER_PARTICLE_H

#include "LibraryHeader.h"

struct Particle {
    Float rx, ry;
    Float vx, vy;
    Float radius;
    Float mass;
    int last_collision;
};

#endif