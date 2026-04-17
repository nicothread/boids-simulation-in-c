#include "sdl_renderer.h"

int main(void) {
    struct SDL_Params sdl_params = {0};

    if (sdl_init(&sdl_params) > 0) return 1;

    sdl_main_loop(&sdl_params);
    return 0;
}
