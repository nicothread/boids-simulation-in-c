#include "world.h"
#include "sdl_renderer.h"
#include "boids_consts.h"
#include "boids_agent_helper.h"

Boid world_boids[NUM_BOIDS] = {0};

static void boid_init(Boid *b){
  b->pos = (Vec2){ randf(0, WINDOW_W), randf(0, WINDOW_H) };
  float angle = randf(0, 2.0f * (float)M_PI);
  float speed = randf(1.5f, MAX_SPEED); // For simulation purpose
  b->vel = (Vec2){ cosf(angle)*speed, sinf(angle)*speed };
  b->acc = (Vec2){0,0};
}

int main(void) {
    struct SDL_Params sdl_params = {0};

    for(int i = 0; i < NUM_BOIDS; i++) {
        boid_init(&world_boids[i]);
    }

    if (sdl_init(&sdl_params) > 0) return 1;

    sdl_main_loop(&sdl_params);
    return 0;
}

