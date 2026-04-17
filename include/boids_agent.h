#ifndef BOIDS_AGENT_H
#define BOIDS_AGENT_H

#include <math.h>
#include <stdlib.h>

#include "boids_consts.h"
#include "boids_structs.h"

// Calls from the main loop or the agent thread:
void boid_init(Boid *b);
void boid_update(Boid *boids, int idx);

#endif // BOIDS_AGENT_H