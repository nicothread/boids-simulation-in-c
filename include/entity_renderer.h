#ifndef BOIDS_ENTITY_RENDERER_H
#define BOIDS_ENTITY_RENDERER_H

#include <SDL2/SDL.h>
#include "boids_structs.h"

void draw_entity(SDL_Renderer *ren, Boid *b);
void update_entity(Boid *b);

#endif // BOIDS_ENTITY_RENDERER_H