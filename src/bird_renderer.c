#include "entity_renderer.h"
#include "boids_consts.h"
#include <SDL2/SDL.h>

void draw_entity(SDL_Renderer *ren, Boid *b){
    float angle = atan2f(b->vel.y, b->vel.x);

    /* Triangle: tip (front), left base, right base */
    float tip_len  = 10.0f;
    float base_half = 5.0f;

    SDL_FPoint tip = {
        b->pos.x + cosf(angle)          * tip_len,
        b->pos.y + sinf(angle)          * tip_len
    };
    SDL_FPoint left = {
        b->pos.x + cosf(angle + 2.4f)  * base_half,
        b->pos.y + sinf(angle + 2.4f)  * base_half
    };
    SDL_FPoint right = {
        b->pos.x + cosf(angle - 2.4f)  * base_half,
        b->pos.y + sinf(angle - 2.4f)  * base_half
    };

    /* Speed-based color: slow = teal, fast = warm orange */
    Uint8 r = (Uint8)(80  + b->speed * 175);
    Uint8 g = (Uint8)(200 - b->speed * 100);
    Uint8 bv= (Uint8)(220 - b->speed * 180);

    SDL_SetRenderDrawColor(ren, r, g, bv, 255);

    /* Triangle with three SDL_RenderDrawLineF calls       */
    /* (No SDL_RenderGeometry dependency needed for SDL 2.0.17-)     */
    SDL_RenderDrawLineF(ren, tip.x, tip.y, left.x,  left.y );
    SDL_RenderDrawLineF(ren, left.x, left.y, right.x, right.y);
    SDL_RenderDrawLineF(ren, right.x, right.y, tip.x,  tip.y );

    /* Filled: scan-line fill for the triangle */
    /* Simple approach: draw lines from tip to base edge */
    int steps = 8;
    for(int s = 0; s <= steps; s++){
        float t = (float)s / steps;
        SDL_FPoint lp = { left.x  + t*(right.x - left.x),
                          left.y  + t*(right.y - left.y) };
        SDL_RenderDrawLineF(ren, tip.x, tip.y, lp.x, lp.y);
    }
}

void update_entity(Boid *b){
    if(b->pos.x < 0)        b->pos.x += WINDOW_W;
    if(b->pos.x >= WINDOW_W) b->pos.x -= WINDOW_W;
    if(b->pos.y < 0)        b->pos.y += WINDOW_H;
    if(b->pos.y >= WINDOW_H) b->pos.y -= WINDOW_H;
}