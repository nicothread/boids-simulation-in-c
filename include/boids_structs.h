#ifndef BOIDS_STRUCTS_H
#define BOIDS_STRUCTS_H

/* ── Types ──────────────────────────────────────────────────────────── */
typedef struct {
    float x, y;
} Vec2;

typedef struct {
    Vec2  pos;
    Vec2  vel;
    Vec2  acc;
    float speed; // for re-presentation purpose
} Boid;

#endif // BOIDS_STRUCTS_H