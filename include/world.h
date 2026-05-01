#ifndef WORLD_H
#define WORLD_H

#include "boids_structs.h"

#define NUM_BOIDS     512
#define WINDOW_W      1024
#define WINDOW_H      1024
#define NUM_BOIDS     512

#define TARGET_FPS    60
#define FRAME_MS      (1000 / TARGET_FPS)

extern Boid world_boids[NUM_BOIDS];

#endif // WORLD_H
