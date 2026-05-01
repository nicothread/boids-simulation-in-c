#ifndef BOIDS_AGENT_HELPERS_H
#define BOIDS_AGENT_HELPERS_H

#include <math.h>
#include <stdlib.h>

static inline Vec2 v2add(Vec2 a, Vec2 b){ return (Vec2){a.x+b.x, a.y+b.y}; }
static inline Vec2 v2sub(Vec2 a, Vec2 b){ return (Vec2){a.x-b.x, a.y-b.y}; }
static inline Vec2 v2scale(Vec2 v, float s){ return (Vec2){v.x*s, v.y*s}; }
static inline float v2dot(Vec2 a, Vec2 b){ return a.x*b.x + a.y*b.y; }
static inline float v2len(Vec2 v){ return sqrtf(v2dot(v,v)); }

static Vec2 v2norm(Vec2 v){
    float l = v2len(v);
    return l > 1e-6f ? v2scale(v, 1.0f/l) : (Vec2){0,0};
}

static Vec2 v2limit(Vec2 v, float max){
    float l = v2len(v);
    return l > max ? v2scale(v, max/l) : v;
}

// Steer toward a desired velocity (Reynolds steering formula)
static Vec2 steer_toward(Vec2 desired, Vec2 vel){
    Vec2 d = v2scale(v2norm(desired), MAX_SPEED);
    return v2limit(v2sub(d, vel), MAX_FORCE);
}

static float randf(float lo, float hi){
    return lo + (hi-lo)*((float)rand()/RAND_MAX);
}

// Call from the agent itself to perform local flocking behaviors
// static Vec2 separation(Boid *boid);
// static Vec2 alignment(Boid *boid);
// static Vec2 cohesion(Boid *boid);

#endif // BOIDS_AGENT_HELPERS_H