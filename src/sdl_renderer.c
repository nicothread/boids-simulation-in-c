#include "sdl_renderer.h"
#include "world.h"
#include "boids_structs.h"
#include "boids_agent.h"
#include "entity_renderer.h"

#include <time.h>
#include <SDL2/SDL.h>

int sdl_init(struct SDL_Params *sdlParams) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((unsigned int)(ts.tv_sec ^ ts.tv_nsec));

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow(
        "Boids — Simple Simulation SDL-C",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_W, WINDOW_H, 0);
    if(!win){ fprintf(stderr, "SDL_CreateWindow: %s\n", SDL_GetError()); return 1; }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!ren){ fprintf(stderr, "SDL_CreateRenderer: %s\n", SDL_GetError()); return 1; }

    sdlParams->ren = ren;
    sdlParams->win = win;

    return 0;
}

void sdl_main_loop(const struct SDL_Params *sdlParams) {

    // --> At this point boids are initialized and ready for simulation

    SDL_bool running = SDL_TRUE;
    Uint32 t0 = SDL_GetTicks();

    while(running){
        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_QUIT) running = SDL_FALSE;
            if(ev.type == SDL_KEYDOWN &&
               (ev.key.keysym.sym == SDLK_ESCAPE ||
                ev.key.keysym.sym == SDLK_q))
                running = SDL_FALSE;
        }

        /* Update all boids */
        for(int i = 0; i < NUM_BOIDS; i++) {
            boid_update(&world_boids[i]);
            update_entity(&world_boids[i]);
        }

        /* Render */
        SDL_SetRenderDrawColor(sdlParams->ren, 10, 12, 20, 255);   /* dark-navy bg */
        SDL_RenderClear(sdlParams->ren);

        for(int i = 0; i < NUM_BOIDS; i++) draw_entity(sdlParams->ren, &world_boids[i]);

        SDL_RenderPresent(sdlParams->ren);

        /* Cap frame rate */
        Uint32 elapsed = SDL_GetTicks() - t0;
        if(elapsed < FRAME_MS) SDL_Delay(FRAME_MS - elapsed);
        t0 = SDL_GetTicks();
    }

    SDL_DestroyRenderer(sdlParams->ren);
    SDL_DestroyWindow(sdlParams->win);
    SDL_Quit();
}