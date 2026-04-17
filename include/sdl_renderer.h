#ifndef BOIDS_SDL_RENDERER_H
#define BOIDS_SDL_RENDERER_H

#include <SDL2/SDL.h>

struct SDL_Params {
    SDL_Renderer *ren;
    SDL_Window *win;
};

int sdl_init(struct SDL_Params *sdlParams);
void sdl_main_loop(const struct SDL_Params *sdlParams);

#endif // BOIDS_SDL_RENDERER_H