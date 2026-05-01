#ifndef BOIDS_AGENT_H
#define BOIDS_AGENT_H

#include "boids_structs.h"

// Calls from the main loop or the agent thread:
void boid_update(Boid *boid);

#endif // BOIDS_AGENT_H
