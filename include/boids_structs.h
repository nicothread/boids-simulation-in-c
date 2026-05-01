#ifndef BOIDS_STRUCTS_H
#define BOIDS_STRUCTS_H
#include "boids_consts.h"

typedef struct {
    float x, y;
} Vec2;

typedef struct Boid {
    Vec2 pos;
    Vec2 vel;
    Vec2 acc;
    struct Boid **detectedBoids;
    int num_detectedBoids;
} Boid;

#endif // BOIDS_STRUCTS_H